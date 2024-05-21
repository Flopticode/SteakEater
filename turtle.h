#pragma once

#include "types.h"
#include <lua.h>

#define TURTLE_MAX_ERRLEN 70

bool turtle_forward(lua_State* lua, const char* err);
bool turtle_back(const char* err);
bool turtle_turn_left(const char* err);
bool turtle_turn_right(const char* err);
