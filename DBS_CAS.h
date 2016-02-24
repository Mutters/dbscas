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
#define DBS_CAS_RC_OK                    0x00  /* �ɹ� */
#define DBS_CAS_RC_UNKNOWN               (0x01 +  DBS_CAS_RC_ERROR_BASE)  /* δ֪���� */
#define DBS_CAS_RC_POINTER_INVALID       (0x02 +  DBS_CAS_RC_ERROR_BASE)  /* ָ����Ч */
#define DBS_CAS_RC_CARD_INVALID          (0x03 +  DBS_CAS_RC_ERROR_BASE)  /* ���ܿ���Ч */
#define DBS_CAS_RC_PIN_INVALID           (0x04 +  DBS_CAS_RC_ERROR_BASE)  /* PIN����Ч */
#define DBS_CAS_RC_DATASPACE_SMALL       (0x06 +  DBS_CAS_RC_ERROR_BASE)  /* �����Ŀռ䲻�� */
#define DBS_CAS_RC_CARD_PAIROTHER        (0x07 +  DBS_CAS_RC_ERROR_BASE)  /* ���ܿ��Ѿ���Ӧ��Ļ����� */
#define DBS_CAS_RC_DATA_NOT_FIND         (0x08 +  DBS_CAS_RC_ERROR_BASE)  /* û���ҵ���Ҫ������ */
#define DBS_CAS_RC_PROG_STATUS_INVALID   (0x09 +  DBS_CAS_RC_ERROR_BASE)  /* Ҫ����Ľ�Ŀ״̬��Ч */
#define DBS_CAS_RC_CARD_NO_ROOM          (0x0A +  DBS_CAS_RC_ERROR_BASE)  /* ���ܿ�û�пռ��Ź���Ľ�Ŀ */
#define DBS_CAS_RC_WORKTIME_INVALID      (0x0B +  DBS_CAS_RC_ERROR_BASE)  /* �趨�Ĺ���ʱ����Ч */
#define DBS_CAS_RC_IPPV_CANNTDEL         (0x0C +  DBS_CAS_RC_ERROR_BASE)  /* IPPV��Ŀ���ܱ�ɾ�� */
#define DBS_CAS_RC_CARD_NOPAIR           (0x0D +  DBS_CAS_RC_ERROR_BASE)  /* ���ܿ�û�ж�Ӧ�κεĻ����� */
#define DBS_CAS_RC_WATCHRATING_INVALID   (0x0E +  DBS_CAS_RC_ERROR_BASE)  /* �趨�Ĺۿ�������Ч */
#define DBS_CAS_RC_CARD_NOTSUPPORT       (0x0F +  DBS_CAS_RC_ERROR_BASE)  /* ��ǰ���ܿ���֧�ִ˹��� */
#define DBS_CAS_RC_DATA_ERROR            (0x10 +  DBS_CAS_RC_ERROR_BASE)  /* ���ݴ������ܿ��ܾ� */
#define DBS_CAS_RC_FEEDTIME_NOT_ARRIVE   (0x11 +  DBS_CAS_RC_ERROR_BASE)  /* ι��ʱ��δ�����ӿ����ܱ�ι�� */
#define DBS_CAS_RC_CARD_TYPEERROR        (0x12 +  DBS_CAS_RC_ERROR_BASE)  /* ��ĸ��ι��ʧ�ܣ��������ܿ����ʹ��� */

#define DBS_CAS_RC_CAS_FAILED                  (0x20 +  DBS_CAS_RC_ERROR_BASE) //����casָ��ִ��ʧ��
#define DBS_CAS_RC_OPER_FAILED                (0x21 +  DBS_CAS_RC_ERROR_BASE) //������Ӫ��ָ��ִ��ʧ��



/*---------- PVODDRM���ܵ��÷���ֵ���� ----------*/
#define DBS_CAS_RC_FILE_ERROR            (0x30 +  DBS_CAS_RC_ERROR_BASE)  /* �ļ����� */
#define DBS_CAS_RC_FILE_EOF              (0x31 +  DBS_CAS_RC_ERROR_BASE)  /* �ļ����� */
#define DBS_CAS_RC_NOENTITLE             (0x32 +  DBS_CAS_RC_ERROR_BASE)  /* û����Ȩ */
#define DBS_CAS_RC_NOT_ISSUETIME         (0x33 +  DBS_CAS_RC_ERROR_BASE)  /* û����Ȩ(�����㷢��ʱ��) */
#define DBS_CAS_RC_NOT_WATCHTIME         (0x34 +  DBS_CAS_RC_ERROR_BASE)  /* û����Ȩ(������ۿ�ʱ��) */
#define DBS_CAS_RC_RIGHT_LIMIT           (0x35 +  DBS_CAS_RC_ERROR_BASE)  /* û����Ȩ(������Ȩ����ֵ) */
#define DBS_CAS_RC_NOTENOUGHMONEY        (0x36 +  DBS_CAS_RC_ERROR_BASE)  /* û����Ȩ(���ڽ���) */
#define DBS_CAS_RC_PREVIEWOVER           (0x37 +  DBS_CAS_RC_ERROR_BASE)  /* û����Ȩ(����Ԥ����Χ) */
#define DBS_CAS_RC_CLEARDATA             (0x38 +  DBS_CAS_RC_ERROR_BASE)  /* û����Ȩ��Ŀ����Ƭͷ����Ԥ�� */
#define DBS_CAS_RC_NEEDSELECT_ENTITLE    (0x39 +  DBS_CAS_RC_ERROR_BASE)  /* ����ĿĿǰ��������������Ȩ�����û�ѡ����Ȩ���ļ� */
#define DBS_CAS_RC_SAVEDATA_ERROR        (0x3A +  DBS_CAS_RC_ERROR_BASE)  /* ������Ȩ���ݴ��� */
#define DBS_CAS_RC_NOENTITLEDATA         (0x3B +  DBS_CAS_RC_ERROR_BASE)  /* û���ҵ���Ȩ�ļ� */
#define DBS_CAS_RC_SYSTEMERR             (0x3C +  DBS_CAS_RC_ERROR_BASE)  /* �ն�ϵͳ���� */
#define DBS_CAS_RC_BUFFEROVERFLOW        (0x3D +  DBS_CAS_RC_ERROR_BASE)  /* ����������̫С */
#define DBS_CAS_RC_CRC_ERROR             (0x3E +  DBS_CAS_RC_ERROR_BASE)  /* CRCУ����� */ 
#define DBS_CAS_RC_IN_SYNC               (0x3F +  DBS_CAS_RC_ERROR_BASE)  /* ͬ����Ȩ�� */
#define DBS_CAS_RC_NOCALIBOPER_TYPE      (0x42 +  DBS_CAS_RC_ERROR_BASE)  /* ���в�������ֲ�ⶨ����Ӫ��-add by rw  20120524 */

