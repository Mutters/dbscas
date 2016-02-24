#ifndef __DBS_CAS_H__
#define __DBS_CAS_H__

#include <stdlib.h>
#include "DBS_Type.h"

#if defined(_WIN32)
#define  DLL_DBSCAS_API __declspec(dllexport)
#else
#define DLL_DBSCAS_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

//Defind From CDCAS.h
#define DBS_CAS_MAXLEN_SN         16U
#define DBS_CAS_MAXNUM_ENTITLE    300U
#define DBS_CAS_OK                0
#define DBS_CAS_Failed            -1


#define DBS_CAS_RC_ERROR_BASE            -100
#define DBS_CAS_RC_OK                    0x00  /* 成功 */
#define DBS_CAS_RC_UNKNOWN               (0x01 +  DBS_CAS_RC_ERROR_BASE)  /* 未知错误 */
#define DBS_CAS_RC_POINTER_INVALID       (0x02 +  DBS_CAS_RC_ERROR_BASE)  /* 指针无效 */
#define DBS_CAS_RC_CARD_INVALID          (0x03 +  DBS_CAS_RC_ERROR_BASE)  /* 智能卡无效 */
#define DBS_CAS_RC_PIN_INVALID           (0x04 +  DBS_CAS_RC_ERROR_BASE)  /* PIN码无效 */
#define DBS_CAS_RC_DATASPACE_SMALL       (0x06 +  DBS_CAS_RC_ERROR_BASE)  /* 所给的空间不足 */
#define DBS_CAS_RC_CARD_PAIROTHER        (0x07 +  DBS_CAS_RC_ERROR_BASE)  /* 智能卡已经对应别的机顶盒 */
#define DBS_CAS_RC_DATA_NOT_FIND         (0x08 +  DBS_CAS_RC_ERROR_BASE)  /* 没有找到所要的数据 */
#define DBS_CAS_RC_PROG_STATUS_INVALID   (0x09 +  DBS_CAS_RC_ERROR_BASE)  /* 要购买的节目状态无效 */
#define DBS_CAS_RC_CARD_NO_ROOM          (0x0A +  DBS_CAS_RC_ERROR_BASE)  /* 智能卡没有空间存放购买的节目 */
#define DBS_CAS_RC_WORKTIME_INVALID      (0x0B +  DBS_CAS_RC_ERROR_BASE)  /* 设定的工作时段无效 */
#define DBS_CAS_RC_IPPV_CANNTDEL         (0x0C +  DBS_CAS_RC_ERROR_BASE)  /* IPPV节目不能被删除 */
#define DBS_CAS_RC_CARD_NOPAIR           (0x0D +  DBS_CAS_RC_ERROR_BASE)  /* 智能卡没有对应任何的机顶盒 */
#define DBS_CAS_RC_WATCHRATING_INVALID   (0x0E +  DBS_CAS_RC_ERROR_BASE)  /* 设定的观看级别无效 */
#define DBS_CAS_RC_CARD_NOTSUPPORT       (0x0F +  DBS_CAS_RC_ERROR_BASE)  /* 当前智能卡不支持此功能 */
#define DBS_CAS_RC_DATA_ERROR            (0x10 +  DBS_CAS_RC_ERROR_BASE)  /* 数据错误，智能卡拒绝 */
#define DBS_CAS_RC_FEEDTIME_NOT_ARRIVE   (0x11 +  DBS_CAS_RC_ERROR_BASE)  /* 喂养时间未到，子卡不能被喂养 */
#define DBS_CAS_RC_CARD_TYPEERROR        (0x12 +  DBS_CAS_RC_ERROR_BASE)  /* 子母卡喂养失败，插入智能卡类型错误 */

#define DBS_CAS_RC_CAS_FAILED                  (0x20 +  DBS_CAS_RC_ERROR_BASE) //发卡cas指令执行失败
#define DBS_CAS_RC_OPER_FAILED                (0x21 +  DBS_CAS_RC_ERROR_BASE) //发卡运营商指令执行失败



