#include "gps.h"
#include "turtle.h"

struct
{
    bool calibrated;
    BlockPos pos;
    Direction rot;
} gps;

void set_position(BlockPos newPos)
{
    gps.pos = newPos;
}
void set_rotation(Direction newRot)
{
    gps.rot = newRot;
}

void calibrate(BlockPos pos, Direction rot)
{
    set_position(pos);
    set_rotation(rot);
    gps.calibrated = true;
}
bool forward(lua_State* lua, const char* err)
{
    if(!turtle_forward(lua, err))
        return false;
    set_position(blockpos_move(gps.pos, direction_get_forward_vec(gps.rot)));
    return true;
}
bool back(const char* err)
{
    if(!turtle_back(err))
        return false;
    set_position(
        blockpos_move(gps.pos,
            direction_get_forward_vec(
                direction_get_opposite(gps.rot))));
    return true;
}
bool turn_left(const char* err)
{
    if(!turtle_turn_left(err))
        return false;
    set_rotation(direction_turn_left(gps.rot));
    return true;
}
bool turn_right(const char* err)
{
    if(!turtle_turn_right(err))
        return false;
    set_rotation(direction_turn_right(gps.rot));
    return true;
}
