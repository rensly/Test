
#include "StdAfx.h"
#include "TestMove.h"
#include <memory>

class A
{
public:
	A()
	{
		Print();
	}
	virtual void Print()
	{
		printf("A is constructed.\n");
	}
};

class B : public A
{
public:
	B()
	{
		A::A();
		Print();
		A::A();
	}

	virtual void Print()
	{
		printf("B is constructed.\n");
	}
};

namespace NS_TestMove
{
#define TEST_MOVE 0

	enum class VALUE_TYPE
	{
		VT_INVALID = -1,
		VT_INT,
		VT_INT2,
		VT_FLOAT,
		VT_FLOAT2,
		VT_DOUBLE,
		VT_STRING,
	};

	class CValue
	{
	public:
		virtual VALUE_TYPE GetType() const = 0;
	};

	class CVInvalid : public CValue
	{
	public:
		virtual VALUE_TYPE GetType() const override { return VALUE_TYPE::VT_INVALID; }
	};

	class CVInt : public CValue
	{
	public:
		virtual VALUE_TYPE GetType() const override { return VALUE_TYPE::VT_INT; }
	public:
		explicit CVInt(int nValue)
			:m_nValue(nValue)
		{}
		int GetValue() const { return m_nValue; }
		void SetValue(int nValue) { m_nValue = nValue; }
	private:
		int m_nValue;
	};

	class CVInt2 : public CVInt
	{
	public:
		virtual VALUE_TYPE GetType() const override { return VALUE_TYPE::VT_INT2; }
	public:
		explicit CVInt2(int nValue, int nValue2)
			:CVInt(nValue)
			, m_nValue2(nValue2)
		{}
		int GetValue2() const { return m_nValue2; }
		void SetValue2(int nValue) { m_nValue2 = nValue; }
	private:
		int m_nValue2;
	};

	class CVFloat : public CValue
	{
	public:
		virtual VALUE_TYPE GetType() const override { return VALUE_TYPE::VT_FLOAT; }
	public:
		explicit CVFloat(float fValue)
			:m_fValue(fValue)
		{}
		float GetValue() const { return m_fValue; }
		void SetValue(float fValue) { m_fValue = fValue; }
	private:
		float m_fValue;
	};

	class CVFloat2 : public CVFloat
	{
	public:
		virtual VALUE_TYPE GetType() const override { return VALUE_TYPE::VT_FLOAT2; }
	public:
		explicit CVFloat2(float fValue, float fValue2)
			:CVFloat(fValue)
			, m_fValue2(fValue2)
		{}
		float GetValue2() const { return m_fValue2; }
		void SetValue2(float fValue) { m_fValue2 = fValue; }
	private:
		float m_fValue2;
	};

	class CVDouble : CValue
	{
	public:
		virtual VALUE_TYPE GetType() const override { return VALUE_TYPE::VT_DOUBLE; }
	public:
		explicit CVDouble(double dValue)
			:m_dValue(dValue)
		{}
		double GetValue() const { return m_dValue; }
		void SetValue(double dValue) { m_dValue = dValue; }
	private:
		double m_dValue;
	};

	class CVString : public CValue
	{
	public:
		virtual VALUE_TYPE GetType() const override { return VALUE_TYPE::VT_STRING; }
	public:
		explicit CVString(const string& strValue)
			:m_strValue(strValue)
		{}
		string GetValue() const { return m_strValue; }
		void SetValue(string strValue) { m_strValue = strValue; }
	private:
		string m_strValue;
	};

	class NodeController
	{
	public:
		virtual const char* GetName() const = 0;
		virtual void SetValue(const CValue&& val) const = 0;
#if (TEST_MOVE == 1)
		virtual CValue&& GetValue() const = 0;
#else
		virtual shared_ptr<CValue> GetValue() const = 0;
#endif
	};

	class NodeController_Point : public NodeController
	{
	public:
		virtual const char* GetName() const override { return "Point"; }
		virtual void SetValue(const CValue&& val) const override
		{
			if (val.GetType() == VALUE_TYPE::VT_FLOAT2)
			{
				const CVFloat2& rValue = static_cast<const CVFloat2&>(val);
				float fX = rValue.GetValue();
				float fY = rValue.GetValue2();
				cout<<"fX:"<<fX<<"\n";
				cout<<"fY:"<<fY<<endl;
			}
		}
#if (TEST_MOVE == 1)
		virtual CValue&& GetValue() const override
		{
			return std::move(CVFloat2(1.0f, 2.0f));
		}
#else
		virtual shared_ptr<CValue> GetValue() const override
		{
			return shared_ptr<CValue>(new CVFloat2(1.0f, 2.0f));
		}
#endif
	};

}

VOID TestMove::Run()
{
__ENTER_FUNCTION

	using namespace NS_TestMove;

	NodeController_Point testPoint;

	testPoint.SetValue(CVFloat2(1.0f, 2.0f));
#if (TEST_MOVE == 1)
	auto& val = testPoint.GetValue();
	if (val.GetType() == VALUE_TYPE::VT_FLOAT2)
	{
		const CVFloat2& rValue = static_cast<const CVFloat2&>(val);
		cout << "f1:" << rValue.GetValue() << "\n";
		cout << "f2:" << rValue.GetValue2() << endl;
	}
#else
// 	auto val = testPoint.GetValue();
// 	if (val->GetType() == VALUE_TYPE::VT_FLOAT2)
// 	{
// 		auto pVal = static_cast<CVFloat2*>(val.get());
// 		cout << "f1:" << pVal->GetValue() << "\n";
// 		cout << "f2:" << pVal->GetValue2() << endl;
// 	}

	A* pA = new B();
	delete pA;

#endif

__LEAVE_FUNCTION
}
