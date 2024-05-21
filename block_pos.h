#pragma once

#include "types.h"

typedef struct
{
    int64 x, y, z;
} BlockPos;

BlockPos blockpos_move(BlockPos pos, Vec3i delta);
