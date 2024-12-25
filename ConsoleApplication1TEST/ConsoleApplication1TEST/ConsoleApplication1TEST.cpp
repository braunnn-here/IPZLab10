#include "pch.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    String^ num(L"14159265358979");
    String^ result(L"");
    int i(num->Length);
    result = num;
    Console::WriteLine(L"Заданий рядок: {0}", num);
    while (i > 3)
    {
        i = i - 3;
        result = result->Insert(i, L" ");
    } 
    Console::WriteLine(L"Результат: {0}", result);
 
    return 0;
}
