#pragma once

#include <string>

struct date {
    int day;
    int month;
    int year;
};

struct bank_operations {
    int hour;
    int minute;
    int seconds;
    date start;
    date finish;
    std::string title;
    std::string action;
    int number;
    double money;
    std::string typeofaction; 
};
