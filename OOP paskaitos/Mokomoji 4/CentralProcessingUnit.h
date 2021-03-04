#ifndef CENTRALPROCESSINGUNIT_H
#define CENTRALPROCESSINGUNIT_H
#include <string>

class CentralProcessingUnit {
  private:
    static int counterID;
    int cpuID;
    std::string manufacturer;
    std::string model;
    int cores;
    int threads;
    float voltage;
    float tdp;
    float baseClock;
    float multiplier;
    float coreClock;

  public:
    CentralProcessingUnit();
    ~CentralProcessingUnit();
    int getID();
    void setManufacturer(const std::string &manufacturer);
    std::string getManufacturer();
    void setModel(const std::string &model);
    std::string getModel();
    void setCores(const int &cores);
    int getCores();
    void setThreads(const int &threads);
    int getThreads();
    void setVoltage(const float &voltage);
    float getVoltage();
    void setTdp(const float &tdp);
    float getTdp();
    void setBaseClock(const float &baseClock);
    float getBaseClock();
    void setMultiplier(const float &multiplier);
    float getMultiplier();
    void setCoreClock(const float &coreClock);
    float getCoreClock();
    std::string toString();
    bool operator==(const CentralProcessingUnit &other) const;
    bool operator!=(const CentralProcessingUnit &other) const;
    bool operator>(const CentralProcessingUnit &other) const;
    bool operator<(const CentralProcessingUnit &other) const;
    bool operator>=(const CentralProcessingUnit &other) const;
    bool operator<=(const CentralProcessingUnit &other) const;
    CentralProcessingUnit& operator++();
    CentralProcessingUnit operator++(int);
    CentralProcessingUnit& operator--();
    CentralProcessingUnit operator--(int);
    std::ostream& operator<<(std::ostream& os);
    //CentralProcessingUnit operator>>();
};
#endif