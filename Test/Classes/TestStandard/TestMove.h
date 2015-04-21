#ifndef __TESTMOVEREF_H__
#define __TESTMOVEREF_H__

#include "Test.h"

// 测试右值引用

class TestMove : public Test
{
public:

	CLASS_NAME_DESC(TestMove, "测试右值引用");

	virtual VOID Run();
};


#endif // __TESTMOVEREF_H__
