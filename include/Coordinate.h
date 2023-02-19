#ifndef COORDINATE_H
#define COORDINATE_H

#include <stdint.h>

struct Coordinate
{
    Coordinate(uint8_t row, uint8_t column) {
        this->row = row; 
        this->column = column;
    }
    friend bool operator==(const Coordinate& coord1, const Coordinate& coord2);
    uint8_t row;
    uint8_t column;
};

#endif //COORDINATE_H