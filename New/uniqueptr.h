//
// Created by jonathanmiroshnik on 01/10/2026.
//

#ifndef CPPLUA_UNIQUEPTR_H
#define CPPLUA_UNIQUEPTR_H
#include <cstdlib>


class uniqueptr {
    public:
    uniqueptr(void* input_pointer) {
        if (used) return;
        pointer = input_pointer;
        used = true;
    }

    ~uniqueptr() {
        if (used) {
            free(pointer);
        }
        used = false;
    }

    void print_status();

    private:
    bool used = false;
    void* pointer;
};


#endif //CPPLUA_UNIQUEPTR_H
