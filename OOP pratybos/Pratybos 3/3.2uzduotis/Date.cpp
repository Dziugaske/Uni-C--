#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include "Date.hpp"

Date::Date() {
    time_t now = time(0);
    tm *timeStruct = localtime(&now);

    setYear(1900 + timeStruct->tm_year);
    setMonth(1 + timeStruct->tm_mon);
    setDay(timeStruct->tm_mday);
}
Date::Date(int year, int month, int day) {
    setYear(year);
    setMonth(month);
    setDay(day);
}
Date::~Date() {
    std::cout << "Deleted class Date" << std::endl;
}
void Date::setYear(int value) {
    if (value > 0 && value < 10000){
        year = value;
    }
}
void Date::setMonth(int value) {
    if (value >= 1 && value <= 12){
        month = value;
    }
}
void Date::setDay(int value) {
    if (value >= 1 && value <= dayNumber()){
        day = value;
    } else {
        throw "Impossible date.";
    }
}
int Date::getYear() {
    return year;
}
int Date::getMonth() {
    return month;
}
int Date::getDay() {
    return day;
}
std::string Date::showDateLT() {
    std::ostringstream ss;
    ss << year << "-" << month << "-" << day;
    return ss.str();
}
std::string Date::showDateUS() {
    std::ostringstream ss;
    ss << month << "/" << day << "/" << year;
    return ss.str();
}
void Date::incrementDate() {
    if (day < dayNumber()) {
        setDay(day + 1);
    } else if (month != 12) {
        setMonth(month + 1);
        setDay(1);
    } else {
        setYear(year + 1);
        setMonth(1);
        setDay(1);
    }
}
bool Date::leapYear() {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
        return true;
    } else {
        return false;
    }
}
int Date::dayNumber() {
    if (month == 2) {
        if (leapYear() == true) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||month == 10 || month==12) {
        return 31;
    } else {
        return 30;
    }
}