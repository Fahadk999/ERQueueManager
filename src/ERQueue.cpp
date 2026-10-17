#include "ERQueue.hpp"

using ER = ERQueue;

void ER::AddPatient () {
    std::string name, condition;

    msd::AskText("Enter Patient Name: ", name);
    msd::AskText("Enter Patient Condition: ", condition);
    Patient newPatient(name, condition);
}
