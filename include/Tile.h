#ifndef TILE_H
#define TILE_H

#include <memory>
#include <ostream>

#include "Building.h"

enum class Terrain {
    U = 30, P = 43, S = 100, L = 44, F = 42, M = 47, W = 41, D = 103, R =106
};

class Tile
{
public:
    Tile(Terrain type);
    void set_building(std::shared_ptr<Building> building);
    Terrain get_terrain();
    void set_terrain(Terrain terrain);
    void set_highlight(bool highlight);
    friend std::ostream& operator<<(std::ostream& os, const Tile& tile);

private:
    Terrain terrain_ {Terrain::U};
    bool occupied_ {false};
    bool highlight_ {false};
    std::shared_ptr<Building> building_ {nullptr};

};

#endif //TILE_H