
#include "StdAfx.h"
#include "TestVirtualInheritance.h"

namespace NS_TestVirtualInheritance
{
	class Class0
	{
	public:
		Class0( int i0 )
			:m_i0(i0)
		{
			cout<<"Class0:"<<m_i0<<endl;
			Print();
		}
		virtual ~Class0() = 0
		{
			cout<<"~Class0:"<<m_i0<<endl;
		}
		virtual void Print()
		{
			cout<<"Class0 Print()"<<endl;
		}
	private:
		int m_i0;
	};

	class Class1 : virtual public Class0
	{
	public:
		Class1( int i0, int i1 )
			:Class0(i0)
			,m_i1(i1)
		{
			cout<<"Class1:"<<m_i1<<endl;
		}
		virtual ~Class1()
		{
			cout<<"~Class1:"<<m_i1<<endl;
		}
		virtual void Print()
		{
			cout<<"Class1 Print()"<<endl;
		}
	private:
		int m_i1;
	};

	class Class2 : virtual public Class0
	{
	public:
		Class2( int i0, int i2 )
			:Class0(i0)
			,m_i2(i2)
		{
			cout<<"Class2:"<<m_i2<<endl;
		}
		virtual ~Class2()
		{
			cout<<"~Class2:"<<m_i2<<endl;
		}
		virtual void Print()
		{
			cout<<"Class2 Print()"<<endl;
		}
	private:
		int m_i2;
	};

	class Class3 : public Class1, public Class2
	{
	public:
		Class3( int i0, int i1, int i2, int i3 )
			:Class0(i0)
			,Class1(i0, i1)
			,Class2(i0, i2)
			,m_i3(i3)
		{
			cout<<"Class3:"<<m_i3<<endl;
		}
		virtual ~Class3()
		{
			cout<<"~Class3:"<<m_i3<<endl;
		}
		virtual void Print()
		{
			cout<<"Class3 Print()"<<endl;
		}
	private:
		int m_i3;
	};
}

VOID TestVirtualInheritance::Run()
{
__ENTER_FUNCTION

	using namespace NS_TestVirtualInheritance;

	Class3 c(0, 1, 2, 3);

	cout<<sizeof(c)<<endl;

	//Class0 *pTest = new Class3(0, 1, 2, 3);
	//pTest->Print();
	//delete pTest;

__LEAVE_FUNCTION
}