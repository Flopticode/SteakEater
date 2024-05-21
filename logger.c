#include <lua.h>
#include "logger.h"

void logger_info(lua_State *L, const char* message) {
    // Push the print function onto the stack
    lua_getglobal(L, "print");
    
    // Push the message onto the stack
    lua_pushstring(L, message);
    
    // Call the print function with 1 argument and 0 results
    if (lua_pcall(L, 1, 0, 0) != LUA_OK) {
        // Handle error (optional)
        const char *error_msg = lua_tostring(L, -1);
        lua_pop(L, 1);  // Pop the error message from the stack
    }
}