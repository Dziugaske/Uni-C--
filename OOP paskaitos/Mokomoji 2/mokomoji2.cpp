#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class CentralProcessingUnit {
  private:
    string manufacturerName;
    string modelName;
    int cores;
    int threads;
    float voltage;
    float tdp;
    float baseClock;
    float multiplier;
    float coreClock;

  public:
    CentralProcessingUnit(string manufacturerName, string modelName) {
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
};
int main() {
    CentralProcessingUnit cpu("AMD", "Ryzen 3600");
    cpu.setCores(6);
    cpu.setTdp(450);
    cpu.setBaseClock(123.1);
    cpu.setMultiplier(13.4);
    cout << cpu.toString();

    vector<CentralProcessingUnit> cpuArray;
    for (int i = 3000; i < 9000; i += 100) {
        cpuArray.push_back(CentralProcessingUnit("Intel", to_string(i)));
    }
    cout << cpuArray[9].toString();
}