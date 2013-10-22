/*
 * Cell.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: Gary
 */

#include "Cell.h"

Cell::Cell()
{
    occupied = false;
    this->type = CellType::Empty;
    this->x = 0;
    this->y = 0;
}

Cell::Cell(CellType cellType)
{
    occupied = false;
    this->type = cellType;
    this->x = 0;
    this->y = 0;
}

Cell::~Cell()
{
    // TODO Auto-generated destructor stub
}

Cell::CellType Cell::getType()
{
    return type;
}

void Cell::setX(int x)
{
    this->x = x;
}

void Cell::setY(int y)
{
    this->y = y;
}

int Cell::getX()
{
    return x;
}

int Cell::getY()
{
    return y;
}