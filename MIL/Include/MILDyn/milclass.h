////////////////////////////////////////////////////////////////////////////////
//! 
//! \brief Milclass CAPI header (Mclass...)
//! 
//! AUTHOR: Matrox Imaging
//!
//! COPYRIGHT NOTICE:
//! Copyright (c) Matrox Electronic Systems Ltd., 1992-2018.
//! All Rights Reserved 
//  Revision:  10.30.0595
////////////////////////////////////////////////////////////////////////////////

#ifndef __MIL_CLASS_H__
#define __MIL_CLASS_H__

#if (!M_MIL_LITE) /* MIL FULL ONLY */

#if M_MIL_USE_RT
#ifdef M_CLASS_EXPORTS
#define MIL_CLASS_DLLFUNC __declspec(dllexport)
#else
#define MIL_CLASS_DLLFUNC __declspec(dllimport)
#endif
#else
#define MIL_CLASS_DLLFUNC
#endif

/* C++ directive if needed */
#ifdef __cplusplus
extern "C"
   {
#endif

////////////////////////////////////////////////////////////////////////////////
// MclassAlloc ContextTypes

#define M_CONVOLUTIONAL_NETWORK                       2779L
#define M_PRETRAINED_CONVOLUTIONAL_NETWORK            2913L

////////////////////////////////////////////////////////////////////////////////   
// Indexing, used in other Mclass functions (MclassInquire(), MclassControl(), ...)
#define M_DEFAULT                               0x10000000L // already defined
#define M_CONTEXT                               0x08000000L // already defined
#define M_GENERAL                               0x20000000L // already defined
#define M_ALL                                   0x40000000L // already defined
#define M_ANY                                   0x11000000L // already defined
                                                

#define M_CLASS_DESCRIPTION_INDEX_VALUE               2898L

#define M_NEW_LABEL                             0x04000000L

#define M_OWNER_SYSTEM                                1101L // already defined
#define M_MODIFICATION_COUNT                          5010L // already defined




#define M_DEFAULT_SOURCE_LAYER                  0x02100000L

#define M_CLASS_DESCRIPTION_INDEX_FLAG          0x00200000L


#define M_CLASS_DESCRIPTION(IndexValue)       (M_CLASS_DESCRIPTION_INDEX_FLAG | (IndexValue))

                                                               
#define M_TIMEOUT                                     2077L // already defined
                                              
#define M_SOURCE                                      2800L //
#define M_OUTPUT                                         3L // already defined

////////////////////////////////////////////////////////////////////////////////
// MclassControl
                                                               
#define M_TIMEOUT                                     2077L // already defined
                                                               
////////////////////////////////////////////////////////////////////////////////
// MclassControl / MclassInquire
// Context 

#define M_ENABLE                                     -9997L // already defined
#define M_DISABLE                                    -9999L // already defined

#define M_AUTO                                         444L // already defined
#define M_USER_DEFINED                                  21L // already defined

#define M_STOP_PREDICT                                2785L

#define M_PREPROCESSED                                  14L // already defined



#define M_SIZE                                       0xC00L // already defined
#define M_SIZE_X                                      1536L // already defined
#define M_SIZE_Y                                      1537L // already defined
#define M_SIZE_BAND                                   1005L // already defined
#define M_BAND_ORDER                                  3036L

#define M_RGB                                            8L // already defined in mil.h, milcolor.h
#define M_BGR                                         0x07L

#define M_METHOD                                       103L // already defined

#define M_MAX                                   0x04000000L // already defined
#define M_AVERAGE                               0x00000020L // already defined


#define M_STRIDE_X                                    2810L
#define M_STRIDE_Y                                    2811L

#define M_OVERSCAN                                      53L // already defined



#define M_TYPE                                        1008L // already defined
#define M_GLOBAL                                0x00000008L // already defined
#define M_LOCAL                                 0x01000000  // already defined

#define M_IDENTITY                                       6L // already defined

#define M_HOST                                         100L // already defined

#define M_EXPIRY_DATE_STRING                          (2990L | M_CLIENT_ENCODING)

#define M_GAMMA                                       6672L // already defined
#define M_MEAN                                  0x08000000L // already defined
#define M_VARIANCE                              0x01000000L // already defined

#define M_NORMALIZATION_SCALE                         2856L
#define M_NORMALIZATION_OFFSET                        2857L

#define M_PREDICT_MODE                                2859L
#define M_SINGLE_CLASSIFICATION                       2860L
#define M_CLASSIFICATION_MAP                          2861L

#define M_CLASSIFICATION_MAP_SIZE_X                   2862L
#define M_CLASSIFICATION_MAP_SIZE_Y                   2863L

#define M_CLASSIFICATION_MAP_INPUT_SIZE_X             2871L
#define M_CLASSIFICATION_MAP_INPUT_SIZE_Y             2872L

#define M_OPERATION                                M_METHOD // already defined
#define M_ADD                                       0x0000L // already defined

#define M_CONSTANT                                  0x8000L // already defined

#define M_SAMPLE_IMAGE_ID                             2907L

#define M_NUMBER_OF_CLASS_DESCRIPTIONS                2945L
#define M_MAX_NUMBER_OF_CLASS_DESCRIPTIONS            2946L


#define M_MP_USE                                      (M_APP_INQUIRE_SYS_START+128L) // 15128 (already defined)

// Result                                                   
#define M_RESET                                          9L // already defined

////////////////////////////////////////////////////////////////////////////////
// MclassInquire 
// Context
#define M_PREPROCESSED                                  14L // already defined

#define M_INVALID                                        -1 // already defined

// Combination flags. Should be binary exclusives.



////////////////////////////////////////////////////////////////////////////////
// MclassAllocResult ResultTypes

////////////////////////////////////////////////////////////////////////////////
// MclassGetResult ResultTypes

// General
#define M_STATUS                                0x00008002L // already defined
#define M_TIMEOUT_REACHED                             2554L
#define M_STOPPED_BY_REQUEST                          2555L
#define M_NOT_ENOUGH_MEMORY                              4L // already defined
#define M_COMPLETE                              0x00000000L // already defined
#define M_INTERNAL_ERROR                                 5L // already defined
#define M_PREDICT_NOT_PERFORMED                       2788L
#define M_CURRENTLY_PREDICTING                        2789L

#define M_NUMBER_OF_CLASSES                           2848L 
#define M_CLASS_SCORES                                2837L 
#define M_BEST_CLASS_INDEX                            2847L
#define M_BEST_CLASS_SCORE                            2889L
#define M_NUMBER_OF_CLASS_SCORES                      2864L

////////////////////////////////////////////////////////////////////////////////
// Other defines

////////////////////////////////////////////////////////////////////////////////
// CAPI function prototypes
MIL_CLASS_DLLFUNC MIL_ID MFTYPE MclassAlloc(MIL_ID    SysId,
                                            MIL_INT64 ContextType,
                                            MIL_INT64 ControlFlag,
                                            MIL_ID*   ContextClassIdPtr);

MIL_CLASS_DLLFUNC MIL_ID MFTYPE MclassAllocResult(MIL_ID    SysId,
                                                  MIL_INT64 ResultType,
                                                  MIL_INT64 ControlFlag,
                                                  MIL_ID*   ResultClassIdPtr);

MIL_CLASS_DLLFUNC void MFTYPE MclassFree(MIL_ID ContextOrResultClassId);

#if M_MIL_USE_64BIT
// Prototypes for 64 bits OSs
MIL_CLASS_DLLFUNC void MFTYPE MclassControlInt64(MIL_ID     ContextOrResultClassId,
                                                 MIL_INT64  LabelOrIndex,
                                                 MIL_INT64  ControlType,
                                                 MIL_INT64  ControlValue);
MIL_CLASS_DLLFUNC void MFTYPE MclassControlDouble(MIL_ID     ContextOrResultClassId,
                                                  MIL_INT64  LabelOrIndex,
                                                  MIL_INT64  ControlType,
                                                  MIL_DOUBLE ControlValue);
#else
// Prototypes for 32 bits OSs
#define MclassControlInt64  MclassControl
#define MclassControlDouble MclassControl

MIL_CLASS_DLLFUNC void MFTYPE MclassControl(MIL_ID     ContextOrResultClassId,
                                            MIL_INT64  LabelOrIndex,
                                            MIL_INT64  ControlType,
                                            MIL_DOUBLE ControlValue);
#endif

MIL_CLASS_DLLFUNC MIL_INT MFTYPE MclassInquire(MIL_ID    ContextOrResultClassId,
                                               MIL_INT64 LabelOrIndex,
                                               MIL_INT64 InquireType,
                                               void*     UserVarPtr);

MIL_CLASS_DLLFUNC void MFTYPE MclassPreprocess(MIL_ID    ContextClassId,
                                               MIL_INT64 ControlFlag);

MIL_CLASS_DLLFUNC void MFTYPE MclassPredict(MIL_ID    ContextClassId,
                                            MIL_ID    TargetImageBufId,
                                            MIL_ID    ResultClassId,
                                            MIL_INT64 ControlFlag);

MIL_CLASS_DLLFUNC void MFTYPE MclassGetResult(MIL_ID    ResultClassId,
                                              MIL_INT64 LabelOrIndex,
                                              MIL_INT64 ResultType,
                                              void*     ResultArrayPtr);

#if M_MIL_USE_UNICODE
MIL_CLASS_DLLFUNC void MFTYPE MclassSaveA(MIL_CONST_TEXTA_PTR FileName,
                                          MIL_ID      ContextClassId,
                                          MIL_INT64   ControlFlag);

MIL_CLASS_DLLFUNC MIL_ID MFTYPE MclassRestoreA(MIL_CONST_TEXTA_PTR FileName,
                                               MIL_ID      SysId,
                                               MIL_INT64   ControlFlag,
                                               MIL_ID*     ContextClassIdPtr);

MIL_CLASS_DLLFUNC void MFTYPE MclassStreamA(MIL_TEXTA_PTR MemPtrOrFileName,
                                            MIL_ID     SysId,
                                            MIL_INT64  Operation,
                                            MIL_INT64  StreamType,
                                            MIL_DOUBLE Version,
                                            MIL_INT64  ControlFlag,
                                            MIL_ID*    ContextClassIdPtr,
                                            MIL_INT*   SizeByteVarPtr);


MIL_CLASS_DLLFUNC void MFTYPE MclassSaveW(MIL_CONST_TEXTW_PTR FileName,
                                          MIL_ID              ContextClassId,
                                          MIL_INT64           ControlFlag);

MIL_CLASS_DLLFUNC MIL_ID MFTYPE MclassRestoreW(MIL_CONST_TEXTW_PTR FileName,
                                               MIL_ID              SysId,
                                               MIL_INT64           ControlFlag,
                                               MIL_ID*             ContextClassIdPtr);

MIL_CLASS_DLLFUNC void MFTYPE MclassStreamW(MIL_TEXTW_PTR MemPtrOrFileName,
                                            MIL_ID        SysId,
                                            MIL_INT64     Operation,
                                            MIL_INT64     StreamType,
                                            MIL_DOUBLE    Version,
                                            MIL_INT64     ControlFlag,
                                            MIL_ID*       ContextClassIdPtr,
                                            MIL_INT*      SizeByteVarPtr);


#if M_MIL_UNICODE_API
#define MclassSave               MclassSaveW
#define MclassRestore            MclassRestoreW
#define MclassStream             MclassStreamW
#else
#define MclassSave               MclassSaveA
#define MclassRestore            MclassRestoreA
#define MclassStream             MclassStreamA
#endif


#else

MIL_CLASS_DLLFUNC void MFTYPE MclassSave(MIL_CONST_TEXT_PTR FileName,
                                         MIL_ID             ContextClassId,
                                         MIL_INT64          ControlFlag);

MIL_CLASS_DLLFUNC MIL_ID MFTYPE MclassRestore(MIL_CONST_TEXT_PTR FileName,
                                              MIL_ID             SysId,
                                              MIL_INT64          ControlFlag,
                                              MIL_ID*            ContextClassIdPtr);

MIL_CLASS_DLLFUNC void MFTYPE MclassStream(MIL_TEXT_PTR MemPtrOrFileName,
                                           MIL_ID       SysId,
                                           MIL_INT64    Operation,
                                           MIL_INT64    StreamType,
                                           MIL_DOUBLE   Version,
                                           MIL_INT64    ControlFlag,
                                           MIL_ID*      ContextClassIdPtr,
                                           MIL_INT*     SizeByteVarPtr);

#endif

/* C++ directive if needed */
#ifdef __cplusplus
}
#endif
////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus

