#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include <math.h>

#include "gps.h"
#include "logger.h"
#include "turtle.h"

// Function to add two numbers
static int l_calibrate(lua_State *lua)
{
    double xd = luaL_checknumber(lua, 1);
    double yd = luaL_checknumber(lua, 2);
    double zd = luaL_checknumber(lua, 3);
    double rd = luaL_checknumber(lua, 4);

    if(xd != round(xd) || yd != round(yd) || zd != round(zd) || rd != round(rd))
    {
        lua_pushboolean(lua, false);
        return 1;
    }

    int64 x = (int64)xd;
    int64 y = (int64)yd;
    int64 z = (int64)zd;
    int64 r = (int64)rd;

    if(r < 0 || r > 3)
    {
        lua_pushboolean(lua, false);
        return 1;
    }

    calibrate((BlockPos){x, y, z}, (Direction)r);

    lua_pushboolean(lua, true);
    return 1;
}
static int l_forward(lua_State *lua)
{
    const char err[TURTLE_MAX_ERRLEN];
    
    bool success = forward(lua, err);
    lua_pushboolean(lua, success);

    if(!success)
    {
        lua_pushstring(lua, err);
        return 2;
    }
    return 1;
}

// Register functions
static const struct luaL_Reg libsteakeater [] = {
    {"calibrate", l_calibrate},
    {"forward", l_forward},
    {NULL, NULL}  // sentinel to signal end of array
};

// Open library
int luaopen_libsteakeater(lua_State *lua)
{
    luaL_newlib(lua, libsteakeater);
    return 1;
}