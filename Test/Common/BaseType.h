#ifndef __BASETYPE_H__
#define __BASETYPE_H__

#include <string>

#define TRUE 1
#define FALSE 0

#define VOID void
typedef char					CHAR;
typedef unsigned char			BYTE;
typedef int						BOOL;
typedef short					SHORT;
typedef unsigned short			USHORT;
typedef int						INT;
typedef unsigned int			UINT;
typedef float					FLOAT;
typedef long					LONG;
typedef unsigned long			ULONG;
typedef double					DOUBLE;

typedef long long				INT64;
typedef unsigned long long		UINT64;

typedef std::string				STRING;


#define INVALID_ID				(-1)
#define INVALID_INDEX			(-1)

#define INVALID_TIME			(-1)		// 无效的时间值

#endif // __BASETYPE_H__