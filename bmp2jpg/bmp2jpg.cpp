// bmp2jpg.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 일부 CString 생성자는 명시적으로 선언됩니다.

#include <afxwin.h>         // MFC 핵심 및 표준 구성 요소입니다.
#include <afxext.h>         // MFC 확장입니다.

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE 클래스입니다.
#include <afxodlgs.h>       // MFC OLE 대화 상자 클래스입니다.
#include <afxdisp.h>        // MFC 자동화 클래스입니다.
#endif // _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>                      // MFC ODBC 데이터베이스 클래스입니다.
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>                     // MFC DAO 데이터베이스 클래스입니다.
#endif // _AFX_NO_DAO_SUPPORT

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Internet Explorer 4 공용 컨트롤에 대한 MFC 지원입니다.
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // Windows 공용 컨트롤에 대한 MFC 지원입니다.
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxsock.h>            // 

#include <iostream>
#include <minwinbase.h>
#include <winnt.h>
#include <fileapi.h>
#include <handleapi.h>
#include <direct.h>
#include <sstream>
#include <filesystem>
#include "mil.h"

using std::filesystem::recursive_directory_iterator;
MIL_ID	g_milApp, g_milSys;
int main()
{
    std::wcout.imbue(std::locale("korean"));

    MappAlloc(M_DEFAULT, &g_milApp);
    MsysAlloc(M_SYSTEM_HOST, M_DEV0, M_DEFAULT, &g_milSys);

    int	nWidth{ -1 }, nHeight{ -1 };
    MIL_ID milBmp{ M_NULL }, milColor{ M_NULL };

    float			fBayerCoefR{ 1 }, fBayerCoefG{ 1 }, fBayerCoefB{ 1 };
    const wchar_t* szRecipePath = L".\\mim_converter_config.ini";

    wchar_t	pBuff[256];

    wchar_t curDir[1000];
    _wgetcwd(curDir, 1000);
    std::wstringstream ss;
    ss << curDir << L"\\*.*";

    std::wcout << L"Convert all .bmp in subpath to .jpg !\n";
    std::wcout << L"===============================================\n";

    for (const auto& file : recursive_directory_iterator("./"))
    {
        std::wstring strName = file.path().c_str();
        strName = strName.substr(2);

        // mim 이 없으면
        if (std::wstring::npos == strName.find(L".bmp"))
            continue;

        std::wcout << strName.c_str() << std::endl;

        std::wstring strJpgName = strName;
        strJpgName.replace(strJpgName.end() - 3, strJpgName.end(), L"jpg");

        if (std::filesystem::exists(strJpgName.c_str())) {
            std::wcout << L"Converted file of \"" << strName.c_str() << L"\" is alread exist.\n";
            continue;
        }


        ss = std::wstringstream(L"");
        ss << curDir << L"\\" << strName.c_str();

        int nNewWidth = MbufDiskInquire(ss.str().c_str(), M_SIZE_X, M_NULL);
        int nNewHeight = MbufDiskInquire(ss.str().c_str(), M_SIZE_Y, M_NULL);
        if (nWidth != nNewWidth || nHeight != nNewHeight) {
            if(milBmp) {
                MbufFree(milBmp);
                milBmp=M_NULL;
            }
            nWidth= nNewWidth;
            nHeight = nNewHeight;
            milBmp = MbufAllocColor(g_milSys, 3, nWidth, nHeight, 8 + M_UNSIGNED, M_IMAGE + M_PROC, M_NULL);
        }
        MbufLoad(ss.str().c_str(), milBmp);

        MbufExport(strJpgName.c_str(), M_JPEG_LOSSY, milBmp);
        std::wcout << strJpgName.c_str() << L" is saved !\n";
    }

    std::wcout << L"======================================\nDONE ! \n";


    if (milBmp)
        MbufFree(milBmp);
    if (milColor)
        MbufFree(milColor);

    MsysFree(g_milSys);
    MappFree(g_milApp);

    system("pause");
    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
