#ifndef __TESTFACTORYMANAGER_H__
#define __TESTFACTORYMANAGER_H__

#include "Test.h"

class TestFactoryManager
{
public:
	TestFactoryManager();
	~TestFactoryManager();

	BOOL Init();

	VOID Release();

	BOOL RegisterAll();

	BOOL Register( TestFactory *pTestFactory );

	TestFactory* GetTestFactory( UINT uIndex );

	TestFactory* GetTestFactory( const CHAR *pszName );

	Test* CreateTest( UINT uIndex );

	Test* CreateTest( const CHAR *pszName );

	BOOL RemoveTest( Test* pTest );

	UINT PrintAll();

private:
	vector<TestFactory*> m_vecTestFactory;
};

#endif // __TESTFACTORYMANAGER_H__