#ifndef TILE_H
#define TILE_H

#include <ostream>

enum class Terrain {
    U = 30, P = 43, S = 100, L = 44, F = 42, M = 47, W = 41, D = 103, R =46
};

class Tile
{
public:
    Tile(Terrain type);
    friend std::ostream& operator<<(std::ostream& os, const Tile& tile);

private:
    Terrain terrain_ {Terrain::U};
    bool occupied_ {false};

};

#endif //TILE_H