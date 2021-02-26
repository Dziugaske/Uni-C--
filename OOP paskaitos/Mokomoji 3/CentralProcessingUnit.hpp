#ifndef CENTRAL_PROCESSING_UNIT
#define CENTRAL_PROCESSING_UNIT
#include <string>

namespace cpu {
    class CentralProcessingUnit {
      private:
        std::string manufacturerName;
        std::string modelName;
        int cores;
        int threads;
        float voltage;
        float tdp;
        float baseClock;
        float multiplier;
        float coreClock;

      public:
        CentralProcessingUnit(std::string manufacturerName, std::string modelName);
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

      private:
        void calculateBaseClock();
        void calculateMultiplier();
        void calculateCoreClock();

      public:
        std::string toString();
    };
}
#endif