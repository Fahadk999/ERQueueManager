#pragma once 

#include "msd.hpp"
#include <cstdint>

struct Details {
    uint32_t id;
    std::string name;
    uint8_t triageScore;
    std::string condition;

    Details (
        uint32_t,
        std::string,
        uint8_t,
        std::string
        );
};

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
    Details GetDetails () const;
};
