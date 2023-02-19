#include <iostream>
#include <vector>

#include "BoardMap.h"
#include "Coordinate.h"
#include "Dwelling.h"
#include "Faction.h"
#include "Game.h"
#include "TerraFormAction.h"
#include "Tile.h"

int main() {
    Game game {};
    game.add_player(Terrain::P);
    game.init_game();
    std::cout << "map generated\n" << game;

    game.play();

    std::cout << "end\n";
}