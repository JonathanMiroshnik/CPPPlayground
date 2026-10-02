//
// Created by jonathanmiroshnik on 01/10/2026.
//

#include "uniqueptr.h"

#include <cstdlib>
#include <iostream>
#include <ostream>

template <typename T>
uniqueptr<T>::uniqueptr(T* input_pointer) : pointer(input_pointer) {}

template <typename T>
uniqueptr<T>::~uniqueptr() {
    free(pointer);   // free(nullptr) is guaranteed to do nothing, so no check needed
}

template <typename T>
uniqueptr<T>& uniqueptr<T>::operator=(T* input_pointer) {
    if (input_pointer != pointer) {
        free(pointer);              // release what we owned before
        pointer = input_pointer;    // then take ownership of the new pointer
    }
    return *this;
}

template <typename T>
T& uniqueptr<T>::operator*() {
    return *pointer;
}

template <typename T>
uniqueptr<T>::operator bool() {
    return pointer != nullptr;      // true == we own something
}

template <typename T>
void uniqueptr<T>::print_status() {
    if (pointer == nullptr) {
        std::cout << "Unused" << std::endl;
        return;
    }
    std::cout << "Used2" << '\n';
    std::cout << "Pointer being protected by the unique pointer: "<< pointer << std::endl;
};

// The member definitions above live in this translation unit, so the compiler
// only knows how to build them for the instantiations named explicitly here.
// Anything else (e.g. uniqueptr<double>) needs its own instantiation line, or
// the definitions have to live in uniqueptr.h.
template class uniqueptr<int>;

