//
// Created by jonathanmiroshnik on 01/10/2026.
//

#include "uniqueptr.h"

#include <iostream>
#include <ostream>

void uniqueptr::print_status() {
    if (!this->used) {
        std::cout << "Unused" << std::endl;
        return;
    }
    std::cout << "Used" << '\n';
    std::cout << "Pointer being protected by the unique pointer: "<< this->pointer << std::endl;
};
