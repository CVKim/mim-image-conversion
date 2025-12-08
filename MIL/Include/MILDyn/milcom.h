/////////////////////////////////////////////////////////////////
//
// Filename          :  MILCOM.H
// Content           :  Define for the Mcom module
// Revision          :  10.35.1105
//
// Copyright © Matrox Electronic Systems Ltd., 1992-2019.
// All Rights Reserved
//
/////////////////////////////////////////////////////////////////

#ifndef __MILCOM_H__
#define __MILCOM_H__

/* C++ directive if needed */
#ifdef __cplusplus
extern "C"
{
#endif

/* General milcom defines */
#define M_COM_SUCCESS                  0
#define M_COM_ERROR                    1

// Allocation control flags
#define M_NO_RXYZ_SWAP                      0x00000001
#define M_COM_NO_CONNECT                    0x00000002
#define M_COM_NO_CONNECT_NO_RXYZ_SWAP       0x00000004
#define M_COM_EMULATION                     0x00000008

/**************************************************************************/
/* McomAlloc TypeofProtocol                                               */
/**************************************************************************/
#define M_COM_PROTOCOL_PROFINET     1
#define M_COM_PROTOCOL_ETHERNETIP   2
#define M_COM_PROTOCOL_MODBUS       3
#define M_COM_PROTOCOL_EPSON        4
#define M_COM_PROTOCOL_ABB          5
#define M_COM_PROTOCOL_FANUC        6
#define M_COM_PROTOCOL_KUKA         7
#define M_COM_PROTOCOL_MOTOMAN      8
#define M_COM_PROTOCOL_DENSO        9
#define M_COM_PROTOCOL_STAUBLI      10
#define M_COM_PROTOCOL_GENERIC      11
#define M_COM_PROTOCOL_CCLINK       12
#define M_COM_PROTOCOL_OPCUA        13

/**************************************************************************/
/* McomRead/McomWrite description                                         */
/**************************************************************************/
#define M_DISCRETE_INPUT     MIL_TEXT("M_DISCRETE_INPUT")
#define M_COILS              MIL_TEXT("M_COILS")
#define M_HOLDING_REGISTER   MIL_TEXT("M_HOLDING_REGISTER")
#define M_INPUT_REGISTER     MIL_TEXT("M_INPUT_REGISTER")

#define M_COM_ETHERNETIP_PRODUCER_ID  110
#define M_COM_ETHERNETIP_PRODUCER     MIL_TEXT("110")
#define M_COM_ETHERNETIP_CONSUMER_ID  111
#define M_COM_ETHERNETIP_CONSUMER     MIL_TEXT("111")
#define M_COM_ETHERNETIP_CONFIG_ID    112
#define M_COM_ETHERNETIP_CONFIG       MIL_TEXT("112")

#define M_COM_MODBUS_PATH(id,table) MIL_TEXT(#id) MIL_TEXT("/") table
#define M_COM_MODBUS_TCP_PATH(slave,id,table) MIL_TEXT(#id) MIL_TEXT("@") MIL_TEXT(slave) MIL_TEXT("/") table
#define M_COM_ETHERNETIP_PATH(assembly) MIL_TEXT("/") MIL_TEXT(#assembly)
#define M_COM_ETHERNETIP_REMOTE_PATH(assembly, remote) MIL_TEXT(slave) MIL_TEXT("/") MIL_TEXT(#assembly)
#define M_COM_PROFINET_PATH(module) MIL_TEXT("/") MIL_TEXT(#module)

// CClink Device
#define M_COM_CCLINK_RAW                                 MIL_TEXT("RAW")
#define M_COM_CCLINK_INPUT_FLAG                          MIL_TEXT("RX")
#define M_COM_CCLINK_OUTPUT_FLAG                         MIL_TEXT("RY")
#define M_COM_CCLINK_INPUT_REGISTER                      MIL_TEXT("RWR")
#define M_COM_CCLINK_OUTPUT_REGISTER                     MIL_TEXT("RWW")

// CClink Raw mode Offset
#define M_COM_CCLINK_FORCE_READ_INPUT                    (1UL << 0)

#define M_COM_CCLINK_FLAGS_MEMORY_BANK                   (1UL << 1)
#define M_COM_CCLINK_INPUT_FLAGS_MEMORY_BANK             (M_COM_CCLINK_FLAGS_MEMORY_BANK | M_COM_CCLINK_FORCE_READ_INPUT)
#define M_COM_CCLINK_OUTPUT_FLAGS_MEMORY_BANK            (M_COM_CCLINK_FLAGS_MEMORY_BANK)

#define M_COM_CCLINK_REGISTERS_MEMORY_BANK               (1UL << 2)
#define M_COM_CCLINK_INPUT_REGISTERS_MEMORY_BANK         (M_COM_CCLINK_REGISTERS_MEMORY_BANK | M_COM_CCLINK_FORCE_READ_INPUT)
#define M_COM_CCLINK_OUTPUT_REGISTERS_MEMORY_BANK        (M_COM_CCLINK_REGISTERS_MEMORY_BANK)

/**************************************************************************/
/* Mcom control/Inquire settings                                          */
/**************************************************************************/
//General
#define M_COM_REMOTE_ADDRESS                 (2|M_CLIENT_ENCODING)
#define M_COM_REMOTE_ADDRESS_SIZE            (M_STRING_SIZE + M_COM_REMOTE_ADDRESS)
#define M_COM_REMOTE_PORT                    3

#define M_COM_PROFINET_DEVICEID              7
#define M_COM_PROFINET_GET_MODULES           8
#define M_COM_HOOK_ID                        9
#define M_COM_START                          10
#define M_COM_TIMEOUT                        11
#define M_COM_ABORT                          12
#define M_COM_PROFINET_GET_PLC_STATE         13
#define M_COM_GET_CONNECTION_STATE           14
#define M_COM_IS_HARDWARE                    15
#define M_COM_PROTOCOL_TYPE                  16
#define M_COM_DEVICE_DESCRIPTION             (17|M_CLIENT_ENCODING)
#define M_COM_DEVICE_DESCRIPTION_SIZE        (M_STRING_SIZE + M_COM_DEVICE_DESCRIPTION)
#define M_COM_INIT_VALUE                     19
#define M_COM_EMULATION_MODE                 20
#define M_COM_EMULATOR_SYNC                  21
#define M_COM_INSTANCE_NAME                  (22|M_CLIENT_ENCODING)
#define M_COM_PROTOCOL_VERSION               23
#define M_COM_INSTANCE_NAME_SIZE             (M_STRING_SIZE + M_COM_INSTANCE_NAME)

//Robot
#define M_COM_ROBOT_CONNECT                 106
#define M_COM_ROBOT_TIMEOUT                 107
#define M_COM_ROBOT_ISCONNECTED             108
#define M_COM_ROBOT_COMMAND_ABORT           109
#define M_COM_ROBOT_COMMAND_TIMEOUT         110
#define M_COM_ROBOT_DISCONNECT              111
#define M_COM_ROBOT_CONNECT_RETRY           112
#define M_COM_ROBOT_CONNECT_RETRY_WAIT      113

//Cclink
#define M_COM_CCLINK_START                   1000
#define M_COM_CCLINK_TOTAL_OCCUPIED_STATION  M_COM_CCLINK_START + 1

//Opcua - Open Platform Communications Unified Architecture
#define M_COM_OPCUA_START                   2000
#define M_COM_OPCUA_NODESET_LIST            M_COM_OPCUA_START + 1

//Ethernet/IP
#define M_COM_ETHERNETIP_START              20000
#define M_COM_ETHERNETIP_CONSUMER_SIZE      M_COM_ETHERNETIP_START + 1
#define M_COM_ETHERNETIP_PRODUCER_SIZE      M_COM_ETHERNETIP_START + 2
#define M_COM_ETHERNETIP_CONFIG_SIZE        M_COM_ETHERNETIP_START + 3
#define M_COM_ETHERNETIP_ASSEMBLY_LIST      M_COM_ETHERNETIP_START + 4

//Profinet Array
#define M_COM_PROFINET_GET_MODULE_ID             10000
#define M_COM_PROFINET_GET_MODULE_ID_RANGE       500
   //We reserve 500 ID for modules ID

#define M_COM_PROFINET_GET_SUBMODULE_ID          (M_COM_PROFINET_GET_MODULE_ID + M_COM_PROFINET_GET_MODULE_ID_RANGE)
#define M_COM_PROFINET_GET_SUBMODULE_ID_RANGE    500
   //We reserve 500 ID for modules ID

#define M_COM_PROFINET_GET_MODULE_INSIZE         (M_COM_PROFINET_GET_SUBMODULE_ID + M_COM_PROFINET_GET_SUBMODULE_ID_RANGE)
#define M_COM_PROFINET_GET_MODULE_INSIZE_RANGE   500
   //We reserve 500 ID for module IN size

#define M_COM_PROFINET_GET_MODULE_OUTSIZE        (M_COM_PROFINET_GET_MODULE_INSIZE + M_COM_PROFINET_GET_MODULE_INSIZE_RANGE)
#define M_COM_PROFINET_GET_MODULE_OUTSIZE_RANGE  500
#define M_COM_PROFINET_START                     (M_COM_PROFINET_GET_MODULE_OUTSIZE + M_COM_PROFINET_GET_MODULE_OUTSIZE_RANGE) 
#define M_COM_PROFINET_INPUT_SIZE                M_COM_PROFINET_START + 1
#define M_COM_PROFINET_OUTPUT_SIZE               M_COM_PROFINET_START + 2
   //We reserve 500 ID for module OUT size

/**************************************************************************/
/* McomControl Parameter                                                  */
/**************************************************************************/

/**************************************************************************/
/* McomInquire Parameter                                                  */
/**************************************************************************/

//Values for M_COM_PROFINET_GET_PLC_STATE
#define M_COM_PROFINET_STATUS_STOP            0x0001
#define M_COM_PROFINET_STATUS_RUN             0x0002
#define M_COM_PROFINET_STATUS_PRIMARY         0x0010
#define M_COM_PROFINET_STATUS_BACKUP          0x0020
#define M_COM_PROFINET_STATUS_STATION_OK      0x0040
/**************************************************************************/
/* McomHookFunction HookType                                              */
/**************************************************************************/
#define M_COM_ERROR_TRIGGER     4
#define M_COM_DATA_CHANGE       5

#define M_COM_GET_HOOK_INFO_SIZE   0x8000000000000000
/**************************************************************************/
/* McomGetHookInfo(), Info type                                           */
/**************************************************************************/
#define M_COM_ID                             99

#define M_COM_ERROR_NUMBER                   56
#define M_COM_PROFINET_SLOT_CHANGED_COUNT    57
#define M_COM_PROFINET_SLOT_CHANGED_LIST     58
#define M_COM_EVENT_ID                       59

#define M_COM_ERR_OFFSET                     47000L

/**************************************************************************/
/* McomQueryProtocols                                                     */
/**************************************************************************/
#define M_COM_PROTOCOL_NAME_SIZE       50
#define M_COM_PROTOCOL_TYPE_ALL        0
#define M_COM_PROTOCOL_TYPE_PLC        1
#define M_COM_PROTOCOL_TYPE_ROBOT      2

/**************************************************************************/
/* McomSendPositionXXX                                                    */
/**************************************************************************/
#define M_COM_FIND_POSITION_REQUEST          1
#define M_COM_ROBOT_FIND_POSITION_RESULT     2
#define M_COM_USER_OPCODE                    1000
/**************************************************************************/
/* Function prototypes                                                    */
/**************************************************************************/

typedef MIL_HOOK_FUNCTION_PTR MIL_COM_HOOK_FUNCTION_PTR;

#if M_MIL_USE_UNICODE
MIL_ID MFTYPE McomAllocW(MIL_ID SysId, MIL_INT64 ProtocolType, MIL_CONST_TEXTW_PTR DeviceDescription, MIL_INT64 InitFlag, MIL_INT64 InitValue, MIL_ID* ComIdPtr);
MIL_ID MFTYPE McomAllocA(MIL_ID SysId, MIL_INT64 ProtocolType, MIL_CONST_TEXTA_PTR DeviceDescription, MIL_INT64 InitFlag, MIL_INT64 InitValue, MIL_ID* ComIdPtr);
void MFTYPE McomReadW(MIL_ID ComId, MIL_CONST_TEXTW_PTR DataObjectEntryName, MIL_INT Offset, MIL_INT Size, void* UserArrayPtr);
void MFTYPE McomReadA(MIL_ID ComId, MIL_CONST_TEXTA_PTR DataObjectEntryName, MIL_INT Offset, MIL_INT Size, void* UserArrayPtr);
void MFTYPE McomWriteW(MIL_ID ComId, MIL_CONST_TEXTW_PTR DataObjectEntryName, MIL_INT Offset, MIL_INT Size, const void* UserArrayPtr);
void MFTYPE McomWriteA(MIL_ID ComId, MIL_CONST_TEXTA_PTR DataObjectEntryName, MIL_INT Offset, MIL_INT Size, const void* UserArrayPtr);
MIL_INT MFTYPE McomQueryProtocolsW(MIL_ID SystemId, MIL_INT Type, MIL_INT Version, MIL_INT Index, MIL_TEXTW_PTR Name, MIL_INT64* Id);
MIL_INT MFTYPE McomQueryProtocolsA(MIL_ID SystemId, MIL_INT Type, MIL_INT Version, MIL_INT Index, MIL_TEXTA_PTR Name, MIL_INT64* Id);
void MFTYPE McomControlText(MIL_ID ComId, MIL_INT64 ControlType, MIL_CONST_TEXT_PTR ControlValue);
void MFTYPE McomControlTextW(MIL_ID ComId, MIL_INT64 ControlType, MIL_CONST_TEXTW_PTR ControlValue);
void MFTYPE McomControlTextA(MIL_ID ComId, MIL_INT64 ControlType, MIL_CONST_TEXTA_PTR ControlValue);
#else
MIL_ID MFTYPE McomAlloc(MIL_ID SysId, MIL_INT64 ProtocolType, MIL_CONST_TEXT_PTR DeviceDescription, MIL_INT64 InitFlag, MIL_INT64 InitValue, MIL_ID* ComIdPtr);
void MFTYPE McomRead(MIL_ID ComId, MIL_CONST_TEXT_PTR DataObjectEntryName, MIL_INT Offset, MIL_INT Size, void* UserArrayPtr);
void MFTYPE McomWrite(MIL_ID ComId, MIL_CONST_TEXT_PTR DataObjectEntryName, MIL_INT Offset, MIL_INT Size, const void* UserArrayPtr);
MIL_INT MFTYPE McomQueryProtocols(MIL_ID SystemId, MIL_INT Type, MIL_INT Version, MIL_INT Index, MIL_TEXT_PTR Name, MIL_INT64* Id);
void MFTYPE McomControlText(MIL_ID ComId, MIL_INT64 ControlType, MIL_CONST_TEXT_PTR ControlValue);
#endif

#if M_MIL_USE_64BIT
// Prototypes for 64 bits OSs
void MFTYPE McomControlInt64(MIL_ID ComId,
                             MIL_INT64 ControlType,
                             MIL_INT64 ControlValue);
void MFTYPE McomControlDouble(MIL_ID ComId,
                              MIL_INT64 ControlType,
                              MIL_DOUBLE ControlValue);
#else
// Prototypes for 32 bits OSs
#define McomControlInt64  McomControl
#define McomControlDouble McomControl
void MFTYPE McomControl(MIL_ID ComId,
                        MIL_INT64 ControlType,
                        MIL_DOUBLE ControlValue);
#endif

MIL_INT MFTYPE McomInquire(MIL_ID     ComId,
                           MIL_INT64  InquireType,
                           void*      UserVarPtr);

MIL_INT MFTYPE McomHookFunction(MIL_ID ComId, MIL_INT HookType, MIL_COM_HOOK_FUNCTION_PTR HookHandlerPtr, void *UserDataPtr);

MIL_INT MFTYPE McomGetHookInfo(MIL_ID EventId, MIL_INT64 InfoType, void* UserVarPtr);

void MFTYPE McomSendPosition(MIL_ID ComId, MIL_INT64 OperationCode, MIL_INT64 Status, MIL_INT64 ObjectSpecifier, MIL_DOUBLE PositionX, MIL_DOUBLE PositionY, MIL_DOUBLE PositionZ, MIL_DOUBLE RotationX, MIL_DOUBLE RotationY, MIL_DOUBLE RotationZ, MIL_INT64 ControlFlag, MIL_DOUBLE ControlValue);
void MFTYPE McomWaitPositionRequest(MIL_ID ComId, MIL_INT64 *OperationCodePtr, MIL_INT64 *StatusPtr, MIL_INT64 *ObjectSpecifierPtr, MIL_DOUBLE *PositionXPtr, MIL_DOUBLE *PositionYPtr, MIL_DOUBLE *PositionZPtr, MIL_DOUBLE *RotationXPtr, MIL_DOUBLE *RotationYPtr, MIL_DOUBLE *RotationZPtr, MIL_INT64 ControlFlag, MIL_DOUBLE ControlValue);
void MFTYPE McomSendCommand(MIL_ID ComId, MIL_INT64 OperationCode, MIL_INT64 Status, MIL_INT64 DataSize, void* DataPtr, MIL_INT64 ControlFlag, MIL_DOUBLE ControlValue);
void MFTYPE McomReceiveCommand(MIL_ID ComId, MIL_INT64 *OperationCodePtr, MIL_INT64 *StatusPtr, MIL_INT64 ArraySize, void* ArrayPtr, MIL_INT64 *ReceivedDataSizePtr, MIL_INT64 ControlFlag, MIL_DOUBLE ControlValue);

void MFTYPE McomFree(MIL_ID ComId);

#if M_MIL_USE_UNICODE
#if M_MIL_UNICODE_API
#define McomRead         McomReadW
#define McomWrite        McomWriteW
#define McomAlloc        McomAllocW
#define McomQueryProtocols McomQueryProtocolsW
#else
#define McomRead         McomReadA
#define McomWrite        McomWriteA
#define McomAlloc        McomAllocA
#define McomQueryProtocols McomQueryProtocolsA
#undef McomControlText
#define McomControlText McomControlTextA
#endif
#endif

/* C++ directive if needed */
#ifdef __cplusplus
}
#endif

