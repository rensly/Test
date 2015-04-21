
#include "StdAfx.h"
#include "TestFactoryManager.h"
#include "TestDefine.h"

BOOL TestFactoryManager::RegisterAll()
{
__ENTER_FUNCTION

	Register( new TestConstructorFactory() );
	Register( new TestVirtualInheritanceFactory() );
	Register( new TestVirtualFunctionFactory() );
	Register( new TestMemberFuncPtrFactory() );
	Register( new TestAutoFactory() );
	Register( new TestStandardFactory() );
	Register( new TestTimeFactory() );
	Register( new TestSharedPtrFactory() );
	Register( new TestStdFunctionAndBindFactory() );
	Register( new TestMoveFactory() );
	Register( new TestCommonFactory() );
	Register( new TestParametersFactory() );

	return TRUE;
__LEAVE_FUNCTION
	return FALSE;
}