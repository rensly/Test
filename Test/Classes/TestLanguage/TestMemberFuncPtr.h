#ifndef __TESTMEMBERFUNCPTR_H__
#define __TESTMEMBERFUNCPTR_H__

#include "Test.h"

// 测试虚函数

class TestMemberFuncPtr : public Test
{
public:

	CLASS_NAME_DESC(TestMemberFuncPtr, "测试成员函数指针");

	virtual VOID Run();
};

#endif // __TESTMEMBERFUNCPTR_H__