inline void MFTYPE MclassStreamCpp(MilStreamParam MemPtrOrFileName,
                                   MIL_ID         SysId,
                                   MIL_INT64      Operation,
                                   MIL_INT64      StreamType,
                                   MIL_DOUBLE     Version,
                                   MIL_INT64      ControlFlag,
                                   MIL_ID*        ContextClassIdPtr,
                                   MIL_INT*       SizeByteVarPtr)
   {
   MclassStream(MemPtrOrFileName.m_Param, SysId, Operation, StreamType, Version, ControlFlag, ContextClassIdPtr, SizeByteVarPtr);
   }

#undef  MclassStream
#define MclassStream MclassStreamCpp

#endif // __cplusplus

#if M_MIL_USE_64BIT
#ifdef __cplusplus

//////////////////////////////////////////////////////////////
// MclassControl function overloads when compiling c++ files
//////////////////////////////////////////////////////////////
template <typename T>
inline void MclassControl(MIL_ID ContextOrResultClassId, MIL_INT64 LabelOrIndex, MIL_INT64 ControlType, T ControlValue)
   { MclassControlInt64(ContextOrResultClassId, LabelOrIndex, ControlType, ControlValue); };

inline void MclassControl(MIL_ID ContextOrResultClassId, MIL_INT64 LabelOrIndex, MIL_INT64 ControlType, float ControlValue)
   { MclassControlDouble(ContextOrResultClassId, LabelOrIndex, ControlType, ControlValue); };

