#include "Map.h"

 Map::Map(const std::vector<std::vector<Tile>> & tiles)
  : tiles_(tiles) {}

std::ostream& operator<<(std::ostream& os, const Map& map) {
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