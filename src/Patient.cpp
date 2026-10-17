#include "Patient.hpp"

uint32_t Patient::idCount = 0;

Patient::Patient (
        std::string _name,
        std::string _condition
        ) 
    :
    name(_name),
    condition(_condition)
{
    // post for first to be 0
    id = idCount++; 
    CalcTriageScore();
}

void Patient::CalcTriageScore () {
    uint8_t heartRate, bloodPressure;

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
    Validate(heartRate);
    std::cout << "Enter your Blood Pressure: ";
    Validate(bloodPressure);

    triageScore = bloodPressure + heartRate;
}

bool Patient::operator < (const Patient& other) const {
    return this->triageScore < other.triageScore;
}

void Patient::ShowPatient () {
    std::cout << "Your Stats: "
        << id << msd::nl
        << name << msd::nl
        << condition << msd::nl;
}
