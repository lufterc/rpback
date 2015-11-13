#include "occupancy_grid.h"
using namespace std;

OccupancyGrid::OccupancyGrid()
{
    raw_data = unique_ptr<char []>(new char[132]);
}
