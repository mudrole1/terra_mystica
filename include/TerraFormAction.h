#ifndef TERRAFORMACTION_H
#define TERRAFORMACTION_H

#include <ostream>
#include <stdint.h>
#include <string>

#include "Action.h"
#include "Coordinate.h"
#include "Tile.h"

class TerraFormAction : public Action
{
public:
    TerraFormAction(Coordinate coordinate, Terrain from,  Terrain to, uint8_t spades);
    uint8_t get_spades();
    Coordinate get_coordinates();
    Terrain get_final_terrain();
    friend std::ostream& operator<<(std::ostream& os, const TerraFormAction& action);
private:
    Coordinate coordinate_;
    Terrain from_ {Terrain::U};
    Terrain to_ {Terrain::U};
    uint8_t spades_ {0};

};

#endif //TERRAFORMACTION_H