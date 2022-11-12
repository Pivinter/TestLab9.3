#include "pch.h"
#include "CppUnitTest.h"
#include "../TestLab9.3/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest93
{
	TEST_CLASS(UnitTest93)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			t = main();
			Assert::AreEqual(t, 0);
		}
	};
}
