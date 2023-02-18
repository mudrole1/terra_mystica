#ifndef COORDINATE_H
#define COORDINATE_H

#include <stdint.h>

struct Coordinate
{
    Coordinate(uint8_t row, uint8_t column) {
        this->row = row; 
        this->column = column;
    }
    uint8_t row;
    uint8_t column;
};

#endif //COORDINATE_H