#ifndef BOARDMAP_H
#define BOARDMAP_H

#include <ostream>
#include <stdint.h>
#include <vector>

#include "Tile.h"

class BoardMap
{
public:
    BoardMap(const std::vector<std::vector<Tile>> & tiles);
    void build_dwelling(uint8_t row, uint8_t column, std::shared_ptr<Building> dwelling);
    friend std::ostream& operator<<(std::ostream& os, const BoardMap& map);

private:
    uint8_t rows_ {9};
    uint8_t columns_ {13};
    std::vector<std::vector<Tile>> tiles_ {};

};

#endif //BOARDMAP_H