#include "CentralProcessingUnit.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

cpu::CentralProcessingUnit::CentralProcessingUnit(std::string manufacturerName, std::string modelName) {
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
    this->cores = cores;
}
int cpu::CentralProcessingUnit::getCores() {
    return cores;
}
void cpu::CentralProcessingUnit::setThreads(int threads) {
    this->threads = threads;
}
int cpu::CentralProcessingUnit::getThreads() {
    return threads;
}
void cpu::CentralProcessingUnit::setVoltage(float voltage) {
    this->voltage = voltage;
}
float cpu::CentralProcessingUnit::getVoltage() {
    return voltage;
}
void cpu::CentralProcessingUnit::setTdp(float tdp) {
    this->tdp = tdp;
}
float cpu::CentralProcessingUnit::getTdp() {
    return tdp;
}
void cpu::CentralProcessingUnit::setBaseClock(float baseClock) {
    this->baseClock = baseClock;
    if (multiplier != 0) {
        calculateCoreClock();
    } else if (coreClock != 0) {
        calculateMultiplier();
    }
}
float cpu::CentralProcessingUnit::getBaseClock() {
    return baseClock;
}
void cpu::CentralProcessingUnit::setMultiplier(float multiplier) {
    this->multiplier = multiplier;
    if (baseClock != 0) {
        calculateCoreClock();
    } else if (coreClock != 0) {
        calculateBaseClock();
    }
}
float cpu::CentralProcessingUnit::getMultiplier() {
    return multiplier;
}
void cpu::CentralProcessingUnit::setCoreClock(float coreClock) {
    this->coreClock = coreClock;
    if (multiplier != 0) {
        calculateBaseClock();
    } else if (baseClock != 0) {
        calculateMultiplier();
    }
}
float cpu::CentralProcessingUnit::getCoreClock() {
    return coreClock;
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
