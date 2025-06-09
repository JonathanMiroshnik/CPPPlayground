// Use the following line in the terminal to compile:
// g++ -Wall -Wextra -Werror main.cpp -o main
// To run on Linux: ./main


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Hello {
    public:
        Hello() {
            yoo = 4;
        }

        int yoo = 3;

        int hello() {
            std::cout << "Hello!" << "\n";
            return 0;
        }
};

class Singleton {
    private:
        static Singleton *singleton;
        char* msg;

    public:
        Singleton() {
            if (singleton != nullptr) {
                return;    
            }
            singleton = new Singleton();
        }

        void print(const char* new_msg = nullptr) {
            if (new_msg != nullptr) {
                msg = (char *) malloc(strlen(new_msg));
                strcpy(msg, new_msg);
            }

            std::cout << msg;          
        }

        void operator delete(void*) {
            if (singleton == nullptr) {
                return;
            }
            if ((*singleton).msg != nullptr) {
                delete (*singleton).msg;
                delete singleton;
            }
        }
};

int main() {
    std::cout << "Hello World!";
    Hello *love = new Hello();
    (*love).hello();

    std::cout << (*love).yoo;


    Singleton sing = Singleton();
    const char* new_msg = "love";
    sing.print(new_msg);

    // Singleton sing2;
    // sing2.print();

    delete sing;
    delete love;

    return 0;
}