# =============================================================================
#  cpplua - C++ playground
#
#  Quick start:
#      make            # build ./build/cpplua
#      make run        # build and run
#      make clean      # delete build artefacts
#      make rebuild    # clean + build
#
#  VS Code: the default build task (Ctrl+Shift+B / Cmd+Shift+B) runs `make`,
#           and F5 (Start Debugging) builds first via the same task. See
#           .vscode/ for the task, launch and IntelliSense configuration.
# =============================================================================

# -----------------------------------------------------------------------------
# Toolchain
# -----------------------------------------------------------------------------
CXX      ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -Wpedantic -g -O0
CPPFLAGS ?=
LDFLAGS  ?=

# -----------------------------------------------------------------------------
# Project layout
# -----------------------------------------------------------------------------
TARGET   := cpplua
BUILD    := build

SRCS     := main.cpp uniqueptr.cpp
HEADERS  := uniqueptr.h

# Vendor headers (Lua). main.cpp does `#include "lua.hpp"`.
INCLUDES := -I. -Ithird_party/lua/include

OBJS     := $(patsubst %.cpp,$(BUILD)/%.o,$(SRCS))
DEPS     := $(OBJS:.o=.d)

# -----------------------------------------------------------------------------
# Lua
# -----------------------------------------------------------------------------
# Only the Lua *headers* are vendored under third_party/lua/include, so we link
# against whatever Lua runtime is installed on the system. Ubuntu/Debian ship
# liblua5.x.so.0 without the -dev symlink, hence the `-l:libluaX.Y.so.0` form.
# Override on the command line if needed, e.g.
#     make LUA_LIBS="-L/opt/lua/lib -llua5.4"
MULTIARCH := $(shell $(CXX) -dumpmachine)
LUA_LIBS  ?= $(firstword $(foreach v,5.4 5.3 5.2,\
                $(if $(wildcard /usr/lib/$(MULTIARCH)/liblua$(v).so.0),-l:liblua$(v).so.0)))
LDLIBS    ?= $(LUA_LIBS) -lm -ldl

# -----------------------------------------------------------------------------
# Rules
# -----------------------------------------------------------------------------
.PHONY: all run clean rebuild

all: $(BUILD)/$(TARGET)

$(BUILD)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(BUILD)/%.o: %.cpp $(HEADERS) | $(BUILD)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

$(BUILD):
	mkdir -p $(BUILD)

run: $(BUILD)/$(TARGET)
	./$(BUILD)/$(TARGET)

clean:
	rm -rf $(BUILD)

rebuild: clean all

-include $(DEPS)
