
#include "StdAfx.h"
#include "TestStdFunctionAndBind.h"
#include <functional>

namespace NS_TestStdFunctionAndBind
{
	int GFunc(int i)
	{
		cout<<"GFunc"<<endl;
		return 0;
	}
	class Class0
	{
	public:
		int Func(int i)
		{
			cout<<"Class0::Func"<<endl;
			return 0;
		}
	};
}

VOID TestStdFunctionAndBind::Run()
{
__ENTER_FUNCTION

	using namespace NS_TestStdFunctionAndBind;

	Class0 c0;

	auto func0 = std::bind(&Class0::Func, &c0, std::placeholders::_1);

	func0(0);

	std::function<int(int)> func1 = std::bind(&Class0::Func, &c0, std::placeholders::_1);

	func1(11);

	std::function<int(int)> func2 = std::function<int(int)>(GFunc);

	func2(22);


__LEAVE_FUNCTION
}