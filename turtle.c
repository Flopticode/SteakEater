#include "turtle.h"
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <string.h>

#include "logger.h"

bool turtle_forward(lua_State* lua, const char* err)
{
    // Load the ComputerCraft turtle API (assuming it's accessible in your environment)
    lua_getglobal(lua, "turtle");

    if (!lua_istable(lua, -1)) {
        strncpy((char*)err, "turtle API not found", TURTLE_MAX_ERRLEN);
        return false;
    }

    // Get the turtle.forward function
    lua_getfield(lua, -1, "forward");
    if (!lua_isfunction(lua, -1)) {
        strncpy((char*)err, "turtle.forward function not found", TURTLE_MAX_ERRLEN);
        return false;
    }

    // Call turtle.forward() with 0 arguments and 2 results
    if (lua_pcall(lua, 0, 2, 0) != LUA_OK) {
        strncpy((char*)err, lua_tostring(lua, -1), TURTLE_MAX_ERRLEN);
        return false;
    }

    // Get the boolean result
    bool success = lua_toboolean(lua, -2);

    // Get the error message if any
    if (!success && lua_isstring(lua, -1)) {
        strncpy((char*)err, lua_tostring(lua, -1), TURTLE_MAX_ERRLEN);
    } else {
        ((char*)err)[0] = '\0';  // No error
    }

    // Clean up the Lua state
    lua_pop(lua, 2);  // Pop the two results

    return success;
}

bool turtle_back(const char* err)
{

}

bool turtle_turn_left(const char* err)
{

}

bool turtle_turn_right(const char* err)
{

}
