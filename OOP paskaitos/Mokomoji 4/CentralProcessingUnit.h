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
    void setCores(int cores);
    int getCores();
    void setThreads(int threads);
    int getThreads();
    void setVoltage(float voltage);
    float getVoltage();
    void setTdp(float tdp);
    float getTdp();
    void setBaseClock(float baseClock);
    float getBaseClock();
    void setMultiplier(float multiplier);
    float getMultiplier();
    void setCoreClock(float coreClock);
    float getCoreClock();

  public:
    std::string toString();
};
#endif