inline void MclassControl(MIL_ID ContextOrResultClassId, MIL_INT64 LabelOrIndex, MIL_INT64 ControlType, MIL_DOUBLE ControlValue)
   { MclassControlDouble(ContextOrResultClassId, LabelOrIndex, ControlType, ControlValue); };
#else // __cplusplus
//////////////////////////////////////////////////////////////
// For C file, call the default function, i.e. Double one
//////////////////////////////////////////////////////////////
#define MclassControl            MclassControlDouble
#endif // __cplusplus
#endif // M_MIL_USE_64BIT

#if M_MIL_USE_SAFE_TYPE

//////////////////////////////////////////////////////////////
// See milos.h for explanation about these functions.
//////////////////////////////////////////////////////////////

// -------------------------------------------------------------------------
// Utility structures for void pointers.

struct ClassVoidPtr
   {
#if M_MIL_SAFE_TYPE_M_NULL_PTR_TYPE_EXISTS
   inline ClassVoidPtr(std::nullptr_t          ) : m_IntVal (M_NULL      ), m_PtrType( 0             ) {}
#endif
   inline ClassVoidPtr(int         NullPtr     ) : m_IntVal (NullPtr     ), m_PtrType( 0             ) {}
   inline ClassVoidPtr(MIL_UINT8  *MilUInt8Ptr ) : m_VoidPtr(MilUInt8Ptr ), m_PtrType( 8 + M_UNSIGNED) {}
   inline ClassVoidPtr(MIL_UINT16 *MilUInt16Ptr) : m_VoidPtr(MilUInt16Ptr), m_PtrType(16 + M_UNSIGNED) {}
   inline ClassVoidPtr(MIL_UINT32 *MilUInt32Ptr) : m_VoidPtr(MilUInt32Ptr), m_PtrType(32 + M_UNSIGNED) {}
   inline ClassVoidPtr(MIL_UINT64 *MilUInt64Ptr) : m_VoidPtr(MilUInt64Ptr), m_PtrType(64 + M_UNSIGNED) {}
   inline ClassVoidPtr(MIL_INT8   *MilInt8Ptr  ) : m_VoidPtr(MilInt8Ptr  ), m_PtrType( 8 + M_SIGNED  ) {}
   inline ClassVoidPtr(MIL_INT16  *MilInt16Ptr ) : m_VoidPtr(MilInt16Ptr ), m_PtrType(16 + M_SIGNED  ) {}
   inline ClassVoidPtr(MIL_INT32  *MilInt32Ptr ) : m_VoidPtr(MilInt32Ptr ), m_PtrType(32 + M_SIGNED  ) {}
   inline ClassVoidPtr(MIL_INT64  *MilInt64Ptr ) : m_VoidPtr(MilInt64Ptr ), m_PtrType(64 + M_SIGNED  ) {}
   inline ClassVoidPtr(MIL_FLOAT  *MilFloatPtr ) : m_VoidPtr(MilFloatPtr ), m_PtrType(32 + M_FLOAT   ) {}
   inline ClassVoidPtr(MIL_DOUBLE *MilDoublePtr) : m_VoidPtr(MilDoublePtr), m_PtrType(64 + M_FLOAT   ) {}

   union
      {
      void*   m_VoidPtr;
      MIL_INT m_IntVal;
      };
   MIL_INT64  m_PtrType;
   };

