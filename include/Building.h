#ifndef BUILDING_H
#define BUILDING_H

#include <stdint.h>

class Building
{
public:
    virtual ~Building() = 0;

protected:
    uint8_t workers_cost_ {0};
    uint8_t coins_cost_ {0};
};

#endif //BUILDING_H