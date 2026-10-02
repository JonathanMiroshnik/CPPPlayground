#include <iostream>
#include "uniqueptr.h"

#include "lua.hpp"

// class Agent {
// 	// TODO: Get the initial master prompt from some file
// 	static const std::string = getFile(TODO);
//
//
// 	constructor {
// 		lua_State* L = luaL_newstate();
// 		std::vector<Node*> nodes = new std::vector<Node*>();
// 	}
//
// 	std::string createStrategy(LLMConnection conn) {
// 		// TODO: Create the req by getting information on all the nodes and adding in a master prompt of some sort
// 		return conn.sendRequest(req);
// 	}
// }
//
// class LLMConnection {
// 	constructor {
// 		std::string url;
// 		std::string model;
// 	}
//
// 	std::string sendRequest(std::string request) {
// 		url -> HTTP sendRequest(request, model);
// 	}
// }

int main() {
	std::cout << "Hello World2!" << std::endl;

	// Lua portion tests ----------------------------------------------------------------------------

	// lua_State* L = luaL_newstate();
	// luaL_dostring(L, "print(\"hello\")");
	// lua_close(L);

	// Lua portion tests ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

	int* intpointer = static_cast<int *>(malloc(sizeof(int)));
	*intpointer = 42;

	// Stack-allocated unique pointer: no `new`, no `delete`, so there is no leak
	// and no use-after-free. The destructor runs automatically at the end of main.
	uniqueptr<int> up1{intpointer};
	up1.print_status();                        // Used2 + the address it owns
	std::cout << "*up1 = " << *up1 << '\n';    // 42: operator* returns a reference
	if (up1) std::cout << "here1" << '\n';     // true: we still own the pointer

	up1 = nullptr;                             // release early (frees intpointer)
	std::cout << "after release: ";
	up1.print_status();                        // Unused
	if (up1) std::cout << "here2" << '\n';     // false: nothing is printed

	return 0;
}
