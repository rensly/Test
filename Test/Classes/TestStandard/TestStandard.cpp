
#include "StdAfx.h"
#include "TestStandard.h"

VOID TestStandard::Run()
{
__ENTER_FUNCTION

	set<int> setValue;
	setValue.insert(1);
	setValue.insert(2);
	setValue.insert(3);

	while( setValue.size() > 0 )
	{
		setValue.erase( *--setValue.end() );
	}

	//////////////////////////////////////////////////////////////////////////
//	char szBuff[512];
//	char szBuff2[512];
//	sscanf("123 456", "%*s%s", szBuff);
//	printf(szBuff);
	//////////////////////////////////////////////////////////////////////////

	string strText = "Test123";

	//////////////////////////////////////////////////////////////////////////
	// ´óÐ¡Ð´×ª»»
	char szText[32] = "Test213";

	cout<<szText<<endl;

	strlwr(szText);

	cout<<"strlwr(szText):"<<szText<<endl;

	strupr(szText);

	cout<<"strupr(szText):"<<szText<<endl;

__LEAVE_FUNCTION
}