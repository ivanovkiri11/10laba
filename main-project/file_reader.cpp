#include "file_reader.h"
#include "constants.h"
#include "bank_operations.h"

#include <fstream>
#include <cstring>
#include <cstdlib> // Для atoi и atof

date convert(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.year = atoi(str_number);
    return result;
}

void read(const char* file_name, bank_operations* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            bank_operations* item = new bank_operations;
            file >> item->hour;
            file >> item->minute;
            file >> item->seconds;
            file >> tmp_buffer;
            item->start = convert(tmp_buffer);
            file >> tmp_buffer;
            item->finish = convert(tmp_buffer);
            file.getline(tmp_buffer, MAX_STRING_SIZE);
            std::getline(file, item->title);
            file >> tmp_buffer;
            item->action = tmp_buffer;
            file >> tmp_buffer;
            item->number = atoi(tmp_buffer);
            file >> tmp_buffer;
            item->money = atof(tmp_buffer);
            file >> tmp_buffer;
            item->typeofaction = tmp_buffer;

            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}
