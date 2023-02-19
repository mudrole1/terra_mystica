#include <iostream>
#include <vector>

#include "BoardMap.h"
#include "Coordinate.h"
#include "Dwelling.h"
#include "Faction.h"
#include "TerraFormAction.h"
#include "Tile.h"

int main() {
    std::vector<std::vector<Tile>> tiles {};
    std::vector<Tile> row {};
    row.push_back(Terrain::P);
    row.push_back(Terrain::M);
    row.push_back(Terrain::F);
    row.push_back(Terrain::L);
    row.push_back(Terrain::D);
    row.push_back(Terrain::W);
    row.push_back(Terrain::P);
    row.push_back(Terrain::S);
    row.push_back(Terrain::W);
    row.push_back(Terrain::F);
    row.push_back(Terrain::L);
    row.push_back(Terrain::W);
    row.push_back(Terrain::S);
    tiles.push_back(row);
    row.clear();

    row.push_back(Terrain::D);
    row.push_back(Terrain::R);
    row.push_back(Terrain::R);
    row.push_back(Terrain::P);
    row.push_back(Terrain::S);
    row.push_back(Terrain::R);
    row.push_back(Terrain::R);
    row.push_back(Terrain::D);
    row.push_back(Terrain::S);
    row.push_back(Terrain::R);
    row.push_back(Terrain::R);
    row.push_back(Terrain::D);
    row.push_back(Terrain::U);
    tiles.push_back(row);
    row.clear();

    row.push_back(Terrain::R);
    row.push_back(Terrain::R);
    row.push_back(Terrain::S);
    row.push_back(Terrain::R);
    row.push_back(Terrain::M);
    row.push_back(Terrain::R);
    row.push_back(Terrain::F);
    row.push_back(Terrain::R);
    row.push_back(Terrain::F);
    row.push_back(Terrain::R);
    row.push_back(Terrain::M);
    row.push_back(Terrain::R);
    row.push_back(Terrain::R);
    tiles.push_back(row);
    row.clear();

    row.push_back(Terrain::F);
    row.push_back(Terrain::L);
    row.push_back(Terrain::D);
    row.push_back(Terrain::R);
    row.push_back(Terrain::R);
    row.push_back(Terrain::W);
    row.push_back(Terrain::L);
    row.push_back(Terrain::R);
    row.push_back(Terrain::W);
    row.push_back(Terrain::R);
    row.push_back(Terrain::W);
    row.push_back(Terrain::P);
    row.push_back(Terrain::U);
    tiles.push_back(row);
    row.clear();

    row.push_back(Terrain::S);
    row.push_back(Terrain::P);
    row.push_back(Terrain::W);
    row.push_back(Terrain::L);
    row.push_back(Terrain::S);
    row.push_back(Terrain::P);
    row.push_back(Terrain::M);
    row.push_back(Terrain::D);
    row.push_back(Terrain::R);
    row.push_back(Terrain::R);
    row.push_back(Terrain::F);
    row.push_back(Terrain::S);
    row.push_back(Terrain::L);
    tiles.push_back(row);
    row.clear();

    row.push_back(Terrain::M);
    row.push_back(Terrain::F);
    row.push_back(Terrain::R);
    row.push_back(Terrain::R);
    row.push_back(Terrain::D);
    row.push_back(Terrain::F);
    row.push_back(Terrain::R);
    row.push_back(Terrain::R);
    row.push_back(Terrain::R);
    row.push_back(Terrain::P);
    row.push_back(Terrain::M);
    row.push_back(Terrain::P);
    row.push_back(Terrain::U);
    tiles.push_back(row);
    row.clear();

    row.push_back(Terrain::R);
    row.push_back(Terrain::R);
    row.push_back(Terrain::R);
    row.push_back(Terrain::M);
    row.push_back(Terrain::R);
    row.push_back(Terrain::W);
    row.push_back(Terrain::R);
    row.push_back(Terrain::F);
    row.push_back(Terrain::R);
    row.push_back(Terrain::D);
    row.push_back(Terrain::S);
    row.push_back(Terrain::L);
    row.push_back(Terrain::D);
    tiles.push_back(row);
    row.clear();

    row.push_back(Terrain::D);
    row.push_back(Terrain::L);
    row.push_back(Terrain::P);
    row.push_back(Terrain::R);
    row.push_back(Terrain::R);
    row.push_back(Terrain::R);
    row.push_back(Terrain::L);
    row.push_back(Terrain::S);
    row.push_back(Terrain::R);
    row.push_back(Terrain::M);
    row.push_back(Terrain::P);
    row.push_back(Terrain::M);
    row.push_back(Terrain::U);
    tiles.push_back(row);
    row.clear();

    row.push_back(Terrain::W);
    row.push_back(Terrain::S);
    row.push_back(Terrain::M);
    row.push_back(Terrain::L);
    row.push_back(Terrain::W);
    row.push_back(Terrain::F);
    row.push_back(Terrain::D);
    row.push_back(Terrain::P);
    row.push_back(Terrain::M);
    row.push_back(Terrain::R);
    row.push_back(Terrain::L);
    row.push_back(Terrain::F);
    row.push_back(Terrain::W);
    tiles.push_back(row);
    row.clear();

    std::shared_ptr<BoardMap> map = std::make_shared<BoardMap>(tiles);
    std::shared_ptr<Building> house =std::make_shared<Dwelling>();
    map->build_dwelling(0,0, house);
    map->build_dwelling(3,11, std::make_shared<Dwelling>());
    std::cout << "map generated\n" << *map;

    std::vector<Coordinate> neighbour_tiles = map->get_directly_adjacent_tiles(Terrain::P);
    for (auto tile : neighbour_tiles) {
        std::cout << (int) tile.row << " " << (int) tile.column << "\n";
    }

    Faction plains (map, Terrain::P);
    plains.do_action();

    std::cout << "end\n";
}