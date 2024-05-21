#pragma once

#include <lua.h>
#include "types.h"

#include "block_pos.h"
#include "direction.h"

void calibrate(BlockPos pos, Direction rot);
bool forward(lua_State* lua, const char* err);
bool back(const char* err);
bool turn_left(const char* err);
bool turn_right(const char* err);
