#pragma once

#include "types.h"

typedef enum
{
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
} Direction;

Direction direction_get_opposite(Direction dir);
Direction direction_turn_left(Direction dir);
Direction direction_turn_right(Direction dir);
Vec3i direction_get_forward_vec(Direction dir);
