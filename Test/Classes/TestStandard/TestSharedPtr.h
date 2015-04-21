#ifndef __TESTSHAREDPTR_H__
#define __TESTSHAREDPTR_H__

#include "Test.h"

// 测试时间

class TestSharedPtr : public Test
{
public:

	CLASS_NAME_DESC(TestSharedPtr, "测试共享指针");

	virtual VOID Run();
};

#endif // __TESTSHAREDPTR_H__