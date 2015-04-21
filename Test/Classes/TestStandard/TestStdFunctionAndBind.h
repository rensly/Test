#ifndef __TESTSTDFUNCTIONANDBIND_H__
#define __TESTSTDFUNCTIONANDBIND_H__

#include "Test.h"

// 测试std::function与std::bind函数指针

class TestStdFunctionAndBind : public Test
{
public:

	CLASS_NAME_DESC(TestStdFunctionAndBind, "测试std::function与std::bind函数指针");

	virtual VOID Run();
};

#endif // __TESTSTDFUNCTIONANDBIND_H__