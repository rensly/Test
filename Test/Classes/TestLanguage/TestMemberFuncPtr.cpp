
#include "StdAfx.h"
#include "TestMemberFuncPtr.h"

namespace NS_TestMemberFuncPtr
{
	class Class0
	{
	public:
		void Func()
		{
			cout<<"Func"<<endl;
		}
// 		virtual void VirtualFunc()
// 		{
// 			cout<<"VirtualFunc"<<endl;
// 		}
	};
}

VOID TestMemberFuncPtr::Run()
{
__ENTER_FUNCTION

	using namespace NS_TestMemberFuncPtr;

	typedef void (Class0::*pMFunc)();

	Class0 c;

	pMFunc mfunc = &Class0::Func;

	cout<<mfunc<<endl;

	(c.*mfunc)();

__LEAVE_FUNCTION
}