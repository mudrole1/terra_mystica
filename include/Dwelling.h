#ifndef DWELLING_H
#define DWELLING_H

#include <stdint.h>

#include "Building.h"

class Dwelling : public Building 
{
public:
    Dwelling();
    Dwelling(bool provides_worker);
    Dwelling(uint8_t workers_cost, uint8_t coins_cost, bool provides_worker);
private:
    bool provides_worker_ {true};
};

#endif //DWELLING_H
