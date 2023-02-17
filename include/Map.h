#ifndef MAP_H
#define MAP_H

#include <ostream>
#include <stdint.h>
#include <vector>

#include "Tile.h"

class Map
{
public:
    Map(const std::vector<std::vector<Tile>> & tiles);
    friend std::ostream& operator<<(std::ostream& os, const Map& map);

private:
    uint8_t rows_ {9};
    uint8_t columns_ {13};
    std::vector<std::vector<Tile>> tiles_ {};

};

#endif //MAP_H