struct ClassConstVoidPtr
   {
#if M_MIL_SAFE_TYPE_M_NULL_PTR_TYPE_EXISTS
   inline ClassConstVoidPtr(std::nullptr_t                ) : m_IntVal      (M_NULL      ), m_PtrType( 0             ) {}
#endif
   inline ClassConstVoidPtr(int               NullPtr     ) : m_IntVal      (NullPtr     ), m_PtrType( 0             ) {}
   inline ClassConstVoidPtr(const MIL_UINT8  *MilUInt8Ptr ) : m_ConstVoidPtr(MilUInt8Ptr ), m_PtrType( 8 + M_UNSIGNED) {}
   inline ClassConstVoidPtr(const MIL_UINT16 *MilUInt16Ptr) : m_ConstVoidPtr(MilUInt16Ptr), m_PtrType(16 + M_UNSIGNED) {}
   inline ClassConstVoidPtr(const MIL_UINT32 *MilUInt32Ptr) : m_ConstVoidPtr(MilUInt32Ptr), m_PtrType(32 + M_UNSIGNED) {}
   inline ClassConstVoidPtr(const MIL_UINT64 *MilUInt64Ptr) : m_ConstVoidPtr(MilUInt64Ptr), m_PtrType(64 + M_UNSIGNED) {}
   inline ClassConstVoidPtr(const MIL_INT8   *MilInt8Ptr  ) : m_ConstVoidPtr(MilInt8Ptr  ), m_PtrType( 8 + M_SIGNED  ) {}
   inline ClassConstVoidPtr(const MIL_INT16  *MilInt16Ptr ) : m_ConstVoidPtr(MilInt16Ptr ), m_PtrType(16 + M_SIGNED  ) {}
   inline ClassConstVoidPtr(const MIL_INT32  *MilInt32Ptr ) : m_ConstVoidPtr(MilInt32Ptr ), m_PtrType(32 + M_SIGNED  ) {}
   inline ClassConstVoidPtr(const MIL_INT64  *MilInt64Ptr ) : m_ConstVoidPtr(MilInt64Ptr ), m_PtrType(64 + M_SIGNED  ) {}
   inline ClassConstVoidPtr(const MIL_FLOAT  *MilFloatPtr ) : m_ConstVoidPtr(MilFloatPtr ), m_PtrType(32 + M_FLOAT   ) {}
   inline ClassConstVoidPtr(const MIL_DOUBLE *MilDoublePtr) : m_ConstVoidPtr(MilDoublePtr), m_PtrType(64 + M_FLOAT   ) {}

   union
      {
      const void* m_ConstVoidPtr;
      MIL_INT     m_IntVal;
      };
   MIL_INT64      m_PtrType;
   };

