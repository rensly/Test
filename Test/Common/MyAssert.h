#ifndef __MYASSERT_H__
#define __MYASSERT_H__

extern VOID MyAssert( const CHAR *pFile, LONG nLine, const CHAR *pFunc, const CHAR *pCond, const CHAR *pFormat, ... );
#define Assert(cond)				(cond) ? ((VOID)0) : MyAssert(__MY_FILE__,__MY_LINE__,__MY_FUNCTION__,#cond,"");
#define AssertEx(cond, format, ...)	(cond) ? ((VOID)0) : MyAssert(__MY_FILE__,__MY_LINE__,__MY_FUNCTION__,#cond,format,##__VA_ARGS__);

#endif // __MYASSERT_H__