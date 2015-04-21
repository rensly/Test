
#include "StdAfx.h"
#include "TestCommon.h"
#include <limits>

VOID TestCommon::Run()
{
__ENTER_FUNCTION

	char szText[256] = "";

	double f64bit = LLONG_MAX;
	sprintf(szText, "f64bit:%f", f64bit);
	printf("%s\n", szText);

	float f32bit = LONG_MAX;
	sprintf(szText, "f32bit:%f", f32bit);
	printf("%s\n", szText);

	sprintf(szText, "f64bit:%f f32bit:%f", f64bit, f32bit);
	printf("%s\n", szText);

	sprintf(szText, "f32bit:%f f64bit:%f", f32bit, f64bit);
	printf("%s\n", szText);

	//////////////////////////////////////////////////////////////////////////
	char *pNewChar = (char*)malloc(0);
	free(pNewChar);

	//////////////////////////////////////////////////////////////////////////
	if ( int i = 1234567890 )
	{
		const unsigned int uLength = 11;
		char szText[uLength];
		_snprintf(szText, uLength, "%d", i);
		cout<<szText<<endl;
	}


	char szLogBuf[512] = "1 \n 2 3";

	//////////////////////////////////////////////////////////////////////////
	char *pTempBuf = szLogBuf;
	do 
	{// °Ñ¿Õ¸ñ,»»ÐÐÌæ»»µô
		if ( *pTempBuf == 0x20 || *pTempBuf == '\n' )
		{
			*pTempBuf = '_';
		}
	} while ( *pTempBuf++ != '\0' );
	//////////////////////////////////////////////////////////////////////////

	cout<<szLogBuf<<endl;

__LEAVE_FUNCTION
}