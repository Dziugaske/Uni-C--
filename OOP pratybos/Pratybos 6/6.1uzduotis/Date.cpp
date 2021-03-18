#include "Date.hpp"
#include <ctime>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

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
void Date::setYear(int value) {
    if (value > 0 && value < 10000) {
        year = value;
    } else {
        throw std::invalid_argument("Invalid year");
    }
}
void Date::setMonth(int value) {
    if (value >= 1 && value <= 12) {
        month = value;
    } else {
        throw std::invalid_argument("Invalid month");
    }
}
void Date::setDay(int value) {
    if (value >= 1 && value <= dayNumber()) {
        day = value;
    } else {
        throw std::invalid_argument("Impossible date.");
    }
}
int Date::getYear() const {
    return year;
}
int Date::getMonth() const {
    return month;
}
int Date::getDay() const {
    return day;
}
std::string Date::showDateLT() const {
    std::ostringstream ss;
    ss << year << "-" << month << "-" << day;
    return ss.str();
}
std::string Date::showDateUS() const {
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
Date Date::operator+(const Date &other) const {
    Date temp = *this;
    temp.setYear(this->year + other.year);
    int tempMonth = this->month + other.month;
    temp.setMonth(tempMonth % 12);
    for (int i = 1; i <= other.day; ++i) {
        temp.incrementDate();
    }
    return temp;
}
Date &Date::operator+=(const Date &other) {
    *this = *this + other;
    return *this;
}
Date operator+(int value, const Date &other) {
    Date temp = other;
    for (int i = 1; i <= value; ++i) {
        temp.incrementDate();
    }
    return temp;
}
Date operator+(const Date &other, int value) {
    return value + other;
}
bool Date::operator==(const Date &other) const {
    if (this->year == other.year && this->month == other.month && this->day == other.day) {
        return true;
    } else {
        return false;
    }
}
bool Date::operator!=(const Date &other) const {
    return !(*this == other);
}
bool Date::operator>(const Date &other) const {
    if (this->year > other.year) {
        return true;
    } else if (this->year == other.year) {
        if (this->month > other.month) {
            return true;
        } else if (this->month == other.month) {
            if (this->day > other.day) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}
bool Date::operator<(const Date &other) const {
    return other > *this;
}
bool Date::operator>=(const Date &other) const {
    if (*this == other || *this > other) {
        return true;
    } else {
        return false;
    }
}
bool Date::operator<=(const Date &other) const {
    if (*this == other || other > *this) {
        return true;
    } else {
        return false;
    }
}
std::ostream &Date::operator<<(std::ostream &os) const {
    os << this->showDateLT();
    return os;
}
std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << date.showDateLT();
    return os;
}
std::istream &operator>>(std::istream &is, Date &date) {
    int year, month, day;
    std::cin >> year >> month >> day;
    Date temp(year, month, day);
    date = temp;
    return is;
}
Date &Date::operator++() {
    this->incrementDate();
    return *this;
}
Date Date::operator++(int) {
    Date temp = *this;
    this->incrementDate();
    return temp;
}
bool Date::leapYear() {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
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
    } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    } else {
        return 30;
    }
}