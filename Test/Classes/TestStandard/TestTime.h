#ifndef __TESTTIME_H__
#define __TESTTIME_H__

#include "Test.h"

// 测试时间

class TestTime : public Test
{
public:

	CLASS_NAME_DESC(TestTime, "测试时间");

	virtual VOID Run();
};

#endif // __TESTTIME_H__