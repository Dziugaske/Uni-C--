#include "CentralProcessingUnit.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

int CentralProcessingUnit::counterID = 1;
CentralProcessingUnit::CentralProcessingUnit() {
    cpuID = counterID;
    ++counterID;
    setManufacturer("N/A");
    setModel("N/A");
    setCores(0);
    setThreads(0);
    setVoltage(0);
    setTdp(0);
    setBaseClock(0);
    setMultiplier(0);
    setCoreClock(0);
}
CentralProcessingUnit::~CentralProcessingUnit() {
}
int CentralProcessingUnit::getID() {
    return cpuID;
}
void CentralProcessingUnit::setManufacturer(const std::string &manufacturer) {
    this->manufacturer = manufacturer;
}
std::string CentralProcessingUnit::getManufacturer() {
    return manufacturer;
}
void CentralProcessingUnit::setModel(const std::string &model) {
    this->model = model;
}
std::string CentralProcessingUnit::getModel() {
    return model;
}
void CentralProcessingUnit::setCores(const int &cores) {
    this->cores = cores;
}
int CentralProcessingUnit::getCores() {
    return cores;
}
void CentralProcessingUnit::setThreads(const int &threads) {
    this->threads = threads;
}
int CentralProcessingUnit::getThreads() {
    return threads;
}
void CentralProcessingUnit::setVoltage(const float &voltage) {
    this->voltage = voltage;
}
float CentralProcessingUnit::getVoltage() {
    return voltage;
}
void CentralProcessingUnit::setTdp(const float &tdp) {
    this->tdp = tdp;
}
float CentralProcessingUnit::getTdp() {
    return tdp;
}
void CentralProcessingUnit::setBaseClock(const float &baseClock) {
    this->baseClock = baseClock;
}
float CentralProcessingUnit::getBaseClock() {
    return baseClock;
}
void CentralProcessingUnit::setMultiplier(const float &multiplier) {
    this->multiplier = multiplier;
}
float CentralProcessingUnit::getMultiplier() {
    return multiplier;
}
void CentralProcessingUnit::setCoreClock(const float &coreClock) {
    this->coreClock = coreClock;
}
float CentralProcessingUnit::getCoreClock() {
    return coreClock;
}
std::string CentralProcessingUnit::toString() const {
    std::ostringstream ss;
    ss << cpuID << " " << manufacturer << " " << manufacturer << " ";
    ss << cores << " " << threads << " " << voltage << " " << tdp << " ";
    ss << baseClock << " " << multiplier << " " << coreClock << std::endl;
    return ss.str();
}
bool CentralProcessingUnit::operator==(const CentralProcessingUnit &other) const {
    if (coreClock == other.coreClock) {
        return true;
    } else {
        return false;
    }
}
bool CentralProcessingUnit::operator!=(const CentralProcessingUnit &other) const {
    bool temp = *this == other;
    return !temp;
}
bool CentralProcessingUnit::operator>(const CentralProcessingUnit &other) const {
    if (coreClock > other.coreClock) {
        return true;
    } else {
        return false;
    }
}
bool CentralProcessingUnit::operator<(const CentralProcessingUnit &other) const {
    return other > *this;
}
bool CentralProcessingUnit::operator>=(const CentralProcessingUnit &other) const {
    if (*this == other) {
        return true;
    } else {
        return *this > other;
    }
}
bool CentralProcessingUnit::operator<=(const CentralProcessingUnit &other) const {
    if (*this == other) {
        return true;
    } else {
        return *this < other;
    }
}
CentralProcessingUnit& CentralProcessingUnit::operator++() {
    ++multiplier;
    return *this;
}
CentralProcessingUnit CentralProcessingUnit::operator++(int) {
    CentralProcessingUnit temp = *this;
    ++multiplier;
    return temp;
}
CentralProcessingUnit& CentralProcessingUnit::operator--() {
    --multiplier;
    return *this;
}
CentralProcessingUnit CentralProcessingUnit::operator--(int) {
    CentralProcessingUnit temp = *this;
    --multiplier;
    return temp;
}
std::ostream& operator<<(std::ostream& os, const CentralProcessingUnit& cpu) {
    os << cpu.toString();
    return os;
}
std::istream& operator>>(std::istream& is, CentralProcessingUnit& cpu) {
    CentralProcessingUnit temp;
    is >> temp.manufacturer >> temp.model >> temp.cores >> temp.threads;
    is >> temp.voltage >> temp.tdp >> temp.baseClock >> temp.multiplier >> temp.coreClock;
    CentralProcessingUnit safetyObject;
    safetyObject.setManufacturer(temp.manufacturer);
    safetyObject.setModel(temp.model);
    safetyObject.setCores(temp.cores);
    safetyObject.setThreads(temp.threads);
    safetyObject.setVoltage(temp.voltage);
    safetyObject.setTdp(temp.tdp);
    safetyObject.setBaseClock(temp.baseClock);
    safetyObject.setMultiplier(temp.multiplier);
    safetyObject.setCoreClock(temp.coreClock);
    cpu = safetyObject;
    return is;
}