#define DBS_CAS_RC_NONEEDPATCH           (0x50 +  DBS_CAS_RC_ERROR_BASE)  /* ���ܿ��Ѿ���Ŀ��汾���������� */
#define DBS_CAS_RC_NOPATCHKEY            (0x51 +  DBS_CAS_RC_ERROR_BASE)  /* ���в�����Patch Key */




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
  DBS_UInt16   m_OperatorID;     /* ��Ӫ��ID */
  DBS_UInt32   m_ID;              /* ��Ȩ�Ĳ�ƷID��0��ʾ��Ч����û�� */
  DBS_CA_TIME  m_ProductStartTime;  /* ���п�ʼʱ�䣬ע��0��ʾ���ն˹���ʱ�����û����뿪ʼʱ��  */
  DBS_CA_TIME  m_ProductEndTime;    /* ���н���ʱ�䣬ע�����û����뿪ʼʱ��ʱ����ֵ��ʾʱ������ */
                                /* ����Ʒ�ǽ�Ŀ��ʱ������ʱ�䷶Χ���������������Ʒ����Щ��Ŀ�����û��ۿ� */

  DBS_CA_TIME  m_WatchStartTime;  /* �ۿ���ʼʱ�䣬ע��0��ʾ���ն˹���ʱ�����û����뿪ʼʱ��  */
  DBS_CA_TIME  m_WatchEndTime;    /* �ۿ�����ʱ�䣬ע�����û����뿪ʼʱ��ʱ����ֵ��ʾʱ������ */
  DBS_UInt32   m_LimitTotaltValue;/* ������ֵ��0��ʾ������ */
  DBS_UInt32   m_LimitUsedValue;  /* ��������ֵ */

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

/*cas �汾��*/
DLL_DBSCAS_API DBS_CASResult DBS_CAS_GetVersion();

/*cas ��ʼ��*/
DLL_DBSCAS_API DBS_CASResult DBS_CAS_Init(DBS_CasInitParams* pInitParams);

/*cas ��ʼ��*/
DLL_DBSCAS_API DBS_CASResult DBS_CAS_Uninit();

/*cas ��ȡ���ܿ�״̬*/
DLL_DBSCAS_API DBS_CASResult DBS_CAS_GetCardStatus(DBS_CasSmasrCardStatus * pStatus);

/*cas ��ȡ���ܿ�SN*/
DLL_DBSCAS_API DBS_CASResult DBS_CAS_GetCardSN(char *pSN);//DBS_CAS_MAXLEN_SN

/*cas ��ȡ��Ȩ����*/
DLL_DBSCAS_API DBS_Int32 DBS_CAS_GetEntitleInfoCount();

/*cas ��ȡ��Ȩ��Ϣ*/
DLL_DBSCAS_API DBS_CASResult DBS_CAS_GetEntitleInfos(DBS_CasEntitleInfo* pEntitles, DBS_UInt32* num);//DBS_CAS_MAXNUM_ENTITLE

/*ע��cas �¼��ۺ���*/
DLL_DBSCAS_API DBS_UInt32 DBS_CAS_RegisterEventNotify(DBS_CasEventNotify notify);

/* �򿪽�Ŀ�ļ� */
DLL_DBSCAS_API DBS_CasDrmFileHandle* DBS_CAS_DRM_OpenFile(const char* pFile, const char* pKeyFile, void *client);

/* �رս�Ŀ�ļ� */
DLL_DBSCAS_API DBS_CASResult DBS_CAS_DRM_CloseFile(DBS_CasDrmFileHandle* pHandle);

/* �ļ���λ */
DLL_DBSCAS_API DBS_CASResult DBS_CAS_DRM_SeekFile(DBS_CasDrmFileHandle* pHandle, DBS_Int64	*pPostion, DBS_FileSeekPos whence);

/*��ȡ�ļ�����*/
DLL_DBSCAS_API DBS_Int32 DBS_CAS_DRM_ReadFile(DBS_CasDrmFileHandle* pHandle, DBS_UInt8 *pBuffer,  DBS_UInt32 size);


/*ע��VIDON File IO*/
DLL_DBSCAS_API DBS_CASResult DBS_CAS_DRM_Regist_File(VIDON_FILE_OPEN pf);

#ifdef __cplusplus
}
#endif

#endif /* __DBS_CAS_H__ */