// -------------------------------------------------------------------------
// MclassGetResult safe type declarations

inline void MFTYPE MclassGetResultUnsafe  (MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, void*          ResultArrayPtr);
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, int            ResultArrayPtr);
#if M_MIL_SAFE_TYPE_M_NULL_PTR_TYPE_EXISTS                                                    
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, std::nullptr_t ResultArrayPtr);
#endif                                                                                        
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_INT8*      ResultArrayPtr);
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_INT16*     ResultArrayPtr);
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_INT32*     ResultArrayPtr);
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_INT64*     ResultArrayPtr);
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, float*         ResultArrayPtr);
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_DOUBLE*    ResultArrayPtr);
#if M_MIL_USE_UNICODE && M_MIL_UNICODE_API                                                    
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_TEXT_PTR   ResultArrayPtr);
#endif                                                                                        
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                                                         
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_UINT8*     ResultArrayPtr);
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_UINT16*    ResultArrayPtr);
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_UINT32*    ResultArrayPtr);
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_UINT64*    ResultArrayPtr);
#endif

// -------------------------------------------------------------------------
// MclassGetResult safe type definitions
// 

inline void MFTYPE MclassGetResultSafeType (MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, int ResultPtr)
   {
   if (ResultPtr != 0)
      SafeTypeError(MIL_TEXT("MclassGetResult"));

   MclassGetResult(ResultClassId, LayerLabelOrIndex, ResultType, NULL);
   }

#if M_MIL_SAFE_TYPE_M_NULL_PTR_TYPE_EXISTS
inline void MFTYPE MclassGetResultSafeType (MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, std::nullptr_t ResultPtr)
   {
   if (ResultPtr != M_NULL)
      SafeTypeError(MIL_TEXT("MclassGetResult"));

   MclassGetResult(ResultClassId, LayerLabelOrIndex, ResultType, NULL);
   }
#endif


inline void MclassGetResultSafeTypeExecute (MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, void* ResultArrayPtr, MIL_INT64 GivenType)
   {
   MIL_INT64 RequiredType = (ResultType & M_HLVLDATATYPE_MASK);
   if((RequiredType != M_TYPE_MIL_DOUBLE) && (RequiredType != M_TYPE_MIL_INT32) && (RequiredType != M_TYPE_MIL_INT64) && 
      (RequiredType != M_TYPE_MIL_ID)     && (RequiredType != M_TYPE_FLOAT)     && (RequiredType != M_TYPE_CHAR)      &&
      (RequiredType != M_TYPE_SHORT)      && (RequiredType != M_TYPE_MIL_UINT8) && (RequiredType != M_TYPE_STRING))
      { RequiredType = 0; }

   if(RequiredType == 0)
      { RequiredType = M_TYPE_MIL_DOUBLE; }

   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MIL_TEXT("MclassGetResult"));

   MclassGetResult(ResultClassId, LayerLabelOrIndex, ResultType, ResultArrayPtr);
   }


inline void MFTYPE MclassGetResultUnsafe  (MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, void*        ResultArrayPtr){MclassGetResult               (ResultClassId, LayerLabelOrIndex, ResultType, ResultArrayPtr                     );}
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_INT8*    ResultArrayPtr){MclassGetResultSafeTypeExecute(ResultClassId, LayerLabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_CHAR        );}
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_UINT8*   ResultArrayPtr){MclassGetResultSafeTypeExecute(ResultClassId, LayerLabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_UINT8   );}
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_INT16*   ResultArrayPtr){MclassGetResultSafeTypeExecute(ResultClassId, LayerLabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_SHORT       );}
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_INT32*   ResultArrayPtr){MclassGetResultSafeTypeExecute(ResultClassId, LayerLabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_INT32   );}
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_INT64*   ResultArrayPtr){MclassGetResultSafeTypeExecute(ResultClassId, LayerLabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_INT64   );}
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, float*       ResultArrayPtr){MclassGetResultSafeTypeExecute(ResultClassId, LayerLabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_FLOAT       );}
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_DOUBLE*  ResultArrayPtr){MclassGetResultSafeTypeExecute(ResultClassId, LayerLabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_DOUBLE  );}

#if M_MIL_USE_UNICODE && M_MIL_UNICODE_API
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_TEXT_PTR ResultArrayPtr){MclassGetResultSafeTypeExecute(ResultClassId, LayerLabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_STRING   );}
#endif

