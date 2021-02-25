#ifndef DATE
#define DATE


class Date {
    private:
        int year;
        int month;
        int day;
    public:
        Date();
        Date(int year, int month, int day);
        ~Date();
    private:
        void setYear(int value);
        void setMonth(int value);
        void setDay(int value);
    public:
        int getYear();
        int getMonth();
        int getDay();
        std::string showDateLT();
        std::string showDateUS();
        void incrementDate();
    private:
        bool leapYear();
        int dayNumber();
};


#endif