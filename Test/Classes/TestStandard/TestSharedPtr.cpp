
#include "StdAfx.h"
#include "TestSharedPtr.h"
#include <memory>

namespace NS_TestSharedPtr
{
}

VOID TestSharedPtr::Run()
{
__ENTER_FUNCTION

	using namespace NS_TestSharedPtr;

	int* pi = new int(1);
	
	shared_ptr<int> spInt(pi);

	shared_ptr<int> spInt2 = spInt;

	if (spInt.get())
	{
		*spInt = 10;
	}

	cout<<spInt.get()<<endl;

__LEAVE_FUNCTION
}