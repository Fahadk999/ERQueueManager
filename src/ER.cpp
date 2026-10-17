#include "ER.hpp"

void ER::AddPatient () {
    std::string name, condition;

    msd::AskText("Enter Patient Name", name);
    msd::AskText("Enter Patient Condition", condition);
    Patient newPatient(name, condition);
    ERQueue.push(newPatient);
}

void ER::ShowWaiting () {
    std::priority_queue<Patient> tempQueue = ERQueue;
    
    std::cout << "--- Waiting List ---" << msd::nl;
    struct {
        int id = 10;
        int name = 20;
        int cond = 20;
        int prio = 6;
    } Width;

    std::cout
        << std::left
        << std::setw(Width.id) << "ID"
        << std::setw(Width.name) << "Name"
        << std::setw(Width.cond) << "Condidtion"
        << std::setw(Width.prio) << "Priority Score"
        << msd::nl;
    while (!(tempQueue.empty()))
    {
        auto details = tempQueue.top().GetDetails();
        std::cout 
            << std::left
            << std::setw(Width.id) << details.id 
            << std::setw(Width.name) << details.name 
            << std::setw(Width.cond) << details.condition 
            << std::setw(Width.prio) << details.triageScore
            << msd::nl;
        tempQueue.pop();
    }
}

void ER::TreatPatient () {
    if (!(ERQueue.empty())) ERQueue.pop();
}
