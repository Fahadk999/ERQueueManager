#pragma once 

#include "msd.hpp"
#include <cstdint>

class Patient {
private:
    static uint32_t idCount;
    uint32_t id;
    std::string name;
    uint8_t triageScore;
    std::string condition;
    
    void CalcTriageScore ();
public:
    Patient (std::string, std::string);
    bool operator < (const Patient&) const;
    void ShowPatient ();
};
