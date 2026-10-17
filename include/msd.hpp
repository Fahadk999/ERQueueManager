#pragma once

#include <string>
#include <iostream>

namespace msd {
    extern char nl;
    extern char space;

    void AskText (std::string, std::string&);
    bool IsOnlySpace (std::string);
}
