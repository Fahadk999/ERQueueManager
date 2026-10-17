#include "ER.hpp"

void ER::AddPatient () {
    std::string name, condition;

    msd::AskText("Enter Patient Name", name);
    msd::AskText("Enter Patient Condition", condition);
    Patient newPatient(name, condition);
}

void ER::ShowWaiting () {
    std::priority_queue<Patient> tempQueue = ERQueue;
    
    std::cout << "--- Waiting List ---" << msd::nl;

    while (!(tempQueue.empty()))
    {
        auto details = tempQueue.top().GetDetails();
        std::cout 
            << "ID: "
            << details.id
            << "Name: "
            << details.name
            << "Condition: "
            << details.condition
            << msd::nl;
    }
}
