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

    // uniqueptr owns its pointee exclusively, so copying or copy-assigning one
    // from another would duplicate ownership and let two destructors free the
    // same pointer. Take ownership of a raw T* instead.
    uniqueptr(const uniqueptr&) = delete;
    uniqueptr& operator=(const uniqueptr&) = delete;

    T* get();
    T* release();
    void reset(T*);
    void swap(uniqueptr<T> &);

    uniqueptr& operator=(T* input_pointer);
    T& operator*();
    explicit operator bool();

    void print_status();

    private:
    T* pointer = nullptr;
};


#endif //CPPLUA_UNIQUEPTR_H