/*---------- PVODDRM功能调用返回值定义 ----------*/
#define DBS_CAS_RC_FILE_ERROR            (0x30 +  DBS_CAS_RC_ERROR_BASE)  /* 文件错误 */
#define DBS_CAS_RC_FILE_EOF              (0x31 +  DBS_CAS_RC_ERROR_BASE)  /* 文件结束 */
#define DBS_CAS_RC_NOENTITLE             (0x32 +  DBS_CAS_RC_ERROR_BASE)  /* 没有授权 */
#define DBS_CAS_RC_NOT_ISSUETIME         (0x33 +  DBS_CAS_RC_ERROR_BASE)  /* 没有授权(不满足发行时间) */
#define DBS_CAS_RC_NOT_WATCHTIME         (0x34 +  DBS_CAS_RC_ERROR_BASE)  /* 没有授权(不满足观看时间) */
#define DBS_CAS_RC_RIGHT_LIMIT           (0x35 +  DBS_CAS_RC_ERROR_BASE)  /* 没有授权(超出版权限量值) */
#define DBS_CAS_RC_NOTENOUGHMONEY        (0x36 +  DBS_CAS_RC_ERROR_BASE)  /* 没有授权(卡内金额不足) */
#define DBS_CAS_RC_PREVIEWOVER           (0x37 +  DBS_CAS_RC_ERROR_BASE)  /* 没有授权(超出预览范围) */
#define DBS_CAS_RC_CLEARDATA             (0x38 +  DBS_CAS_RC_ERROR_BASE)  /* 没有授权节目，但片头可以预览 */
#define DBS_CAS_RC_NEEDSELECT_ENTITLE    (0x39 +  DBS_CAS_RC_ERROR_BASE)  /* 本节目目前都是限制流量授权，需用户选择授权打开文件 */
#define DBS_CAS_RC_SAVEDATA_ERROR        (0x3A +  DBS_CAS_RC_ERROR_BASE)  /* 保存授权数据错误 */
#define DBS_CAS_RC_NOENTITLEDATA         (0x3B +  DBS_CAS_RC_ERROR_BASE)  /* 没有找到授权文件 */
#define DBS_CAS_RC_SYSTEMERR             (0x3C +  DBS_CAS_RC_ERROR_BASE)  /* 终端系统错误 */
#define DBS_CAS_RC_BUFFEROVERFLOW        (0x3D +  DBS_CAS_RC_ERROR_BASE)  /* 缓冲区长度太小 */
#define DBS_CAS_RC_CRC_ERROR             (0x3E +  DBS_CAS_RC_ERROR_BASE)  /* CRC校验错误 */ 
#define DBS_CAS_RC_IN_SYNC               (0x3F +  DBS_CAS_RC_ERROR_BASE)  /* 同步授权中 */
#define DBS_CAS_RC_NOCALIBOPER_TYPE      (0x42 +  DBS_CAS_RC_ERROR_BASE)  /* 卡中不存在移植库定制运营商-add by rw  20120524 */

#define DBS_CAS_RC_NONEEDPATCH           (0x50 +  DBS_CAS_RC_ERROR_BASE)  /* 智能卡已经是目标版本，无需升级 */
#define DBS_CAS_RC_NOPATCHKEY            (0x51 +  DBS_CAS_RC_ERROR_BASE)  /* 卡中不存在Patch Key */




typedef enum {
  // seek from start of file.
  DBS_FILE_SEEK_START,
  // seek from current position in the file.
  DBS_FILE_SEEK_CURRENT,
  // seek from end of file.
  DBS_FILE_SEEK_END,
} DBS_FileSeekPos;

typedef enum
{
  DBS_CARD_IN,
  DBS_CARD_OUT,
  DBS_CARD_INVERSE,
  DBS_CARD_CHECKING,
  DBS_CARD_BUSY,
  DBS_CARD_ERROR
} DBS_CasSmasrCardStatus;

typedef DBS_Int32   DBS_CASResult;
typedef DBS_Int32   DBS_CasDrmFileHandle;
typedef DBS_UInt32  DBS_CA_TIME;
typedef DBS_UInt16  DBS_CA_DATE;

typedef void(*DBS_CasEventNotify)(DBS_CasSmasrCardStatus event, void *pEventBody);

