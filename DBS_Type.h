#ifndef __DBSTYPE_H__
#define __DBSTYPE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef long long          DBS_Int64;
typedef unsigned long long DBS_UInt64;
typedef unsigned int       DBS_UInt32;
typedef int                DBS_Int32;
typedef unsigned short     DBS_UInt16;
typedef short              DBS_Int16;
typedef unsigned char      DBS_UInt8;
typedef char               DBS_Int8;
typedef float              DBS_Float;
typedef int                DBS_Bool;

#define DBS_TRUE  1
#define DBS_FALSE 0

#ifdef __cplusplus
}
#endif

#endif
