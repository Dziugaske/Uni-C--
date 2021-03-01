#include "CentralProcessingUnit.h"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int cpu::CentralProcessingUnit::counterID = 1;
cpu::CentralProcessingUnit::CentralProcessingUnit(std::string manufacturerName, std::string modelName) {
    cpuID = counterID;
    ++counterID;
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
cpu::CentralProcessingUnit::~CentralProcessingUnit() {
}
void cpu::CentralProcessingUnit::setCores(int cores) {
    if (cores > 0 && cores <= 128) {
        this->cores = cores;
        calculateThreads();
    } else {
        throw std::invalid_argument("Invalid core count.");
    }
}
int cpu::CentralProcessingUnit::getCores() {
    return cores;
}
void cpu::CentralProcessingUnit::setThreads(int threads) {
    if (threads >= 2 && threads <= 256) {
        this->threads = threads;
        calculateCores();
    } else {
        throw std::invalid_argument("Invalid thread count.");
    }
}
int cpu::CentralProcessingUnit::getThreads() {
    return threads;
}
void cpu::CentralProcessingUnit::setVoltage(float voltage) {
    if (voltage > 0 && voltage < 2) {
        this->voltage = voltage;
    } else {
        throw std::invalid_argument("Invalid voltage.");
    }
}
float cpu::CentralProcessingUnit::getVoltage() {
    return voltage;
}
void cpu::CentralProcessingUnit::setTdp(float tdp) {
    if (tdp > 0 && tdp < 1000) {
        this->tdp = tdp;
    } else {
        throw std::invalid_argument("Invalid TDP.");
    }
}
float cpu::CentralProcessingUnit::getTdp() {
    return tdp;
}
void cpu::CentralProcessingUnit::setBaseClock(float baseClock) {
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
float cpu::CentralProcessingUnit::getBaseClock() {
    return baseClock;
}
void cpu::CentralProcessingUnit::setMultiplier(float multiplier) {
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
float cpu::CentralProcessingUnit::getMultiplier() {
    return multiplier;
}
void cpu::CentralProcessingUnit::setCoreClock(float coreClock) {
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
float cpu::CentralProcessingUnit::getCoreClock() {
    return coreClock;
}
void cpu::CentralProcessingUnit::calculateCores() {
    cores = threads / 2;
}
void cpu::CentralProcessingUnit::calculateThreads() {
    threads = cores * 2;
}
void cpu::CentralProcessingUnit::calculateBaseClock() {
    baseClock = coreClock / multiplier;
}
void cpu::CentralProcessingUnit::calculateMultiplier() {
    multiplier = coreClock / baseClock;
}
void cpu::CentralProcessingUnit::calculateCoreClock() {
    coreClock = baseClock * multiplier;
}
std::string cpu::CentralProcessingUnit::toString() {
    std::ostringstream ss;
    ss << "CPU ID: " << cpuID << std::endl;
    ss << "Manufactured by: " << manufacturerName << std::endl;
    ss << "Model name: " << modelName << std::endl;
    ss << "Cores: " << cores << std::endl;
    ss << "Threads: " << threads << std::endl;
    ss << "Voltage: " << voltage << std::endl;
    ss << "TDP: " << tdp << std::endl;
    ss << "Base clock: " << baseClock << std::endl;
    ss << "Multiplier: " << multiplier << std::endl;
    ss << "Core clock: " << coreClock << std::endl;
    return ss.str();
}
