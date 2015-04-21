#ifndef __TYPE_H__
#define __TYPE_H__

#include "BaseType.h"
#include "MyAssert.h"

#ifdef WIN32
#define __MY_FILE__ __FILE__
#define __MY_LINE__ __LINE__
#define __MY_FUNCTION__ __FUNCTION__
#else
#define __MY_FILE__ __FILE__
#define __MY_LINE__ __LINE__
#define __MY_FUNCTION__ __FUNCTION__
#endif

#define Assert(cond)				(cond) ? ((VOID)0) : MyAssert(__MY_FILE__,__MY_LINE__,__MY_FUNCTION__,#cond,"");
#define AssertEx(cond, format, ...)	(cond) ? ((VOID)0) : MyAssert(__MY_FILE__,__MY_LINE__,__MY_FUNCTION__,#cond,format,##__VA_ARGS__);

#define __MY_TRY try
#define __MY_CATCH catch(...)
#define __MY_THROW(t) throw(t);

#define __ENTER_FUNCTION try {
#define __LEAVE_FUNCTION } catch(...) { Assert(FALSE); }

//根据指针值删除内存
#ifndef SAFE_DELETE
#define SAFE_DELETE(x)	if( (x)!=NULL ) { delete (x); (x)=NULL; }
#endif
//根据指针值删除数组类型内存
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(x)	if( (x)!=NULL ) { delete[] (x); (x)=NULL; }
#endif
//根据指针调用free接口
#ifndef SAFE_FREE
#define SAFE_FREE(x)	if( (x)!=NULL ) { free(x); (x)=NULL; }
#endif
//根据指针调用Release接口
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(x)	if( (x)!=NULL ) { (x)->Release(); (x)=NULL; }
#endif

#endif // __TYPE_H__