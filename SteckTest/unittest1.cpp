#include "stdafx.h"
#include "CppUnitTest.h"
#include "../stek/steck.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SteckTest
{		
	TEST_CLASS(steck)
	{
	public:
		
		TEST_METHOD(konstruktor)
		{
			Steck<int>a;
			Assert::IsTrue(a.Size()==0);
		

		}
		TEST_METHOD(pop)
		{
			Steck<int>a;
			try {
				a.pop();
				Assert::IsTrue(false);
			}
			catch (out_of_range) {
				Assert::IsTrue(true);
			}
			a.push(1);
			Assert::IsTrue((a.pop() == 1) && (a.Size() == 0));
			a.push(1);
			a.push(2);
			a.push(3);

			Assert::IsTrue((a.pop() == 3) && (a.Size() == 2));

		}
		TEST_METHOD(pop_in_head)
		{
			Steck<int>a;
			try {
				a.pop_in_head();
				Assert::IsTrue(false);
			}
			catch (out_of_range) {
				Assert::IsTrue(true);
			}
			a.push(1);
			Assert::IsTrue((a.pop_in_head() == 1)&&(a.Size()==0));
			a.push(1);
			a.push(2);
			a.push(3);

			Assert::IsTrue((a.pop_in_head() == 1) && (a.Size() == 2));
		}
		TEST_METHOD(peek)
		{

			Steck<int>a;
			try {
				a.peek();
				Assert::IsTrue(false);
			}
			catch (out_of_range) {
				Assert::IsTrue(true);
			}
			a.push(1);
			Assert::IsTrue((a.peek() == 1) && (a.Size() == 1));
			a.push(1);
			a.push(2);
			a.push(3);

			Assert::IsTrue((a.peek() == 3) && (a.Size() == 4));
		}
		TEST_METHOD(size)
		{
			Steck<int>a;
			for (int i = 0; i < 10;i++) {
				a.push(1);
				Assert::IsTrue(a.Size()==i+1);
			}
			for (int i = a.Size(); i > 0; i--) {
				a.pop();
				Assert::IsTrue(a.Size() == i-1);
			}



		}



	};
}