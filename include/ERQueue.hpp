#pragma once

#include <queue>
#include "Patient.hpp"

class ERQueue {
private:
    std::priority_queue<Patient> Queue;

public:
    ERQueue () = default;

    void AddPatient ();
};

