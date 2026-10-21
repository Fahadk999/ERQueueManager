#include "Patient.hpp"

uint32_t Patient::idCount = 0;

void Details::Fill (
        uint8_t _painLevel,
        uint8_t _heartRate,
        uint8_t _bloodPressure,
        uint16_t _triageScore
        )
{
    painLevel = _painLevel;
    heartRate = _heartRate;
    bloodPressure = _bloodPressure;
    triageScore = _triageScore;
}

Patient::Patient (
        std::string _name, // add gender also
        std::string _gender,
        std::string _condition
        ) 
{
    details.name = _name;
    details.condition = _condition;
    details.gender = _gender;
    // post for first to be 0
    details.id = idCount++; 
    CalcTriageScore();
}

void Patient::CalcTriageScore () {
    auto Validate = [] (uint8_t& storeBuffer) {
        int inputBuffer;
        while (!(std::cin >> inputBuffer)
                || inputBuffer < 0 || inputBuffer > 255)
        {
            std::cout 
                << "Enter a positive number between (0-255): ";

            // to stop the inf loop of asking :/
            std::cin.clear();
            std::cin.ignore();
        }
        storeBuffer = static_cast<uint8_t>(inputBuffer);
    };
    std::cout << "Enter your Hear Rate: ";
    Validate(details.heartRate);
    std::cout << "Enter your Blood Pressure: ";
    Validate(details.bloodPressure);

    details.triageScore = 
        static_cast<uint16_t>(details.bloodPressure) 
        +
        static_cast<uint16_t>(details.heartRate);
    std::cout << "\n[Success] Patient Added" << msd::nl;
}

bool Patient::operator < (const Patient& other) const {
    return this->details.triageScore < other.details.triageScore;
}

void Patient::ShowPatient () {
    std::cout << "Your Stats: "
        << details.id << msd::nl
        << details.name << msd::nl
        << details.condition << msd::nl;
}

Details Patient::GetDetails () const {
    return details;
}
