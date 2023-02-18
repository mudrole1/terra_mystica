#include "Tile.h"

Tile::Tile(Terrain terrain)
 : terrain_(terrain) {}

void Tile::set_building(std::shared_ptr<Building> building) {
   building_ = building;
   occupied_ = true;
}

std::ostream& operator<<(std::ostream& os, const Tile& tile) {
   os << "\033[0;";
   os << (int)tile.terrain_;
   os << "m";
   if(tile.building_ != nullptr) {
      os << "D ";
   } else {
      os << "  ";
   }
   os << "\033[0m";
   return os;
}