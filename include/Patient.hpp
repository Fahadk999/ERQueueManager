#pragma once 

#include "msd.hpp"
#include <cstdint>

struct Details {
    uint32_t id;
    std::string name,
                gender,
                condition;
    uint8_t painLevel,
            heartRate,
            bloodPressure;
    uint16_t triageScore;

    void Fill (
        uint8_t,
        uint8_t,
        uint8_t,
        uint16_t
        );
};

class Patient {
private:
    static uint32_t idCount;
    Details details;
    
    void CalcTriageScore ();
public:
    Patient (std::string, std::string, std::string);
    bool operator < (const Patient&) const;
    void ShowPatient ();
    Details GetDetails () const;
};
