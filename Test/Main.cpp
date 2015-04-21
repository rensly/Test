
#include "StdAfx.h"
#include "TestFactoryManager.h"
#include <conio.h>	// getch()

TestFactoryManager g_tTestFactoryManager;

int main( int nArg, char **pArgs )
{
__ENTER_FUNCTION

	g_tTestFactoryManager.Init();

	do 
	{
		__MY_TRY
		{
			cout<<"Test list:"<<endl;

			g_tTestFactoryManager.PrintAll();

			cout<<"Wait input ID:";

			INT nID = 0;
			cin>>nID;

			Test *pTest = g_tTestFactoryManager.CreateTest(nID);
			Assert(pTest);

			cout<<"===================="
				<<"begin:"
				<<pTest->GetClassName()
				<<"===================="
				<<endl;

			pTest->Run();

			cout<<"\n"
				<<"===================="
				<<"end:::"
				<<pTest->GetClassName()
				<<"===================="
				<<endl;

			g_tTestFactoryManager.RemoveTest(pTest);
		}
		__MY_CATCH
		{
			cout<<"Exception. . ."<<endl;
		}

		cout<<"请按Esc键退出,或其他任意键继续. . ."<<endl;

		cin.clear();
		cin.sync();

	} while ( getch() != 27 );

	g_tTestFactoryManager.Release();

	return 0;
__LEAVE_FUNCTION
	return 0;
}