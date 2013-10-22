/*
 * PathFinder.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: Gary
 */

#include "Path.h"

Path::Path(std::shared_ptr<std::vector<std::vector<std::shared_ptr<Cell>>>> m, int width, int height)
{
    matrix = m;
    mapWidth = width;
    mapHeight = height;
}

Path::~Path()
{
    matrix.reset();
}

bool Path::validPath(Cell src, Cell dest)
{
    return findPath(src, dest) != nullptr;
}

std::shared_ptr<std::vector<PathUnit>> Path::findPath(Cell src, Cell dest)
{
    std::vector<PathUnit> path;
    path.push_back(PathUnit(src.getX(), src.getY()));

    bool destinationFound = false;
    unsigned int depth = 0;
    int destinationDepth = 0;
    while (!destinationFound || depth < path.size())
    {
        std::vector<PathUnit> currentNeighbors(path[depth].getNeighbors());

        // Filter neighbors
        std::vector<PathUnit> filteredNeighbors(validateNeighbors(currentNeighbors, path));

        // Copy valid neighbors to path
        for (std::vector<PathUnit>::iterator it = filteredNeighbors.begin(); it != filteredNeighbors.end(); it++)
        {
            path.push_back(*it);
        }

        // Check for destination in filteredNeighbors
        if (PathUnit(dest.getX(), dest.getY()).containedIn(path))
        {
            // Destination is found
            destinationFound = true;
            destinationDepth = depth;
        }
        depth++;
    }

    if (!destinationFound)
    {
        return nullptr;
    }
    else
    {
        std::vector<PathUnit> finalPath(getShortestPath(path, destinationDepth));
        return std::make_shared<std::vector<PathUnit>>(finalPath);
    }
}

std::vector<PathUnit> Path::validateNeighbors(std::vector<PathUnit> v, std::vector<PathUnit> path)
{
    std::vector<PathUnit> goodPathUnits;

    for (std::vector<PathUnit>::iterator it = v.begin(); it != v.end(); it++)
    {
        // Checking boundaries
        if ((it->x >= 0) && (it->x < mapWidth) && (it->y >= 0) && it->y < mapHeight)
        {
            // Checking existance in path
            if (!it->containedIn(path))
            {
                // Checking cell type
                Cell::CellType type = (*matrix)[it->x][it->y]->getType();
                if (type != Cell::CellType::Empty && type != Cell::CellType::Wall)
                {
                    goodPathUnits.push_back(*it);
                }
            }
        }
    }

    return goodPathUnits;
}

std::vector<PathUnit> Path::getShortestPath(std::vector<PathUnit> path, int destinationDepth)
{
    // TO DO
    std::vector<PathUnit> p;
    return p;
}