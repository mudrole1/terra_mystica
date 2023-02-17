#include "Tile.h"

Tile::Tile(Terrain terrain)
 : terrain_(terrain) {}

 std::ostream& operator<<(std::ostream& os, const Tile& tile) {
    os << "\033[0;";
    os << (int)tile.terrain_;
    os << "m..\033[0m";
    return os;
 }