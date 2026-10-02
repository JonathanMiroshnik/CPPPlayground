//
// Created by jonathanmiroshnik on 01/10/2026.
//

#ifndef CPPLUA_UNIQUEPTR_H
#define CPPLUA_UNIQUEPTR_H


template <typename T>
class uniqueptr {
    public:
    uniqueptr(T* input_pointer);

    ~uniqueptr();

    T* operator=(T* input_pointer);
    T operator*();
    operator bool();

    void print_status();

    private:
    bool used = false;
    T* pointer;
};


#endif //CPPLUA_UNIQUEPTR_H
