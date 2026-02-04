#pragma once
#ifndef VC_EXTRALEAN
#   define VC_EXTRALEAN
#endif
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS

#include <afxwin.h>
#include <afxext.h>
#include <afxdtctl.h>
#include <afxcmn.h>
#include <afxsock.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <locale>
#include <vector>
#include <climits>

#include "mil.h"

namespace fs = std::filesystem;

static fs::path gIniPath = L".\\mim_converter_config.ini";

static int IniGetInt(const std::wstring& sec, LPCWSTR key, int defVal = 0)
{
    return ::GetPrivateProfileIntW(sec.c_str(), key, defVal, gIniPath.c_str());
}

static std::wstring IniGetStr(const std::wstring& sec, LPCWSTR key,
    LPCWSTR defVal = L"")
{
    wchar_t buf[512]{};
    ::GetPrivateProfileStringW(sec.c_str(), key, defVal,
        buf, 512, gIniPath.c_str());
    return buf;
}

/* ---------------- Job 구조체 ----------------------------- */
struct Job
{
    int         idx = 0;
    int         bayerOrder = 1;   // 0~3
    bool        toBmp = true;
    bool        toJpg = true;
    int         channelCnt = 1;   // 1 or 3
    int         bayerInterp = 0;  // 0:ColorCorr, 1:Adaptive, 2:Avg, 3:Bilinear

    // [신규 기능] Gray 변환 옵션
    bool        toGray = false;   // 0: Color유지, 1: Gray변환
    int         grayType = 0;     // 0: Standard(MimConvert), 1: Average(ImageJ)

    fs::path    src, dst;
};

/* ---------------- INI → Job 벡터 ------------------------- */
static std::vector<Job> LoadJobsFromIni()
{
    std::vector<Job> jobs;

    int cnt = IniGetInt(L"MIM2BMP Information", L"type count", 0);
    if (cnt <= 0) {
        std::wcerr << L"[ERROR] type count 가 0 또는 정의되지 않았습니다.\n";
        return jobs;
    }

    const fs::path iniDir = fs::absolute(gIniPath).parent_path();

    for (int i = 1; i <= cnt; ++i)
    {
        wchar_t secInfo[16]; swprintf(secInfo, 16, L"info%d", i);
        wchar_t secPath[16]; swprintf(secPath, 16, L"PATH%d", i);

        /* 섹션 존재 확인 ------------------------------------------------ */
        bool hasInfo = (IniGetInt(secInfo, L"BAYER_ORDER", INT_MIN) != INT_MIN);

        wchar_t dummy[256];
        bool hasPath = (::GetPrivateProfileStringW(secPath, nullptr, L"",
            dummy, 256, gIniPath.c_str()) > 0);

        if (!hasInfo || !hasPath)
        {
            std::wcerr << L"[ERROR] type count=" << cnt
                << L" 이지만 " << (hasInfo ? L"" : secInfo)
                << (!hasInfo && !hasPath ? L"/" : L"")
                << (hasPath ? L"" : secPath)
                << L" 섹션이 없습니다. 해당 Job 건너뜜.\n";
            continue;
        }

        /* 값 읽기 ------------------------------------------------------ */
        Job j;
        j.idx = i;
        j.bayerOrder = IniGetInt(secInfo, L"BAYER_ORDER", 1);
        j.toBmp = IniGetInt(secInfo, L"CONVERT_BMP", 1);
        j.toJpg = IniGetInt(secInfo, L"CONVERT_JPG", 1);
        j.channelCnt = IniGetInt(secInfo, L"CHANNEL_CNT", 1);
        j.bayerInterp = IniGetInt(secInfo, L"BayerInterpolation", 0);

        // [신규 기능] 옵션 로드 (이름 변경 반영)
        j.toGray = IniGetInt(secInfo, L"CONVERT_TO_GRAY", 0);
        j.grayType = IniGetInt(secInfo, L"GRAY_CONVERSION_TYPE", 0);

        j.src = IniGetStr(secPath, L"Source mim path", L"");
        j.dst = IniGetStr(secPath, L"Target img path", L"");
        if (j.src.empty()) j.src = iniDir;
        if (j.dst.empty()) j.dst = j.src;

        j.src = fs::absolute(j.src);
        j.dst = fs::absolute(j.dst);
        jobs.push_back(std::move(j));
    }
    return jobs;
}

/* ---------------- Bayer enum 변환 ------------------------ */
static MIL_INT64 ToMilBayer(int order)
{
    switch (order)
    {
    case 1: return M_BAYER_BG;
    case 2: return M_BAYER_GB;
    case 3: return M_BAYER_GR;
    case 4: return M_BAYER_RG;
    default: return M_BAYER_RG;
    }
}

