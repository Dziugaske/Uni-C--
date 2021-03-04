#include "CentralProcessingUnit.h"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int CentralProcessingUnit::counterID = 1;
CentralProcessingUnit::CentralProcessingUnit() {
    cpuID = counterID;
    ++counterID;
    this->manufacturer = manufacturer;
    this->model = model;
    cores = 0;
    threads = 0;
    voltage = 0;
    tdp = 0;
    baseClock = 0;
    multiplier = 0;
    coreClock = 0;
}
CentralProcessingUnit::~CentralProcessingUnit() {
}
void CentralProcessingUnit::setCores(int cores) {
    if (cores > 0 && cores <= 128) {
        this->cores = cores;
        calculateThreads();
    } else {
        throw std::invalid_argument("Invalid core count.");
    }
}
int CentralProcessingUnit::getCores() {
    return cores;
}
void CentralProcessingUnit::setThreads(int threads) {
    if (threads >= 2 && threads <= 256) {
        this->threads = threads;
        calculateCores();
    } else {
        throw std::invalid_argument("Invalid thread count.");
    }
}
int CentralProcessingUnit::getThreads() {
    return threads;
}
void CentralProcessingUnit::setVoltage(float voltage) {
    if (voltage > 0 && voltage < 2) {
        this->voltage = voltage;
    } else {
        throw std::invalid_argument("Invalid voltage.");
    }
}
float CentralProcessingUnit::getVoltage() {
    return voltage;
}
void CentralProcessingUnit::setTdp(float tdp) {
    if (tdp > 0 && tdp < 1000) {
        this->tdp = tdp;
    } else {
        throw std::invalid_argument("Invalid TDP.");
    }
}
float CentralProcessingUnit::getTdp() {
    return tdp;
}
void CentralProcessingUnit::setBaseClock(float baseClock) {
    if (baseClock > 0 && baseClock < 1000) {
        this->baseClock = baseClock;
        if (multiplier != 0) {
            calculateCoreClock();
        } else if (coreClock != 0) {
            calculateMultiplier();
        }
    } else {
        throw std::invalid_argument("Invalid base clock.");
    }
}
float CentralProcessingUnit::getBaseClock() {
    return baseClock;
}
void CentralProcessingUnit::setMultiplier(float multiplier) {
    if (multiplier > 0 && multiplier < 50) {
        this->multiplier = multiplier;
        if (baseClock != 0) {
            calculateCoreClock();
        } else if (coreClock != 0) {
            calculateBaseClock();
        }
    } else {
        throw std::invalid_argument("Invalid multiplier.");
    }
}
float CentralProcessingUnit::getMultiplier() {
    return multiplier;
}
void CentralProcessingUnit::setCoreClock(float coreClock) {
    if (coreClock > 1000 && coreClock < 6000) {
        this->coreClock = coreClock;
        if (multiplier != 0) {
            calculateBaseClock();
        } else if (baseClock != 0) {
            calculateMultiplier();
        }
    } else {
        throw std::invalid_argument("Invalid core clock.");
    }
}
float CentralProcessingUnit::getCoreClock() {
    return coreClock;
}
std::string CentralProcessingUnit::toString() {
    std::ostringstream ss;
    ss << "CPU ID: " << cpuID << std::endl;
    ss << "Manufactured by: " << manufacturer << std::endl;
    ss << "Model name: " << model << std::endl;
    ss << "Cores: " << cores << std::endl;
    ss << "Threads: " << threads << std::endl;
    ss << "Voltage: " << voltage << std::endl;
    ss << "TDP: " << tdp << std::endl;
    ss << "Base clock: " << baseClock << std::endl;
    ss << "Multiplier: " << multiplier << std::endl;
    ss << "Core clock: " << coreClock << std::endl;
    return ss.str();
}