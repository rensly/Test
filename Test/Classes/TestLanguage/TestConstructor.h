#ifndef __TESTCONSTRUCTOR_H__
#define __TESTCONSTRUCTOR_H__

#include "Test.h"

// 测试构造

class TestConstructor : public Test
{
public:

	CLASS_NAME_DESC(TestConstructor, "测试构造");

	virtual VOID Run();
};

#endif // __TESTCONSTRUCTOR_H__