/* ---------------- Job 실행 ------------------------------- */
static void RunOneJob(const Job& jb, MIL_ID milSys, MIL_ID hCoef)
{
    std::wcout << L"\n===== [JOB " << jb.idx << L"] =========================\n"
        << L" SRC : " << jb.src.c_str() << L"\n"
        << L" DST : " << jb.dst.c_str() << L"\n";

    // 로그 출력 부분도 직관적으로 변경
    if (jb.toGray) {
        std::wcout << L" GRAY MODE : " << (jb.grayType == 0 ? L"Standard(Luminance)" : L"Average(ImageJ)") << L"\n";
    }

    /* src 검사 -------------------------------------------------------- */
    if (!fs::exists(jb.src) || !fs::is_directory(jb.src))
    {
        std::wcerr << L"[ERROR] Source 경로가 존재하지 않거나 폴더가 아닙니다:\n  "
            << jb.src.c_str() << L"\n";
        return;
    }

    /* dst 폴더가 없으면 생성 ----------------------------------------- */
    if (!fs::exists(jb.dst))
    {
        std::error_code ec;
        fs::create_directories(jb.dst, ec);
        if (ec)
        {
            std::wcerr << L"[ERROR] Target 폴더 생성 실패 (" << ec.message().c_str()
                << L"):\n  " << jb.dst.c_str() << L"\n";
            return;
        }
        std::wcout << L"[INFO] Target 폴더 생성: " << jb.dst.c_str() << L"\n";
    }

    if (!(jb.toBmp || jb.toJpg))
    {
        std::wcout << L"  >> BMP/JPG 모두 비활성 – SKIP\n";
        return;
    }

    MIL_ID hRaw = M_NULL, hClr = M_NULL;
    MIL_ID hGrayProc = M_NULL; // 결과 저장용 Gray 버퍼
    MIL_ID hFloatSum = M_NULL; // 연산용 Float 버퍼

    int curW = -1, curH = -1, curBand = -1;

    try
    {
        for (const auto& e :
            fs::recursive_directory_iterator(jb.src,
                fs::directory_options::skip_permission_denied))
        {
            if (!e.is_regular_file() || e.path().extension() != L".mim") continue;

            fs::path mim = e.path();
            fs::path rel;
            try { rel = fs::relative(mim.parent_path(), jb.src); }
            catch (const fs::filesystem_error& ex) {
                std::wcerr << L"[WARN] 상대경로 계산 실패: " << ex.what() << L"\n";
                continue;
            }

            fs::path outDir = jb.dst / rel;
            std::error_code ec;
            fs::create_directories(outDir, ec);
            if (ec) {
                std::wcerr << L"[WARN] 폴더 생성 실패 (" << ec.message().c_str()
                    << L") → " << outDir.c_str() << L"\n";
                continue;
            }

            fs::path bmp = outDir / mim.stem(); bmp += L".bmp";
            fs::path jpg = outDir / mim.stem(); jpg += L".jpg";

            bool needBmp = jb.toBmp && !fs::exists(bmp);
            bool needJpg = jb.toJpg && !fs::exists(jpg);
            if (!(needBmp || needJpg)) continue;

            MIL_INT w64 = MbufDiskInquire(mim.c_str(), M_SIZE_X, M_NULL);
            MIL_INT h64 = MbufDiskInquire(mim.c_str(), M_SIZE_Y, M_NULL);
            int w = static_cast<int>(w64);
            int h = static_cast<int>(h64);
            int b = jb.channelCnt;

            // 사이즈나 밴드 설정이 변경되면 버퍼 재할당
            if (w != curW || h != curH || b != curBand)
            {
                if (hRaw) MbufFree(hRaw);
                if (hClr) MbufFree(hClr);
                if (hGrayProc) MbufFree(hGrayProc);
                if (hFloatSum) MbufFree(hFloatSum);

                curW = w; curH = h; curBand = b;

                hRaw = (b == 1)
                    ? MbufAlloc2d(milSys, w, h, 8 + M_UNSIGNED, M_IMAGE + M_PROC, M_NULL)
                    : MbufAllocColor(milSys, 3, w, h, 8 + M_UNSIGNED, M_IMAGE + M_PROC, M_NULL);

                hClr = MbufAllocColor(milSys, 3, w, h, 8 + M_UNSIGNED, M_IMAGE + M_PROC, M_NULL);

                // Gray 옵션이 켜져있을 때만 할당
                if (jb.toGray) {
                    MbufAlloc2d(milSys, w, h, 8 + M_UNSIGNED, M_IMAGE + M_PROC, &hGrayProc);

                    // ImageJ 방식(Type 1)일 경우 정밀 연산을 위해 Float 할당
                    if (jb.grayType == 1) {
                        MbufAlloc2d(milSys, w, h, 32 + M_FLOAT, M_IMAGE + M_PROC, &hFloatSum);
                    }
                }
            }

            /* -- 변환 / 저장 ---------------------------------------- */
            MbufLoad(mim.c_str(), hRaw);

            // 1. 기본 Bayer -> Color 변환
            if (b == 1) {
                MIL_INT64 interpFlag = 0;
                switch (jb.bayerInterp) {
                case 1:  interpFlag = M_ADAPTIVE_FAST;    break;
                case 2:  interpFlag = M_AVERAGE_2X2;      break;
                case 3:  interpFlag = M_BILINEAR;         break;
                case 0:
                default: interpFlag = M_ADAPTIVE + M_COLOR_CORRECTION; break;
                }
                MbufBayer(hRaw, hClr, hCoef, ToMilBayer(jb.bayerOrder) + interpFlag);
            }
            else {
                MbufCopy(hRaw, hClr);
            }

            // 2. [Color -> Gray] 변환 로직
            MIL_ID hFinal = hClr; // 기본 저장 대상은 Color

            if (jb.toGray && hGrayProc)
            {
                if (jb.grayType == 0)
                {
                    // Option 0: Standard Luminance (MimConvert)
                    MimConvert(hClr, hGrayProc, M_RGB_TO_L);
                }
                else if (jb.grayType == 1 && hFloatSum)
                {
                    // Option 1: Average (ImageJ Style)
                    MIL_ID R = MbufChildColor(hClr, M_RED, M_NULL);
                    MIL_ID G = MbufChildColor(hClr, M_GREEN, M_NULL);
                    MIL_ID B = MbufChildColor(hClr, M_BLUE, M_NULL);

                    MimArith(R, G, hFloatSum, M_ADD);
                    MimArith(hFloatSum, B, hFloatSum, M_ADD);
                    MimArith(hFloatSum, 3.0, hGrayProc, M_DIV_CONST);

                    MbufFree(R); MbufFree(G); MbufFree(B);
                }

                hFinal = hGrayProc; // 저장 대상을 Gray 버퍼로 교체
            }

            // 3. 최종 저장
            auto save = [&](const fs::path& p, MIL_INT fmt, MIL_ID buf)
            {
                MbufExport(p.c_str(), fmt, buf);
                std::wcout << L"[SAVE] " << p.c_str() << L"\n";
            };

            if (needBmp) save(bmp, M_BMP, hFinal);
            if (needJpg) save(jpg, M_JPEG_LOSSY, hFinal);
        }
    }
    catch (const fs::filesystem_error& ex)
    {
        std::wcerr << L"[ERROR] 파일 시스템 예외: " << ex.what() << L"\n";
    }

    if (hRaw) MbufFree(hRaw);
    if (hClr) MbufFree(hClr);
    if (hGrayProc) MbufFree(hGrayProc);
    if (hFloatSum) MbufFree(hFloatSum);
}

