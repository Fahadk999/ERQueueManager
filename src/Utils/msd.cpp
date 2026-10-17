#include "msd.hpp"

namespace msd {
    char nl = '\n';
}

void msd::AskText (std::string prompt, std::string& buffer) 
{  
    do {
        std::cout 
            << prompt
            << ": ";
        std::getline(std::cin, buffer);
    } while (buffer.size() > 0);
}


