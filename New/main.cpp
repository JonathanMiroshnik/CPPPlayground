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
	auto up1 = new uniqueptr<int>(intpointer);
	up1->print_status();
	if (up1) std::cout << "here1" << '\n';
	delete up1;
	up1->print_status();
	if (up1) std::cout << "here2" << '\n';

	return 0;
}
