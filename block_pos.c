#include "block_pos.h"

BlockPos blockpos_move(BlockPos pos, Vec3i delta)
{
    return (BlockPos) {
        pos.x + delta.x,
        pos.y + delta.y,
        pos.z + delta.z
    };
}