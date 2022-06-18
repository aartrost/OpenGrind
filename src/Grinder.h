#pragma once

class Grinder
{  
    private:
        int eeAddress = 100;
        unsigned long targetTime = 0;

    public:
        Grinder();
        bool startBtnPressed();
        bool isGrinding();
        int getSingleDoseStats();
        int getDoubleDoseStats();
        void increaseShotCounter(bool isSingleDose);
        void resetStats();
        void on();
        void off();
};