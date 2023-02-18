#ifndef BOARDMAP_H
#define BOARDMAP_H

#include <ostream>
#include <stdint.h>
#include <vector>
#include <map>

#include "Coordinate.h"
#include "Tile.h"

class BoardMap
{
public:
    BoardMap(const std::vector<std::vector<Tile>> & tiles);
    void build_dwelling(uint8_t row, uint8_t column, std::shared_ptr<Building> dwelling);
    void generate_single_directly_adjacent(Tile tile, uint8_t row, uint8_t column);
    std::vector<Coordinate> get_directly_adjacent_tiles(Terrain terrain);
    friend std::ostream& operator<<(std::ostream& os, const BoardMap& map);

private:
    uint8_t rows_ {9};
    uint8_t columns_ {13};
    std::vector<std::vector<Tile>> tiles_ {};
    std::map<Terrain, std::vector<Coordinate>> player_directly_adjacent_;

    std::vector<Coordinate> generate_neighbours_(uint8_t row, uint8_t column);
};

#endif //BOARDMAP_H