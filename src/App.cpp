#include "App.hpp"

namespace App {
    ER er;
}

void App::Run () {
    // all the main loop
    bool running = true;
    short int choice; 

    while (running) {
        std::cout 
            << "\n--- ER Triage Manager ---\n"
            << "1. Register New Patien\n"
            << "2. Treat Critical Patient\n"
            << "3. View Emergency Queue\n"
            << "4. Exit\n"
            << "Enter Your Choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                er.AddPatient();
                break;
            case 2:
                er.TreatPatient();
                break;
            case 3:
                er.ShowWaiting();
                break;
            case 4:
                std::cout
                    << "\nExited Program\n";
                running = false;
                break;
            default: 
                std::cerr << "\nInvalid Input\n";
                break;
        }
    }
}
