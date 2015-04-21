
#include "StdAfx.h"
#include "TestParameters.h"

namespace NS_TestParameters
{
	class _TestParameters
	{
	public:
		_TestParameters()
		{
			m_uID = s_uCount++;
			PrintID();
		}

		_TestParameters( const _TestParameters &other )
		{
			m_uID = s_uCount++;
			PrintID();
		}

		~_TestParameters()
		{
			PrintID();
		}

		VOID PrintID()
		{
			cout<<"m_uID:"<<m_uID<<endl;
		}

	private:
		static UINT s_uCount;
		UINT m_uID;
	};

	UINT _TestParameters::s_uCount = 0;

	VOID TestFunc( _TestParameters tTest )
	{

	}

	string getTextString()
	{
		static int i = 0;
		char szText[32] = {0};
		sprintf(szText, "%d", i++);
		return szText;
	}

	VOID TestCStringFunc( const char *pszContent )
	{
		cout<<"pszContent:"<<pszContent<<endl;
	}

	VOID TestStringFunc( string *pStr, string *pStr2 )
	{
		cout<<*pStr<<endl;
	}
}

VOID TestParameters::Run()
{
__ENTER_FUNCTION

	using namespace NS_TestParameters;

	_TestParameters tTest;
	TestFunc(tTest);

	TestCStringFunc( getTextString().c_str() );

	TestStringFunc( &getTextString(), &getTextString() );

__LEAVE_FUNCTION
}