#include "direction.h"

Direction direction_turn_left(Direction dir)
{
    if(dir == NORTH)
        return WEST;
    return dir - 1;
}

Direction direction_turn_right(Direction dir)
{
    if(dir == WEST)
        return NORTH;
    return dir + 1;
}

Direction direction_get_opposite(Direction dir)
{
    return direction_turn_left(direction_turn_left(dir));
}

Vec3i direction_get_forward_vec(Direction dir)
{
    switch (dir)
    {
        case NORTH:
            return (Vec3i){0, 0, -1};
        case EAST:
            return (Vec3i){1, 0, 0};
        case SOUTH:
            return (Vec3i){0, 0, 1};
        case WEST:
            return (Vec3i){-1, 0, 0};
    }
}
