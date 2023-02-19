#include <iostream>
#include <stdexcept>

#include "Faction.h"
#include "TerraFormAction.h"

Faction::Faction(std::shared_ptr<BoardMap> map, Terrain terrain)
 : map_(map), terrain_(terrain) 
{
    for(uint8_t i=0; i < num_dwellings_; ++i) {
        dwellings_.push(std::make_shared<Dwelling>(Dwelling()));
    }
}


void Faction::do_action() {
    std::vector<std::shared_ptr<Action>> actions = generate_all_actions_();
    uint8_t index {0};
    std::cout << "You can do these actions:\n";
    for(auto action : actions) {
        std::cout << (int) index << ": \t";
        index++;
        switch (action->get_type())
        {
        case ActionType::TERRAFORM:
            std::cout << *std::dynamic_pointer_cast<TerraFormAction>(action) << "\n";
            break;
        default:
            break;
        }
    }
    std::cout << *map_ << "\n";
    std::cout << "which one did you take?\n";
    int chosen_index;
    std::cin >> chosen_index;

    while((chosen_index < 0) || (chosen_index >= actions.size())) {
        std::cout << "wrong number, try again.";
        std::cin >> chosen_index;
    }

    std::shared_ptr<Action> chosen_action = actions.at(chosen_index);
    switch (chosen_action->get_type())
    {
    case ActionType::TERRAFORM:
        do_terraform_action_(chosen_action);
        break;
    default:
        break;
    }
}

std::vector<std::shared_ptr<Action>> Faction::generate_all_actions_() {
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

void Faction::do_terraform_action_(std::shared_ptr<Action> chosen_action) {
    std::shared_ptr<TerraFormAction> chosen_terra_form = std::dynamic_pointer_cast<TerraFormAction>(chosen_action);
    uint8_t worker_cost = chosen_terra_form->get_spades()*spade_cost_;
    if(workers_ < worker_cost) {
        throw std::logic_error("not enough workers for the chosen terraforming action\n");
    }
    map_->terraform(chosen_terra_form);
    workers_ = workers_ - worker_cost;
    std::cout << "Action " << *chosen_terra_form << "has been performed.\n";
    std::cout << *map_;
}
