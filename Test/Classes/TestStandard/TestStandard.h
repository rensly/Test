#ifndef __TESTSTANDARD_H__
#define __TESTSTANDARD_H__

#include "Test.h"

// 测试标准库

class TestStandard : public Test
{
public:

	CLASS_NAME_DESC(TestStandard, "测试标准库");

	virtual VOID Run();
};

#endif // __TESTSTANDARD_H__