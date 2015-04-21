
#include "StdAfx.h"
#include "TestTime.h"
#include <time.h>

namespace NS_TestTime
{
	int timeDiffDay( unsigned int nTime1, unsigned int nTime2 )
	{
		time_t t0 = 0;	// 这个值是为了取时区
		tm _tm0 = *localtime(&t0);
		unsigned int nTimeZone = _tm0.tm_hour * 3600;

		time_t t1 = nTime1 + nTimeZone;
		time_t t2 = nTime2 + nTimeZone;
		int nDay1 = t1 / 86400;
		int nDay2 = t2 / 86400;
		return nDay1 - nDay2;
	}
}

VOID TestTime::Run()
{
__ENTER_FUNCTION

	using namespace NS_TestTime;

	time_t t = time(NULL);
	tm _tm = *localtime(&t);
	cout<<"current time:"<<ctime(&t)<<endl;

	time_t t2 = 0;
	tm _tm2 = *localtime(&t2);
	cout<<"target time:"<<ctime(&t2)<<endl;

	time_t t3 = 0,t4 = 57600+86400*1;
	cout<<"t3 time:"<<ctime(&t3)<<endl;
	cout<<"t4 time:"<<ctime(&t4)<<endl;
	cout<<"time diff day:"<<timeDiffDay(t3, t4)<<endl;

__LEAVE_FUNCTION
}