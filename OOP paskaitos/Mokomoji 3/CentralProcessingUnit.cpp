#include "CentralProcessingUnit.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

CentralProcessingUnit(std::string manufacturerName, std::string modelName) {
    this->manufacturerName = manufacturerName;
    this->modelName = modelName;
    cores = 0;
    threads = 0;
    voltage = 0;
    tdp = 0;
    baseClock = 0;
    multiplier = 0;
    coreClock = 0;
}
~CentralProcessingUnit() {
}
void setCores(int cores) {
    this->cores = cores;
}
int getCores() {
    return cores;
}
void setThreads(int threads) {
    this->threads = threads;
}
int getThreads() {
    return threads;
}
void setVoltage(float voltage) {
    this->voltage = voltage;
}
float getVoltage() {
    return voltage;
}
void setTdp(float tdp) {
    this->tdp = tdp;
}
float getTdp() {
    return tdp;
}
void setBaseClock(float baseClock) {
    this->baseClock = baseClock;
    if (multiplier != 0) {
        calculateCoreClock();
    } else if (coreClock != 0) {
        calculateMultiplier();
    }
}
float getBaseClock() {
    return baseClock;
}
void setMultiplier(float multiplier) {
    this->multiplier = multiplier;
    if (baseClock != 0) {
        calculateCoreClock();
    } else if (coreClock != 0) {
        calculateBaseClock();
    }
}
float getMultiplier() {
    return multiplier;
}
void setCoreClock(float coreClock) {
    this->coreClock = coreClock;
    if (multiplier != 0) {
        calculateBaseClock();
    } else if (baseClock != 0) {
        calculateMultiplier();
    }
}
float getCoreClock() {
    return coreClock;
}

private:
void calculateBaseClock() {
    baseClock = coreClock / multiplier;
}
void calculateMultiplier() {
    multiplier = coreClock / baseClock;
}
void calculateCoreClock() {
    coreClock = baseClock * multiplier;
}

public:
string toString() {
    ostringstream ss;
    ss << "Manufactured by: " << manufacturerName << endl;
    ss << "Model name: " << modelName << endl;
    ss << "Cores: " << cores << endl;
    ss << "Threads: " << threads << endl;
    ss << "Voltage: " << voltage << endl;
    ss << "TDP: " << tdp << endl;
    ss << "Base clock: " << baseClock << endl;
    ss << "Multiplier: " << multiplier << endl;
    ss << "Core clock: " << coreClock << endl;
    return ss.str();
}
