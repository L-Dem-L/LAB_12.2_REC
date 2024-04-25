#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_12.2_REC/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(hasDuplicatePairTest)
		{
			// Створення тестового списку
			Node* head = nullptr;
			Node* tail = nullptr;
			int values[] = { 1, 2, 3, 4, 5, 2 }; // список із дублюючими значеннями 2
			int size = sizeof(values) / sizeof(values[0]);
			createList(head, tail, values, size);

			// Виклик функції hasDuplicatePair для тестування
			bool result = hasDuplicatePair(head);

			// Перевірка очікуваного результату
			Assert::IsTrue(result); // очікуємо, що функція поверне true, оскільки є дублююча пара 2
		}
	};
}
