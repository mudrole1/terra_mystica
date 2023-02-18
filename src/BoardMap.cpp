#include "BoardMap.h"

BoardMap::BoardMap(const std::vector<std::vector<Tile>> & tiles)
  : tiles_(tiles) {}

void BoardMap::build_dwelling(uint8_t row, uint8_t column, std::shared_ptr<Building> dwelling)
{
    tiles_.at(row).at(column).set_building(dwelling);
    generate_single_directly_adjacent(tiles_.at(row).at(column), row, column);
}
std::ostream& operator<<(std::ostream& os, const BoardMap& map) {
    for (uint8_t i = 0; i < map.rows_; ++i) {
        for (uint8_t j = 0; j < map.columns_; ++j) {
            if((i % 2 == 1) && (j == 0)) {
                os << " ";
            }
            os << map.tiles_.at(i).at(j);
        }
        os << "\n";
    }
    return os;
}