typedef struct {
  DBS_UInt16   m_OperatorID;     /* 运营商ID */
  DBS_UInt32   m_ID;              /* 授权的产品ID，0表示无效或者没有 */
  DBS_CA_TIME  m_ProductStartTime;  /* 发行开始时间，注：0表示在终端购买时，由用户输入开始时间  */
  DBS_CA_TIME  m_ProductEndTime;    /* 发行结束时间，注：由用户输入开始时间时，此值表示时间周期 */
                                /* 当产品是节目包时，发行时间范围决定了属于这个产品的哪些节目允许用户观看 */

  DBS_CA_TIME  m_WatchStartTime;  /* 观看开始时间，注：0表示在终端购买时，由用户输入开始时间  */
  DBS_CA_TIME  m_WatchEndTime;    /* 观看结束时间，注：由用户输入开始时间时，此值表示时间周期 */
  DBS_UInt32   m_LimitTotaltValue;/* 限量总值，0表示不限量 */
  DBS_UInt32   m_LimitUsedValue;  /* 限量已用值 */

} DBS_CasEntitleInfo;

typedef struct {
  char* workPath;
} DBS_CasInitParams;

typedef struct vidon_file_h VIDON_FILE_H;

struct vidon_file_h
{
  void (*close)(VIDON_FILE_H* file);
  DBS_Int64 (*seek)(VIDON_FILE_H* file, DBS_Int64 offset, DBS_FileSeekPos whence);
  DBS_Int64 (*read)(VIDON_FILE_H* file, DBS_UInt8* buf, DBS_Int64 size);
  DBS_Int64 (*write)(VIDON_FILE_H* file, const DBS_UInt8* buf, DBS_Int64 size);
  
  //reserved 
  void* client;
  void* internal;

  //add
  char* data;
  char* data_begin;
  DBS_Int64 data_length;
  DBS_Int64 data_pos;
};

typedef VIDON_FILE_H* (*VIDON_FILE_OPEN)(const char* filename, const char* mode, void* client);

/*cas 版本号*/
DLL_DBSCAS_API DBS_CASResult DBS_CAS_GetVersion();

/*cas 初始化*/
DLL_DBSCAS_API DBS_CASResult DBS_CAS_Init(DBS_CasInitParams* pInitParams);

/*cas 反始化*/
DLL_DBSCAS_API DBS_CASResult DBS_CAS_Uninit();

/*cas 获取智能卡状态*/
DLL_DBSCAS_API DBS_CASResult DBS_CAS_GetCardStatus(DBS_CasSmasrCardStatus * pStatus);

/*cas 获取智能卡SN*/
DLL_DBSCAS_API DBS_CASResult DBS_CAS_GetCardSN(char *pSN);//DBS_CAS_MAXLEN_SN

/*cas 获取授权数量*/
DLL_DBSCAS_API DBS_Int32 DBS_CAS_GetEntitleInfoCount();

/*cas 获取授权信息*/
DLL_DBSCAS_API DBS_CASResult DBS_CAS_GetEntitleInfos(DBS_CasEntitleInfo* pEntitles, DBS_UInt32* num);//DBS_CAS_MAXNUM_ENTITLE

/*注册cas 事件槽函数*/
DLL_DBSCAS_API DBS_UInt32 DBS_CAS_RegisterEventNotify(DBS_CasEventNotify notify);

/* 打开节目文件 */
DLL_DBSCAS_API DBS_CasDrmFileHandle* DBS_CAS_DRM_OpenFile(const char* pFile, const char* pKeyFile, void *client);

/* 关闭节目文件 */
DLL_DBSCAS_API DBS_CASResult DBS_CAS_DRM_CloseFile(DBS_CasDrmFileHandle* pHandle);

/* 文件定位 */
DLL_DBSCAS_API DBS_CASResult DBS_CAS_DRM_SeekFile(DBS_CasDrmFileHandle* pHandle, DBS_Int64	*pPostion, DBS_FileSeekPos whence);

/*读取文件数据*/
DLL_DBSCAS_API DBS_Int32 DBS_CAS_DRM_ReadFile(DBS_CasDrmFileHandle* pHandle, DBS_UInt8 *pBuffer,  DBS_UInt32 size);


/*注册VIDON File IO*/
DLL_DBSCAS_API DBS_CASResult DBS_CAS_DRM_Regist_File(VIDON_FILE_OPEN pf);

#ifdef __cplusplus
}
#endif

#endif /* __DBS_CAS_H__ */