#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_UINT16* ResultArrayPtr){MclassGetResultSafeTypeExecute(ResultClassId, LayerLabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_SHORT    );}
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_UINT32* ResultArrayPtr){MclassGetResultSafeTypeExecute(ResultClassId, LayerLabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_INT32);}
inline void MFTYPE MclassGetResultSafeType(MIL_ID ResultClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 ResultType, MIL_UINT64* ResultArrayPtr){MclassGetResultSafeTypeExecute(ResultClassId, LayerLabelOrIndex, ResultType, ResultArrayPtr, M_TYPE_MIL_INT64);}
#endif

// ----------------------------------------------------------
// MclassInquire safe type declarations

inline MIL_INT MFTYPE MclassInquireUnsafe  (MIL_ID ContextOrResultClassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, void*          UserVarPtr);
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID ContextOrResultClassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, int            UserVarPtr);
#if M_MIL_SAFE_TYPE_M_NULL_PTR_TYPE_EXISTS
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID ContextOrResultClassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, std::nullptr_t UserVarPtr);
#endif
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID ContextOrResultClassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, MIL_INT8*      UserVarPtr);
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID ContextOrResultClassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, MIL_INT32*     UserVarPtr);
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID ContextOrResultClassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, MIL_INT64*     UserVarPtr);
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID ContextOrResultClassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, float*         UserVarPtr);
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID ContextOrResultClassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, MIL_DOUBLE*    UserVarPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                                                                        
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID ContextOrResultClassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, MIL_UINT8*     UserVarPtr);
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID ContextOrResultClassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, MIL_UINT16*    UserVarPtr);
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID ContextOrResultClassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, MIL_UINT32*    UserVarPtr);
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID ContextOrResultClassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, MIL_UINT64*    UserVarPtr);
#endif                                                                              
#if M_MIL_SAFE_TYPE_ADD_WCHAR_T                                                     
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID ContextOrResultClassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, wchar_t*    UserVarPtr);
#endif

// ----------------------------------------------------------
// MclassInquire safe type definitions

inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID MclassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, int UserVarPtr)
   {
   if (UserVarPtr != 0)
      SafeTypeError(MIL_TEXT("MclassInquire"));

   return MclassInquire(MclassId, LabelOrIndex, InquireType, NULL);
   }

#if M_MIL_SAFE_TYPE_M_NULL_PTR_TYPE_EXISTS
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID MclassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, std::nullptr_t)
   {
   return MclassInquire(MclassId, LabelOrIndex, InquireType, NULL);
   }
#endif

inline MIL_INT MFTYPE MclassInquireSafeTypeExecute(MIL_ID MclassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, void* UserVarPtr, MIL_INT64 GivenType)
   {
   MIL_INT64 RequiredType = (InquireType & M_HLVLDATATYPE_MASK);

   if((RequiredType != M_TYPE_MIL_DOUBLE) && (RequiredType != M_TYPE_MIL_INT32) && (RequiredType != M_TYPE_MIL_INT64) && 
      (RequiredType != M_TYPE_MIL_ID)     && (RequiredType != M_TYPE_FLOAT)     && (RequiredType != M_TYPE_CHAR)      &&
      (RequiredType != M_TYPE_SHORT)      && (RequiredType != M_TYPE_MIL_UINT8) && (RequiredType != M_TYPE_STRING))
      RequiredType = 0;

   MIL_INT64 StrippedInquireType = M_STRIP_CLIENT_TEXT_ENCODING(InquireType);
   bool StrInquire = ( (StrippedInquireType == M_STRIP_CLIENT_TEXT_ENCODING(M_EXPIRY_DATE_STRING))
                     );
   if (RequiredType == 0)
      { RequiredType = (StrInquire ? M_TYPE_STRING : M_TYPE_MIL_DOUBLE); }

   if(StrInquire                               &&
      M_CLIENT_ASCII_ENCODING_SET(InquireType) &&
      (GivenType == M_TYPE_CHAR))
      { GivenType = M_TYPE_STRING; }

   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MIL_TEXT("MclassInquire"));

   return MclassInquire(MclassId, LabelOrIndex, InquireType, UserVarPtr);
   }

