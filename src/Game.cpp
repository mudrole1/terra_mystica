#include "Game.h"
#include "Tile.h"

Game::Game(){
    generate_standard_map_();
}

void Game::add_player(Terrain terrain) {
    players_.push_back(Faction(map_, terrain));
}

void Game::init_game() {
    map_->build_dwelling(0,0, std::make_shared<Dwelling>());
    map_->build_dwelling(3,11, std::make_shared<Dwelling>());
}

void Game::play() {
    for (Faction player: players_) {
        player.do_action();
    }
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    os << *game.map_;
    return os;
}

void Game::generate_standard_map_() {
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

    map_ = std::make_shared<BoardMap>(tiles);
}