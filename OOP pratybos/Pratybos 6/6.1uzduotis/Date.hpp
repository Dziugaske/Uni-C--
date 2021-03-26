#ifndef DATE
#define DATE
#include <string>

class Date {
  private:
    int year;
    int month;
    int day;

  public:
    Date();
    Date(int year, int month, int day);
    void setYear(int value);
    void setMonth(int value);
    void setDay(int value);

    int getYear() const;
    int getMonth() const;
    int getDay() const;
    std::string showDateLT() const;
    std::string showDateUS() const;
    void incrementDate();

    Date operator+(const Date &other) const;
    Date &operator+=(const Date &other);
    friend Date operator+(int value, const Date &other);
    friend Date operator+(const Date &other, int value);

    bool operator==(const Date &other) const;
    bool operator!=(const Date &other) const;
    bool operator>(const Date &other) const;
    bool operator<(const Date &other) const;
    bool operator>=(const Date &other) const;
    bool operator<=(const Date &other) const;

    std::ostream &operator<<(std::ostream &os)  const;
    friend std::ostream &operator<<(std::ostream &os, const Date &date);
    friend std::istream &operator>>(std::istream &is, Date &date);

    Date &operator++();
    Date operator++(int);

  private:
    bool leapYear();
    int dayNumber();
};

#endif