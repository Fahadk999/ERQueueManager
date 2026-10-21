#include "ER.hpp"

void ER::AddPatient () {
    std::string name, gender, condition;

    msd::AskText("Enter Patient Name", name);
    msd::AskText("Enter your gender", gender);
    msd::AskText("Enter Patient Condition", condition);
    Patient newPatient(name, gender, condition);
    ERQueue.push(newPatient);
}

void ER::ShowWaiting () {
    std::priority_queue<Patient> tempQueue = ERQueue;
    
    std::cout << "--- Waiting List ---" << msd::nl;
    struct {
        int small = 6;
        int medium = 10;
        int large = 20;
    } Width;

    std::cout
        << std::left
        << std::setw(Width.small) << "ID"
        << std::setw(Width.large) << "Name"
        << std::setw(Width.large) << "Gender"
        << std::setw(Width.large) << "Condidtion"
        << std::setw(Width.medium) << "Priority Score"
        << msd::nl;
    while (!(tempQueue.empty()))
    {
        auto details = tempQueue.top().GetDetails();
        std::cout 
            << std::left
            << std::setw(Width.small) << details.id 
            << std::setw(Width.large) << details.name 
            << std::setw(Width.large) << details.gender
            << std::setw(Width.large) << details.condition 
            << std::setw(Width.medium) << details.triageScore
            << msd::nl;
        tempQueue.pop();
    }
}

void ER::TreatPatient () {
    if (!(ERQueue.empty())) ERQueue.pop();
}
