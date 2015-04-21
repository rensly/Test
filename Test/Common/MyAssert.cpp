
#include "StdAfx.h"
#include "MyAssert.h"

#ifdef WIN32
#include <windows.h>
#else

#endif

VOID MyError( const CHAR *pFile, LONG nLine, const CHAR *pFunc, const CHAR *pCond, const CHAR *pMsg )
{
	const int MAX_LEN = 8192;
	char szBuf[MAX_LEN];
	sprintf( szBuf,
		"FILE:[%s]"
		"\n"
		"LINE:[%d]"
		"\n"
		"FUNC:[%s]"
		"\n"
		"C:[%s]"
		"E:[%s]",
		pFile,
		nLine,
		pFunc,
		pCond,
		pMsg
		);

#ifdef WIN32
	MessageBoxA( NULL, szBuf, "MyError", MB_OK );
#else
	// 其他平台下
#endif

	throw std::string( pMsg );
}

VOID MyAssert( const CHAR *pFile, LONG nLine, const CHAR *pFunc, const CHAR *pCond, const CHAR *pFormat, ... )
{
	const int MAX_LEN = 8192;
	char szBuf[MAX_LEN];
	va_list ap;
	va_start( ap, pFormat );
	vsnprintf( szBuf, MAX_LEN, pFormat, ap );
	va_end( ap );

	return MyError( pFile, nLine, pFunc, pCond, szBuf );
}