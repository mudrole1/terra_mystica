#include "TerraFormAction.h"

TerraFormAction::TerraFormAction(Coordinate coordinate) 
 : coordinate_(coordinate)
 {
    type_ = ActionType::TERRAFORM;
 }

std::ostream& operator<<(std::ostream& os, const TerraFormAction& action) {
    os << "terraform on coordinates (";
    os << (int) action.coordinate_.row;
    os << ",";
    os << (int) action.coordinate_.column;
    os << ")";
    return os;
}