inline MIL_INT MFTYPE MclassInquireUnsafe  (MIL_ID MclassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, void*       UserVarPtr) {return MclassInquire               (MclassId, LabelOrIndex, InquireType, UserVarPtr                   );}
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID MclassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, MIL_INT8*   UserVarPtr) {return MclassInquireSafeTypeExecute(MclassId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_CHAR      );}
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID MclassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, MIL_UINT8*  UserVarPtr) {return MclassInquireSafeTypeExecute(MclassId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_MIL_UINT8 );}
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID MclassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, MIL_INT32*  UserVarPtr) {return MclassInquireSafeTypeExecute(MclassId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_MIL_INT32 );}
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID MclassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, MIL_INT64*  UserVarPtr) {return MclassInquireSafeTypeExecute(MclassId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_MIL_INT64 );}
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID MclassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, float*      UserVarPtr) {return MclassInquireSafeTypeExecute(MclassId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_FLOAT     );}
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID MclassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, MIL_DOUBLE* UserVarPtr) {return MclassInquireSafeTypeExecute(MclassId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_MIL_DOUBLE);}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID MclassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, MIL_UINT16* UserVarPtr) {return MclassInquireSafeTypeExecute(MclassId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_SHORT     );}
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID MclassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, MIL_UINT32* UserVarPtr) {return MclassInquireSafeTypeExecute(MclassId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_MIL_INT32 );}
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID MclassId, MIL_INT64 LabelOrIndex, MIL_INT64 InquireType, MIL_UINT64* UserVarPtr) {return MclassInquireSafeTypeExecute(MclassId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_MIL_INT64 );}
#endif
#if M_MIL_SAFE_TYPE_ADD_WCHAR_T
inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID MclassId, MIL_INT64 LabelOrIndex, MIL_INT64  InquireType, wchar_t*    UserVarPtr) {return MclassInquireSafeTypeExecute(MclassId, LabelOrIndex, InquireType, UserVarPtr, M_TYPE_STRING   );}
#endif

//------------------------------
// Safetype functions assignment

#define MclassGetResult            MclassGetResultSafeType
#define MclassInquire              MclassInquireSafeType

#else // #if M_MIL_USE_SAFE_TYPE

#define MclassGetResultUnsafe            MclassGetResult
#define MclassInquireUnsafe              MclassInquire

#endif // #if M_MIL_USE_SAFE_TYPE

// ----------------------------------------------------------
// Overload for std::vector.
#if defined(M_MIL_USE_VECTOR) && M_MIL_USE_VECTOR
template <typename UserType>
inline MIL_INT MFTYPE MclassInquire(MIL_ID MclassId, MIL_INT LabelOrIndex, MIL_INT64  InquireType, std::vector<UserType> &UserVarPtr)
   {
   // If the given MIL data type is not the same as the SrcType, change it to the correct one
   // and give a warning.
   MIL_INT64 InternalTrueDataTypeForStdVector = MilTraits<UserType>::TypeFlag;

#if M_MIL_USE_SAFE_TYPE
   if(M_GET_HLVLDATATYPE(InquireType) != 0)
      {
      SafeTypeError(MIL_TEXT("MclassInquire"), MIL_TEXT("Combination value for the required data type is not supported with std::vector overload."));
      }
#endif

   InquireType = M_STRIP_HLVLDATATYPE(InquireType) + InternalTrueDataTypeForStdVector;

   MIL_INT InternalNumberOfElementsForStdVector = 0;
   MclassInquire(MclassId, LabelOrIndex, M_STRIP_HLVLDATATYPE(InquireType) + M_NB_ELEMENTS + M_TYPE_MIL_INT, &InternalNumberOfElementsForStdVector);

   UserVarPtr.resize(InternalNumberOfElementsForStdVector);

   if(InternalNumberOfElementsForStdVector > 0)
      {
      return MclassInquire(MclassId, LabelOrIndex, InquireType, &UserVarPtr[0]);
      }
   return 0;
   }
template <typename UserType>
inline void MFTYPE MclassGetResult(MIL_ID ResultClassId, MIL_INT LayerLabelOrIndex, MIL_INT64  ResultType, std::vector<UserType> &ResultArrayPtr)
   {
   //! If the given MIL data type is not the same as the SrcType, change it to the correct one
   //! and give a warning.
   MIL_INT64 InternalTrueDataTypeForStdVector = MilTraits<UserType>::TypeFlag;

#if M_MIL_USE_SAFE_TYPE
   if(M_GET_HLVLDATATYPE(ResultType) != 0)
      {
      SafeTypeError(MIL_TEXT("MclassGetResult"), MIL_TEXT("Combination value for the required data type is not supported with std::vector overload."));
      }
#endif

   ResultType = M_STRIP_HLVLDATATYPE(ResultType) + InternalTrueDataTypeForStdVector;

   MIL_INT InternalNumberOfElementsForStdVector = 0;
   MclassGetResult(ResultClassId, LayerLabelOrIndex, M_STRIP_HLVLDATATYPE(ResultType) + M_NB_ELEMENTS + M_TYPE_MIL_INT, &InternalNumberOfElementsForStdVector);

   ResultArrayPtr.resize(InternalNumberOfElementsForStdVector);

   if(InternalNumberOfElementsForStdVector > 0)
      {
      MclassGetResult(ResultClassId, LayerLabelOrIndex, ResultType, &ResultArrayPtr[0]);
      }
   }

