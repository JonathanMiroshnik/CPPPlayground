//
// Created by jonathanmiroshnik on 01/10/2026.
//

#include "uniqueptr.h"

#include <cstdlib>
#include <iostream>
#include <ostream>

template <typename T>
uniqueptr<T>::uniqueptr(T* input_pointer) {
    if (used) return;
    pointer = input_pointer;
    used = true;
}

template <typename T>
uniqueptr<T>::~uniqueptr() {
    if (used || pointer == nullptr) {
        free(pointer);
    }
    used = false;
}

template <typename T>
T* uniqueptr<T>::operator=(T* input_pointer) {
    pointer = input_pointer;
    used = true;
    return input_pointer;
}

// template <typename T>
// T uniqueptr<T>::operator->() {

// }

template <typename T>
T uniqueptr<T>::operator*() {
    return *pointer;
}

template <typename T>
uniqueptr<T>::operator bool() {
    return pointer != nullptr;
}

template <typename T>
void uniqueptr<T>::print_status() {
    if (!this->used) {
        std::cout << "Unused" << std::endl;
        return;
    }
    std::cout << "Used2" << '\n';
    std::cout << "Pointer being protected by the unique pointer: "<< this->pointer << std::endl;
};

// The member definitions above live in this translation unit, so the compiler
// only knows how to build them for the instantiations named explicitly here.
// Anything else (e.g. uniqueptr<double>) needs its own instantiation line, or
// the definitions have to live in uniqueptr.h.
template class uniqueptr<int>;

