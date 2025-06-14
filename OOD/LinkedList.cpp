#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#include "Ultra.h"

using namespace std;

class Node {
    public:
        Node* next;
        void* value;
};

int main()
{
    // int v1 = 0, v2 = 0;
    // cin >> v1 >> v2; // error: uses "v" not "v1"
    // // error: cout not defined; should be std::cout
    // cout << v1 + v2 << std::endl;

    // Ultra u;
    
    // cout << u.i << std::endl;

    // string h(5, 'h');
    // cout << *(&h) << std::endl;

    int i = 1, j = 2;//, k = 3;
    if (i < j) {
        cout << true << endl;
    }

    const char *cp = "Hello World";
    if (cp && *cp) {
        cout << cp << endl;
    }

    vector<string> v7(10, "hi");
    for (auto s : v7) {
        cout << s << endl;
    }    

    string line;
    // read input a line at a time until end-of-file
    while (getline(cin, line))
    if (!line.empty())
        cout << line << endl;
    else
        break;

    return 0;
}