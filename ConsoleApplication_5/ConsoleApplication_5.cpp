#include "pch.h"
#include "Windows.h"

using namespace System;

int main(array<String^>^ args)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	try {
		Console::WriteLine("Оберіть задачу:");
		Console::WriteLine("1 - Розрахунок струму короткого замикання (за S)");
		Console::WriteLine("2 - Таблиця ступенів чисел");
		Console::Write("Ваш вибір: ");
		String^ choiceStr = Console::ReadLine();
		int choice;
		if (!Int32::TryParse(choiceStr, choice)) {
			Console::WriteLine("Помилка: введіть число 1 або 2!");
			return 0;
		}
		if (choice == 1) {
			// Задача 1: розрахунок струму короткого замикання
			Console::Write("Введіть S (потужність КЗ, МВА): ");
			String^ S_str = Console::ReadLine();
			if (String::IsNullOrWhiteSpace(S_str)) {
				Console::WriteLine("Будь ласка, введіть S!");
				return 0;
			}
			double S;
			if (!Double::TryParse(S_str, S)) {
				Console::WriteLine("Помилка: введено текст замість числа!");
				return 0;
			}
			Console::Write("Введіть рівні напруги через пробіл: ");

			String^ vInput = Console::ReadLine();
			array<String^>^ vParts = vInput->Split(' ');
			array<double>^ voltages = gcnew array<double>(vParts->Length);
			for (int i = 0; i < vParts->Length; i++) {
				double num;
				if (!Double::TryParse(vParts[i], num)) {
					Console::WriteLine("Помилка: введіть тільки числа, розділені пробілом!");
						return 0;
				}
				voltages[i] = num;
			}
			Console::WriteLine("\nРезультати розрахунку:");
			Console::WriteLine("Напруга (В)\tIкз (А)");
			for each (int voltage in voltages) {
				double sc_current = S / (Math::Sqrt(3) * voltage);
				Console::WriteLine("{0}\t\t{1:F6}", voltage, sc_current);
			}
		}
		else if (choice == 2) {
			// Задача 2: таблиця ступенів чисел
			Console::Write("Введіть числа через пробіл: ");
			String^ input = Console::ReadLine();
			if (String::IsNullOrWhiteSpace(input)) {
				Console::WriteLine("Помилка: рядок порожній!");
				return 0;
			}
			array<String^>^ parts = input->Split(' ');
			int columns = parts->Length;
			int rows = columns;
			array<double>^ numbers = gcnew array<double>(parts->Length);
			for (int i = 0; i < parts->Length; i++) {
				double num;
				if (!Double::TryParse(parts[i], num)) {
					Console::WriteLine("Помилка: введіть тільки числа, розділені пробілом!");
						return 0;
				}
				numbers[i] = num;
			}
			array<double, 2>^ table = gcnew array<double, 2>(rows, columns);
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					table[i, j] = Math::Pow(numbers[j], i + 1);
				}
			}
			// Виведення таблиці
			Console::WriteLine("\nТаблиця ступенів чисел:");
			for (int i = 0; i < columns; i++) {
				Console::Write("x{0}\t", i + 1);
			}
			Console::WriteLine();
			for (int i = 0; i < rows; i++) {

				for (int j = 0; j < columns; j++) {
					Console::Write("{0}\t", table[i, j]);
				}
				Console::WriteLine(" <- x^{0}", i + 1);
			}
		}
		else {
			Console::WriteLine("Будь ласка, виберіть 1 або 2.");
		}
	}
	catch (Exception^ ex) {
		Console::WriteLine("Невідома помилка: {0}", ex->Message);
	}
	return 0;
}