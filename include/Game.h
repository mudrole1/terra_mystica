#ifndef GAME_H
#define GAME_H

#include <ostream>
#include <vector>

#include "BoardMap.h"
#include "Faction.h"

class Game {
public:
    Game();
    void add_player(Terrain terrain);
    void init_game();
    void play();
    
    friend std::ostream& operator<<(std::ostream& os, const Game& game);

private:
    std::vector<Faction> players_;
    std::shared_ptr<BoardMap> map_;

    void generate_standard_map_();
};
#endif //GAME_H