#include "TerraFormAction.h"

TerraFormAction::TerraFormAction(Coordinate coordinate, Terrain from, Terrain to, uint8_t spades) 
 : coordinate_(coordinate), from_(from), to_(to), spades_(spades)
 {
    type_ = ActionType::TERRAFORM;
 }

uint8_t TerraFormAction::get_spades(){
    return spades_;
}

Coordinate TerraFormAction::get_coordinates() {
    return coordinate_;
}

Terrain TerraFormAction::get_final_terrain() {
    return to_;
}

std::ostream& operator<<(std::ostream& os, const TerraFormAction& action) {
    os << "terraform on coordinates (";
    if (action.coordinate_.row < 10) {
        os << " ";
    }
    os << (int) action.coordinate_.row;
    os << ",";
    if(action.coordinate_.column < 10) {
        os << " ";
    }
    os << (int) action.coordinate_.column;
    os << ") from terrain ";
    os << "\033[0;";
    os << (int)action.from_;
    os << "m  \033[0m";
    os << " to terrain ";
    os << "\033[0;";
    os << (int)action.to_;
    os << "m  \033[0m";
    os << " with ";
    os << (int) action.spades_;
    os << " spades";
    return os;
}