#if M_MIL_USE_64BIT
#ifdef __cplusplus
//////////////////////////////////////////////////////////////
// McomControl function definition when compiling c++ files
//////////////////////////////////////////////////////////////
#if !M_MIL_USE_LINUX
inline void McomControl(MIL_ID ComId, MIL_INT64 ControlType, int ControlValue)
   {
   McomControlInt64(ComId, ControlType, ControlValue);
   };
#endif
inline void McomControl(MIL_ID ComId, MIL_INT64 ControlType, MIL_INT32 ControlValue)
   {
   McomControlInt64(ComId, ControlType, ControlValue);
   };

inline void McomControl(MIL_ID ComId, MIL_INT64 ControlType, MIL_INT64 ControlValue)
   {
   McomControlInt64(ComId, ControlType, ControlValue);
   };

inline void McomControl(MIL_ID ComId, MIL_INT64 ControlType, MIL_DOUBLE ControlValue)
   {
   McomControlDouble(ComId, ControlType, ControlValue);
   };

inline void McomControl(MIL_ID ComId, MIL_INT64 ControlType, MIL_CONST_TEXT_PTR ControlValue)
   {
   McomControlText(ComId, ControlType, ControlValue);
   };
#else
//////////////////////////////////////////////////////////////
// For C file, call the default function, i.e. Int64 one
//////////////////////////////////////////////////////////////
#define McomControl  McomControlDouble


#endif // __cplusplus
#endif // M_MIL_USE_64BIT


#endif /* __MILCOM_H__ */
