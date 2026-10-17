#include "msd.hpp"

namespace msd {
    char nl = '\n';
    char space = ' ';
}

void msd::AskText (std::string prompt, std::string& buffer) 
{  
    do {
        std::cout 
            << prompt
            << ": ";
        std::getline(std::cin, buffer);
    } while (
            IsOnlySpace(buffer) 
            );
}

bool msd::IsOnlySpace (std::string str) 
{
    if (str.empty())
        return true;

    if (str[0] == ' ')
        return IsOnlySpace(str.substr(1));

    return false;
}

    


