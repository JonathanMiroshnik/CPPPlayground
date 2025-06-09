#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Node {
    public:
        Node* next;
        void* value;
};

int main()
{
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2; // error: uses "v" not "v1"
    // error: cout not defined; should be std::cout
    std::cout << v1 + v2 << std::endl;
    return 0;
}