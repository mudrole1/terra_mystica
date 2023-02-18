#ifndef ACTION_H
#define ACTION_H

#include <stdint.h>
#include <string>

enum class ActionType {
    UNDEFINED,
    TERRAFORM
};

class Action
{
public:
    ActionType get_type();
    virtual ~Action() = 0;

protected:
    ActionType type_ {ActionType::UNDEFINED};
};

#endif //ACTION_H