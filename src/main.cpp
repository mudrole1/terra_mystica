#include <iostream> 
#include <vector>

#include "Map.h"
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

    Map map {tiles};
    std::cout << "map generated\n" << map;
}