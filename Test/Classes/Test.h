#ifndef __TEST_H__
#define __TEST_H__

#define CLASS_NAME( Class ) \
	virtual const CHAR * GetClassName() { return #Class; }\
	static const CHAR * GetStaticClassName() { return #Class; }

#define CLASS_DESC( pszDesc ) \
	static const CHAR * GetStaticClassDesc() { return pszDesc; }

#define CLASS_NAME_DESC( Class, pszDesc )\
	CLASS_NAME(Class)\
	CLASS_DESC(pszDesc)

class Test
{
public:

	Test(){}
	virtual ~Test(){}

public:

	virtual const CHAR * GetClassName() = 0;

	static const CHAR * GetStaticClassName() { return ""; }

	static const CHAR * GetStaticClassDesc() { return ""; }

	virtual BOOL Init() { return TRUE; }

	virtual VOID Reset() {}

	virtual VOID Run() = 0;

};

class TestFactory
{
public:
	virtual Test* CreateTest() = 0;
	virtual const CHAR* GetTestName() = 0;
	virtual const CHAR* GetTestDesc() = 0;
};

#define CLASS_CREATEFACTORY( Class ) \
class Class##Factory : public TestFactory \
{\
public:\
	virtual Test* CreateTest() { return new Class; }\
	virtual const CHAR* GetTestName() { return Class::GetStaticClassName(); }\
	virtual const CHAR* GetTestDesc() { return Class::GetStaticClassDesc(); }\
};


#endif