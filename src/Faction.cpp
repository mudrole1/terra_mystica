#include "Faction.h"
#include "TerraFormAction.h"

Faction::Faction(std::shared_ptr<BoardMap> map, Terrain terrain)
 : map_(map), terrain_(terrain) 
{
    for(uint8_t i=0; i < num_dwellings_; ++i) {
        dwellings_.push(std::make_shared<Dwelling>(Dwelling()));
    }
}

std::vector<std::shared_ptr<Action>> Faction::generate_all_actions() {
    std::vector<std::shared_ptr<Action>> all_actions = generate_terra_form_actions_();
    return all_actions;
}

std::vector<std::shared_ptr<Action>> Faction::generate_terra_form_actions_() {
    std::vector<std::shared_ptr<Action>> output;
    std::vector<Coordinate> da_tiles = map_->get_directly_adjacent_tiles(terrain_);
    for (auto tile : da_tiles) {
        Terrain da_terrain = map_->get_terrain(tile);
        if(da_terrain == Terrain::R) {
            continue;
        }
        map_->highlight_tile(tile);
        std::vector<Terrain> all_other_terrains = map_->generate_all_other_terrains(da_terrain);
        for (Terrain other_terrain: all_other_terrains) {
            uint8_t cost_in_spades = map_->distance_between_terrains(da_terrain, other_terrain);
            uint8_t cost_in_workers = cost_in_spades * spade_cost_;
            if (cost_in_workers <= workers_) {
                output.push_back(std::make_shared<TerraFormAction>(TerraFormAction(tile, da_terrain, other_terrain, cost_in_spades)));
            }
        }
    }
    return output;
}