/* =========================================================
 * main
 * =======================================================*/
int wmain(int argc, wchar_t* argv[])
{
    std::wcout.imbue(std::locale("korean"));

    /* -------- INI 경로 결정 -------- */
    if (argc >= 2) gIniPath = fs::absolute(argv[1]);
    else           gIniPath = fs::absolute(gIniPath);
    std::wcout << L"[INI] " << gIniPath.c_str() << L"\n";

    /* -------- Job 로드 -------- */
    auto jobs = LoadJobsFromIni();
    if (jobs.empty()) return -1;

    /* -------- MIL 초기화 -------- */
    MIL_ID milApp{}, milSys{};
    MappAlloc(M_DEFAULT, &milApp);
    MsysAlloc(M_SYSTEM_HOST, M_DEV0, M_DEFAULT, &milSys);

    const float coef[3] = { 1.f,1.f,1.f };
    MIL_ID hCoef = MbufAlloc1d(milSys, 3, M_FLOAT + 32, M_ARRAY, M_NULL);
    MbufPut(hCoef, coef);

    /* -------- Job 실행 -------- */
    for (const auto& jb : jobs) RunOneJob(jb, milSys, hCoef);

    /* -------- 마무리 -------- */
    MbufFree(hCoef);
    MsysFree(milSys);
    MappFree(milApp);

    std::wcout << L"\n=============  모든 Job 완료  =============\n";
    system("pause");
    return 0;
}