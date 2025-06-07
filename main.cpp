// Use the following line in the terminal to compile:
// g++ -Wall -Wextra -Werror main.cpp -o main
// To run on Linux: ./main


#include <iostream>

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

int main() {
  std::cout << "Hello World!";
  Hello *love = new Hello();
  (*love).hello();

  std::cout << (*love).yoo;
  return 0;
}