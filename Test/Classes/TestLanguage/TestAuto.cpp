
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
	auto a = v[0];// a �� int �̈́e
	decltype(v[0]) b = 0;   // b �� const int& �̈́e����
	// std::vector<int>::operator[]��size_type��const �Ļط��̈́e
	auto c = 0;         // c �� int �̈́e
	auto d = c;         // d �� int �̈́e      
	decltype(c) e;      // e �� int �̈́e��c ���w���̈́e 
	decltype((c)) f = e; // f �� int& �̈́e����飨c������ֵ
	decltype(0) g;      // g��int�̈́e�����0����ֵ

__LEAVE_FUNCTION
}