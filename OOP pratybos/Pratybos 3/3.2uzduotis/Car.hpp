#ifndef CAR
#define CAR
#include "Date.hpp"

class Car {
    private:
        static int carCount;
        std::string modelName;
        int mileage;
        bool crashed;
        Date registryDate;
    public:
        Car();
        Car(std::string modelName);
        Car(std::string modelName, int mileage, bool crashed);
        Car(std::string modelName, int mileage, bool crashed, Date registryDate);
        ~Car();
        static int getCount();
        void setModelName(std::string modelName);
        void setMileage(int mileage);
        void setCrashed(bool crashed);
        std::string getModelName();
        int getMileage();
        bool getCrashed();
        std::string getDate();
        void adjustDate(int value);
};


#endif