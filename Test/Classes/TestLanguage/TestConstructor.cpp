
#include "StdAfx.h"
#include "TestConstructor.h"

namespace NS_TestConstructor
{
	class Class0
	{
	public:
		Class0(int i, int i2)
			:m_nNumber(i)
		{
		}
		~Class0()
		{

		}
	public:
		void Print()
		{
			cout << m_nNumber << endl;
		}
		int GetNumber()
		{
			return m_nNumber;
		}
	public:
		int m_nNumber = 1;
	};

	class Class1
	{
	public:
		Class1(int i)
			:m_nNumber0(i)
			,m_strText0("string 0")
		{
		}
	protected:
	private:
		int		m_nNumber0 = 10;
		int		m_nNumber1 = m_c.GetNumber();
		string	m_strText0 = "string default value";
		string	m_strText1 = m_strText0;
		Class0	m_c = { m_nNumber0, m_nNumber1 };
	};
}

VOID TestConstructor::Run()
{
__ENTER_FUNCTION

	using namespace NS_TestConstructor;

	Class1 c(20);
	
	cout << "..." << endl;


__LEAVE_FUNCTION
}