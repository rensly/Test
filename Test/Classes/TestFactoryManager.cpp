
#include "StdAfx.h"
#include "TestFactoryManager.h"

TestFactoryManager::TestFactoryManager()
{

}

TestFactoryManager::~TestFactoryManager()
{
	Release();
}

BOOL TestFactoryManager::Init()
{
__ENTER_FUNCTION
	return RegisterAll();
__LEAVE_FUNCTION
	return FALSE;
}

VOID TestFactoryManager::Release()
{
__ENTER_FUNCTION
	ClearVecPtr(m_vecTestFactory);
__LEAVE_FUNCTION
}

BOOL TestFactoryManager::Register( TestFactory *pTestFactory )
{
__ENTER_FUNCTION

	Assert(pTestFactory);

	if ( GetTestFactory(pTestFactory->GetTestName()) )
	{
		AssertEx( FALSE, "Repeat Register:%s", pTestFactory->GetTestName() );
		return FALSE;
	}

	m_vecTestFactory.push_back(pTestFactory);

	return TRUE;
__LEAVE_FUNCTION
	return FALSE;
}

TestFactory* TestFactoryManager::GetTestFactory( UINT uIndex )
{
__ENTER_FUNCTION

	TestFactory *pTestFactory = NULL;

	if ( uIndex < m_vecTestFactory.size() )
	{
		pTestFactory = m_vecTestFactory[uIndex];
	}

	return pTestFactory;

__LEAVE_FUNCTION
	return NULL;
}

TestFactory* TestFactoryManager::GetTestFactory( const CHAR *pszName )
{
__ENTER_FUNCTION

	Assert(pszName);
	Assert(*pszName != '\0');

	TestFactory *pTestFactory = NULL;

	for ( UINT i = 0; i < m_vecTestFactory.size(); ++i )
	{
		if ( strcmp(m_vecTestFactory[i]->GetTestName(), pszName) == 0 )
		{
			pTestFactory = m_vecTestFactory[i];
			break;
		}
	}

	return pTestFactory;

__LEAVE_FUNCTION
	return NULL;
}

Test* TestFactoryManager::CreateTest( UINT uIndex )
{
__ENTER_FUNCTION

	TestFactory *pTestFactory = GetTestFactory(uIndex);
	Assert(pTestFactory);

	return pTestFactory ? pTestFactory->CreateTest() : NULL;

__LEAVE_FUNCTION
	return NULL;
}

Test* TestFactoryManager::CreateTest( const CHAR *pszName )
{
__ENTER_FUNCTION

	TestFactory *pTestFactory = GetTestFactory(pszName);
	Assert(pTestFactory);

	return pTestFactory ? pTestFactory->CreateTest() : NULL;

__LEAVE_FUNCTION
	return NULL;
}

BOOL TestFactoryManager::RemoveTest( Test* pTest )
{
__ENTER_FUNCTION

	if ( pTest )
	{
		delete pTest;
	}

	return TRUE;
__LEAVE_FUNCTION
	return FALSE;
}

UINT TestFactoryManager::PrintAll()
{
__ENTER_FUNCTION

	UINT uCount = 0;
	TestFactory *pTestFactory = NULL;
	while ( pTestFactory = GetTestFactory(uCount) )
	{
		std::cout<<"ID:"<<uCount<<"\t\t"
			<<pTestFactory->GetTestName()
			<<" => "
			<<pTestFactory->GetTestDesc()
			<<std::endl;

		++uCount;
	}

	return uCount;
__LEAVE_FUNCTION
	return 0;
}