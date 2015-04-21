
#include "StdAfx.h"
#include "TestVirtualFunction.h"

namespace NS_TestVirtualFunction
{
	class Class0
	{
	public:
		Class0( int i0 )
			:m_i0(i0)
		{
			cout<<"Class0:"<<m_i0<<endl;
		}
		virtual ~Class0()
		{
			Print();

			cout<<"~Class0:"<<m_i0<<endl;
		}
		void PrintNotVirtual()
		{
			cout<<"Class0 PrintNotVirtual()"<<endl;
		}
		void PrintNotVirtual2()
		{
			cout<<"Class0 PrintNotVirtual2()"<<endl;

			PrintNotVirtual();
		}
		virtual void Print()
		{
			cout<<"Class0 Print()"<<endl;

			PrintNotVirtual();
		}
		virtual void VirtualFuncDefaultParamValue( bool isPrint = true )
		{
			if ( isPrint )
			{
				cout<<"Class0 FuncDefaultParamValue()"<<endl;
			}
		}
	private:
		int m_i0;
	};

	class Class1 : public Class0
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
			Print();

			cout<<"~Class1:"<<m_i1<<endl;
		}
		void PrintNotVirtual()
		{
			cout<<"Class1 PrintNotVirtual()"<<endl;
		}
		virtual void Print()
		{
			cout<<"Class1 Print()"<<endl;

			PrintNotVirtual2();
		}
		virtual void Print2()
		{
			cout<<"Class1 Print2()"<<endl;
		}
		virtual void VirtualFuncDefaultParamValue( bool isPrint )
		{
			if ( isPrint )
			{
				cout<<"Class1 FuncDefaultParamValue()"<<endl;
			}
		}
	private:
		int m_i1;
	};

	class Class2 : public Class1
	{
	public:
		Class2( int i0, int i1, int i2 )
			:Class1(i0, i1)
			,m_i2(i2)
		{
			cout<<"Class2:"<<m_i2<<endl;
		}
		virtual ~Class2()
		{
			Print();

			cout<<"~Class2:"<<m_i2<<endl;
		}
		virtual void Print()
		{
			cout<<"Class2 Print()"<<endl;
		}
		virtual void Print2()
		{
			cout<<"Class2 Print2()"<<endl;
		}
	private:
		int m_i2;
	};

	class Class11
	{
	public:
		Class11()
		{
		}
		virtual ~Class11()
		{
		}
		void Print()
		{
			cout<<"Class11 Print()"<<endl;
		}
	};

	class Class12 : public Class11
	{
	public:
		Class12()
		{
		}
		virtual ~Class12()
		{
		}
		virtual void Print()
		{
			cout<<"Class12 Print()"<<endl;
		}
	};

	class Class13
	{
	public:
		Class13()
		{
		}
		virtual ~Class13()
		{
		}

		virtual Class12* CreateWindow() = 0;
	};
}

VOID TestVirtualFunction::Run()
{
__ENTER_FUNCTION

	using namespace NS_TestVirtualFunction;

	Class2 c(0, 1, 2);
	c.PrintNotVirtual();
	c.Print2();

	cout<<sizeof(c)<<endl;

	cout<<"===================================================================="<<endl;

	Class0 *pc = new Class1(0, 1);
	pc->Print();
	pc->VirtualFuncDefaultParamValue();
	delete pc;

	cout<<"===================================================================="<<endl;

	Class11 *pc11 = new Class12;
	pc11->Print();
	delete pc11;

	cout<<"===================================================================="<<endl;

__LEAVE_FUNCTION
}