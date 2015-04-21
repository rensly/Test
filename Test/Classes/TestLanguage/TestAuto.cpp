
#include "StdAfx.h"
#include "TestAuto.h"

VOID TestAuto::Run()
{
__ENTER_FUNCTION

	vector<int> vecInt;
	vecInt.push_back(0);
	vecInt.push_back(1);
	vecInt.push_back(2);
	for (auto i : vecInt)
	{
		i += 1;
		cout << i << endl;
	}
	for (auto it = vecInt.begin(); it != vecInt.end(); ++it)
	{
		auto i = *it;
		i += 1;
		cout << i << endl;
	}
	for (decltype(*vecInt.begin()) i : vecInt)
	{
		i += 1;
		cout << i << endl;
	}

	const std::vector<int> v(1);
	auto a = v[0];// a 為 int 型別
	decltype(v[0]) b = 0;   // b 為 const int& 型別，即
	// std::vector<int>::operator[]（size_type）const 的回返型別
	auto c = 0;         // c 為 int 型別
	auto d = c;         // d 為 int 型別      
	decltype(c) e;      // e 為 int 型別，c 實體的型別 
	decltype((c)) f = e; // f 為 int& 型別，因為（c）是左值
	decltype(0) g;      // g為int型別，因為0是右值

__LEAVE_FUNCTION
}