#ifndef TERRAFORMACTION_H
#define TERRAFORMACTION_H

#include <ostream>
#include <stdint.h>
#include <string>

#include "Action.h"
#include "Coordinate.h"

class TerraFormAction : public Action
{
public:
    TerraFormAction(Coordinate coordinate);
    friend std::ostream& operator<<(std::ostream& os, const TerraFormAction& action);
private:
    Coordinate coordinate_;
};

#endif //TERRAFORMACTION_H