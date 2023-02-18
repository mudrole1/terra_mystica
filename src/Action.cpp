#include "Action.h"

Action::~Action() {}

ActionType Action::get_type() {
    return type_;
}