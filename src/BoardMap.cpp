#include "BoardMap.h"

BoardMap::BoardMap(const std::vector<std::vector<Tile>> & tiles)
  : tiles_(tiles) {}

void BoardMap::build_dwelling(uint8_t row, uint8_t column, std::shared_ptr<Building> dwelling)
{
    tiles_.at(row).at(column).set_building(dwelling);
    generate_single_directly_adjacent(tiles_.at(row).at(column), row, column);
}

void BoardMap::generate_single_directly_adjacent(Tile tile, uint8_t row, uint8_t column) {
    Terrain terrain = tile.get_terrain();
    std::vector<Coordinate> neighbour_tiles = generate_neighbours_(row, column);
    auto it = player_directly_adjacent_.find(terrain);
    if (it == player_directly_adjacent_.end()) {
        player_directly_adjacent_.insert(std::pair<Terrain, std::vector<Coordinate>>(terrain, neighbour_tiles));
    } else {
        player_directly_adjacent_.at(terrain).insert(player_directly_adjacent_.at(terrain).end(), neighbour_tiles.begin(), neighbour_tiles.end());
    }
}

std::vector<Coordinate> BoardMap::get_directly_adjacent_tiles(Terrain terrain) {
    return player_directly_adjacent_.at(terrain);
}

std::vector<Coordinate> BoardMap::generate_neighbours_(uint8_t row, uint8_t column) {
    std::vector<Coordinate> neighbours;
    int8_t which_neighbour {0};
    uint8_t upper_column_limit {0};
    if(row % 2 == 1) {
        which_neighbour = 1;
        upper_column_limit = columns_ - 2;
    } else {
        which_neighbour = -1;
        upper_column_limit = columns_ - 1;
    }

    int8_t new_column = column+which_neighbour;

    //row above
    if(row > 0) {
        neighbours.push_back(Coordinate(row-1, column));
        if((new_column >= 0) && (new_column < columns_)) {
            neighbours.push_back(Coordinate(row-1, new_column));
        }
    }

    //same row
    if(column > 0) {
        neighbours.push_back(Coordinate(row, column-1));
    }
    if (column < upper_column_limit) {
        neighbours.push_back(Coordinate(row, column+1));
    }

    //row below
    if (row < (rows_-1)) {
        neighbours.push_back(Coordinate(row+1, column));
        if((new_column >= 0) && (new_column < columns_)) {
            neighbours.push_back(Coordinate(row+1, column+which_neighbour));
        }
    }
    return neighbours;
}

Terrain BoardMap::get_terrain(Coordinate coordinate) {
    return tiles_.at(coordinate.row).at(coordinate.column).get_terrain();
}

uint8_t BoardMap::distance_between_terrains(Terrain terrain1, Terrain terrain2) {
    uint8_t position1 {0};
    uint8_t position2 {0};
    if (terrain1 == terrain2) {
        return 0;
    }
    for(uint8_t i = 0; i < terrain_distances_.size(); ++i) {
        if(terrain_distances_.at(i)== terrain1) {
            position1 = i;
        }
        if(terrain_distances_.at(i)== terrain2) {
            position2 = i;
        }
    }
    uint8_t distance {0};
    if (position1 > position2) {
        distance = position1 - position2;
    } else {
        distance = position2 - position1;
    }
    if(distance > (terrain_distances_.size()/2)) {
        distance = terrain_distances_.size() - distance;
    }
    return distance;
}

void BoardMap::highlight_tile(Coordinate coordinate)
{
    tiles_.at(coordinate.row).at(coordinate.column).set_highlight(true);
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