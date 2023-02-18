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
    Terrain get_terrain(Coordinate coordinate);
    uint8_t distance_between_terrains(Terrain terrain1, Terrain terrain2);
    void highlight_tile(Coordinate coordinate);
    friend std::ostream& operator<<(std::ostream& os, const BoardMap& map);

private:
    uint8_t rows_ {9};
    uint8_t columns_ {13};
    const std::vector<Terrain> terrain_distances_ {Terrain::P, Terrain::S, Terrain::L, Terrain::F, Terrain::M, Terrain::W, Terrain::D};
    std::vector<std::vector<Tile>> tiles_ {};
    std::map<Terrain, std::vector<Coordinate>> player_directly_adjacent_;

    std::vector<Coordinate> generate_neighbours_(uint8_t row, uint8_t column);
};

#endif //BOARDMAP_H