// ----------------------------------------------------------
// Overloads for std::vector in MxxxStream.
inline void MFTYPE MclassStream(std::vector<MIL_UINT8> &MemPtrOrFileName,
                                MIL_ID                 SysId,
                                MIL_INT64              Operation,
                                MIL_INT64              StreamType,
                                MIL_DOUBLE             Version,
                                MIL_INT64              ControlFlag,
                                MIL_ID*                McontextIdPtr,
                                MIL_INT*               SizeByteVarPtr)
   {
   MxxxStreamForStdVector(MemPtrOrFileName,
                          SysId,
                          Operation,
                          StreamType,
                          Version,
                          ControlFlag,
                          McontextIdPtr,
                          SizeByteVarPtr,
                          MclassStream);
   }
#endif // defined(M_MIL_USE_VECTOR) && M_MIL_USE_VECTOR

#ifdef M_MIL_USE_STRING
/***************************************************************************/
/* CLASS MODULE                                                              */
/***************************************************************************/
#if M_MIL_USE_UNICODE
#if M_MIL_UNICODE_API

inline void MFTYPE MclassSaveW(const MIL_STRING& FileName, MIL_ID ContextClassId, MIL_INT64 ControlFlag)
   {
   return MclassSaveW(FileName.c_str(), ContextClassId, ControlFlag);
   }

inline MIL_ID MFTYPE MclassRestoreW(const MIL_STRING& FileName, MIL_ID SysId, MIL_INT64 ControlFlag, MIL_ID* ContextClassId)
   {
   return MclassRestoreW(FileName.c_str(), SysId, ControlFlag, ContextClassId);
   }


#else // M_MIL_UNICODE_API
inline void MFTYPE MclassSaveA(const MIL_STRING& FileName, MIL_ID ContextClassId, MIL_INT64 ControlFlag)
   {
   return MclassSaveA(FileName.c_str(), ContextClassId, ControlFlag);
   }

inline MIL_ID MFTYPE MclassRestoreA(const MIL_STRING& FileName, MIL_ID SysId, MIL_INT64 ControlFlag, MIL_ID* ContextClassId)
   {
   return MclassRestoreA(FileName.c_str(), SysId, ControlFlag, ContextClassId);
   }

#endif /* M_MIL_UNICODE_API*/

#else // M_MIL_USE_UNICODE
inline void MFTYPE MclassSave(const MIL_STRING& FileName, MIL_ID ContextClassId, MIL_INT64 ControlFlag)
   {
   return MclassSave(FileName.c_str(), ContextClassId, ControlFlag);
   }

inline MIL_ID MFTYPE MclassRestore(const MIL_STRING& FileName, MIL_ID SysId, MIL_INT64 ControlFlag, MIL_ID* ContextClassId)
   {
   return MclassRestore(FileName.c_str(), SysId, ControlFlag, ContextClassId);
   }

#endif /* M_MIL_USE_UNICODE */                                                                                                                                          

#if M_MIL_USE_SAFE_TYPE

inline MIL_INT MFTYPE MclassInquireSafeType(MIL_ID ContextClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 InquireType, MIL_STRING &ValuePtr)
   {
#if MIL_COMPILE_VERSION >= 1060 && M_MIL_USE_SAFE_TYPE
   if((InquireType & M_CLIENT_ENCODING) != M_CLIENT_ENCODING)
      {
      SafeTypeError(MIL_TEXT("MdmrInquireFont"), MIL_TEXT("Inquire Type not supported with MIL_STRING."));
      }
#endif

   MIL_INT RetValue = 0;
   MIL_INT InternalStringSize = 0;

   MclassInquireSafeType(ContextClassId, LayerLabelOrIndex, (InquireType & (~M_HLVLDATATYPE_MASK)) + M_STRING_SIZE + M_TYPE_MIL_INT, &InternalStringSize);

   if(InternalStringSize > 0)
      {
      ValuePtr.assign(InternalStringSize, MIL_TEXT('\0'));
      RetValue = MclassInquireSafeTypeExecute(ContextClassId, LayerLabelOrIndex, InquireType, &ValuePtr[0], M_TYPE_STRING);
      ValuePtr.resize(InternalStringSize - 1);
      }

   return RetValue;
   }
#else
inline MIL_INT MFTYPE MclassInquire(MIL_ID ContextClassId, MIL_INT64 LayerLabelOrIndex, MIL_INT64 InquireType, MIL_STRING &ValuePtr)
   {
   MIL_INT RetValue = 0;
   MIL_INT InternalStringSize = 0;

   MclassInquire(ContextClassId, LayerLabelOrIndex, (InquireType & (~M_HLVLDATATYPE_MASK)) + M_STRING_SIZE + M_TYPE_MIL_INT, &InternalStringSize);

   if(InternalStringSize > 0)
      {
      ValuePtr.assign(InternalStringSize, MIL_TEXT('\0'));
      RetValue = MclassInquire(ContextClassId, LayerLabelOrIndex, InquireType, &ValuePtr[0]);
      ValuePtr.resize(InternalStringSize - 1);
      }

   return RetValue;
   }
#endif
#endif /* M_MIL_USE_STRING*/
#endif /* !M_MIL_LITE */

#endif
