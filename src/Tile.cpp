#include "Tile.h"

Tile::Tile(Terrain terrain)
 : terrain_(terrain) {}

void Tile::set_building(std::shared_ptr<Building> building) {
   building_ = building;
   occupied_ = true;
}

Terrain Tile::get_terrain() {
   return terrain_;
}

void Tile::set_terrain(Terrain terrain) {
   terrain_ = terrain;
}

void Tile::set_highlight(bool highlight)
{
   highlight_ = highlight;
}

bool Tile::get_occupied() {
   return occupied_;
}

std::ostream& operator<<(std::ostream& os, const Tile& tile) {
   if(tile.highlight_) {
      os << "\033[5;";
   } else {
      os << "\033[0;";
   }
   os << (int)tile.terrain_;
   os << "m";
   if(tile.building_ != nullptr) {
      os << "D";
   } else {
      os << " ";
   }
   if(tile.highlight_) {
      os << "*";
   } else {
      os << " ";
   }
   os << "\033[0m";
   return os;
}