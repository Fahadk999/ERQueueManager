#pragma once

#include <queue>
#include "Patient.hpp"

class ER {
private:
    std::priority_queue<Patient> ERQueue;

public:
    ER () = default;

    void AddPatient ();
    void ShowWaiting ();
};

