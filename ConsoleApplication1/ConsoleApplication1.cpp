#include "pch.h"
#include <Windows.h>

using namespace System;

int main(array<System::String^>^ args)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Console::WriteLine(L"¬вед≥ть р€док");
	String^ str = Console::ReadLine();
	String^ example(L"Begin " + str + L" end");
	Console::WriteLine(example);
	Console::WriteLine(L"–€док м≥стить {0} символ≥в.", example->Length);
	return 0;
}

int main(array<System::String^>^ args)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Console::WriteLine(L"¬вед≥ть перший р€док");
	String^ str1 = Console::ReadLine();
	Console::WriteLine(L"¬вед≥ть другий р€док");
	String^ str2 = Console::ReadLine();
	String^ example(str1 + " " + str2);
	Console::WriteLine(example);
	return 0;
}

int main(array<System::String^>^ args)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Console::WriteLine(L"¬вед≥ть перший р€док");
	String^ str1 = Console::ReadLine();
	Console::WriteLine(L"¬вед≥ть другий р€док");
	String^ str2 = Console::ReadLine();
	int result(String::Compare(str1, str2, true));
	if (result > 0)
		Console::WriteLine(L"{0} б≥льше н≥ж {1}", str1, str2);
	else if (result < 0)
		Console::WriteLine(L"{1} б≥льше н≥ж {0}", str1, str2);
	else
		Console::WriteLine(L"{0} екв≥валентно {1}", str1, str2);
	return 0;
}

int main(array<System::String^>^ args)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Console::WriteLine(L"¬вед≥ть р€док");
	String^ str1 = Console::ReadLine();
	String^ reversed(L"");
	for (int i = str1->Length - 1; i >= 0; i--) {
		reversed += str1[i];
	};
	Console::WriteLine(L"–еверсивний р€док: {0}", reversed);
}

int main(array<System::String^>^ args)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Console::WriteLine(L"¬вед≥ть перший р€док");
	String^ str1 = Console::ReadLine();
	Console::WriteLine(L"¬вед≥ть другий р€док");
	String^ str2 = Console::ReadLine();
	if (str1->Length > str2->Length)
	{
		Console::WriteLine(L"ѕерший р€док довший за другий");
	}
	else if (str1->Length < str2->Length)
	{
		Console::WriteLine(L"ƒругий р€док довший за перший");
	}
	else
	{
		Console::WriteLine(L"–€дки однаков≥ за довжиною");
	}
}