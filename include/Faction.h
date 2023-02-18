#include <memory>
#include <stack>
#include <stdint.h>
#include <vector>

#include "Action.h"
#include "BoardMap.h"
#include "Dwelling.h"
#include "Tile.h"

class Faction
{
public:
    Faction(std::shared_ptr<BoardMap> map, Terrain terrain);
    std::vector<std::shared_ptr<Action>> generate_all_actions();

private:
    std::shared_ptr<BoardMap> map_ {nullptr};
    Terrain terrain_;
    uint8_t workers_ {1};
    uint8_t coins_ {15};

    const uint8_t num_dwellings_ {8};
    std::stack<std::shared_ptr<Dwelling>> dwellings_ {};
    std::vector<std::shared_ptr<Action>> generate_terra_form_actions_();

};