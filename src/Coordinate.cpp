#include "Coordinate.h"

bool operator==(const Coordinate& coord1, const Coordinate& coord2) {
    bool rows = (coord1.row == coord2.row);
    bool columns = (coord1.column == coord2.column);
    return rows && columns;
}