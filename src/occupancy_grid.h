#ifndef OCCUPANCYGRID_H
#define OCCUPANCYGRID_H

#include <memory>

class OccupancyGrid
{
public:
    OccupancyGrid();

private:
    std::unique_ptr<char []> raw_data;
};

#endif // OCCUPANCYGRID_H
