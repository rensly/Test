#ifndef __TESTDEFINE_H__
#define __TESTDEFINE_H__

#include "Test.h"
#include "TestLanguage/TestConstructor.h"
#include "TestLanguage/TestVirtualInheritance.h"
#include "TestLanguage/TestVirtualFunction.h"
#include "TestLanguage/TestMemberFuncPtr.h"
#include "TestLanguage/TestAuto.h"
#include "TestStandard/TestStandard.h"
#include "TestStandard/TestTime.h"
#include "TestStandard/TestSharedPtr.h"
#include "TestStandard/TestStdFunctionAndBind.h"
#include "TestStandard/TestMove.h"
#include "TestCommon/TestCommon.h"
#include "TestParameters/TestParameters.h"

CLASS_CREATEFACTORY(TestConstructor);
CLASS_CREATEFACTORY(TestVirtualInheritance);
CLASS_CREATEFACTORY(TestVirtualFunction);
CLASS_CREATEFACTORY(TestMemberFuncPtr);
CLASS_CREATEFACTORY(TestAuto);
CLASS_CREATEFACTORY(TestStandard);
CLASS_CREATEFACTORY(TestTime);
CLASS_CREATEFACTORY(TestSharedPtr);
CLASS_CREATEFACTORY(TestStdFunctionAndBind);
CLASS_CREATEFACTORY(TestMove);
CLASS_CREATEFACTORY(TestCommon);
CLASS_CREATEFACTORY(TestParameters);


#endif