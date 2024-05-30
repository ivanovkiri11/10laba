#include <iostream>
#include <iomanip>
#include <locale> // Для setlocale

using namespace std;

#include "bank_operations.h" // Исправлено на bank_operations.h
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №10. GIT\n";
    cout << "Вариант №7. Банковские операции\n"; // Изменено на "Банковские операции"
    cout << "Автор: Иванов Кирилл\n\n";
    cout << "Group: 23UIR1d\n";
    bank_operations* operations[MAX_FILE_ROWS_COUNT]; // Изменено на operations
    int size;
    try
    {
        read("data.txt", operations, size);
        cout << "***** Банковские операции *****\n\n"; // Изменено на "Банковские операции"
        for (int i = 0; i < size; i++)
        {
            /********** вывод операции **********/
            cout << "Операция........: ";
            cout << operations[i]->action << '\n'; // Вывод операции
            cout << "Номер операции...: ";
            cout << operations[i]->number << '\n'; // Вывод номера операции
            cout << "Сумма............: ";
            cout << operations[i]->money << '\n'; // Вывод суммы
            cout << "Тип операции.....: ";
            cout << operations[i]->typeofaction << '\n'; // Вывод типа операции
            cout << "Дата начала......: ";
            cout << setw(4) << setfill('0') << operations[i]->start.year << '-';
            cout << setw(2) << setfill('0') << operations[i]->start.month << '-';
            cout << setw(2) << setfill('0') << operations[i]->start.day;
            cout << '\n';
            cout << "Дата окончания...: ";
            cout << setw(4) << setfill('0') << operations[i]->finish.year << '-';
            cout << setw(2) << setfill('0') << operations[i]->finish.month << '-';
            cout << setw(2) << setfill('0') << operations[i]->finish.day;
            cout << '\n';
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete operations[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}
