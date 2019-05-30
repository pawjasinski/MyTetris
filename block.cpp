#include <QtCore>
#include <stdlib.h>
#include "block.h"
using std::array;

void Block::setShape(blockShape shape)
{
    static const int tableOfShapes[8][4][2] =
    {
        { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } },
        { { 0, -1 },  { 0, 0 },   { -1, 0 },  { -1, 1 } },
        { { 0, -1 },  { 0, 0 },   { 1, 0 },   { 1, 1 } },
        { { 0, -1 },  { 0, 0 },   { 0, 1 },   { 0, 2 } },
        { { -1, 0 },  { 0, 0 },   { 1, 0 },   { 0, 1 } },
        { { 0, 0 },   { 1, 0 },   { 0, 1 },   { 1, 1 } },
        { { -1, -1 }, { 0, -1 },  { 0, 0 },   { 0, 1 } },
        { { 1, -1 },  { 0, -1 },  { 0, 0 },   { 0, 1 } }
    };
    /* // it doesn't work, but i have no idea why
    static const array< array< array< int, 2>, 4>, 8> tableOfShapes =
    {
        { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } },
        { { 0, -1 },  { 0, 0 },   { -1, 0 },  { -1, 1 } },
        { { 0, -1 },  { 0, 0 },   { 1, 0 },   { 1, 1 } },
        { { 0, -1 },  { 0, 0 },   { 0, 1 },   { 0, 2 } },
        { { -1, 0 },  { 0, 0 },   { 1, 0 },   { 0, 1 } },
        { { 0, 0 },   { 1, 0 },   { 0, 1 },   { 1, 1 } },
        { { -1, -1 }, { 0, -1 },  { 0, 0 },   { 0, 1 } },
        { { 1, -1 },  { 0, -1 },  { 0, 0 },   { 0, 1 } }
    };
    */
    for (unsigned int i = 0; i < 4; ++i)
    {
        for (unsigned int j = 0; j < 2; ++j)
        {
            coord[i][j] = tableOfShapes[static_cast<int>(shape)][i][j];
        }
    }
    tetrixShape = shape;
}

void Block::setRandomShape()
{
    tetrixShape = static_cast<blockShape>(QRandomGenerator::global()->bounded(1,8));
}

int Block::minX() const
{
    int min = coord[0][0];
    for (unsigned int i = 0; i < 4; ++i)
    {
        min = std::min(min, coord[i][0]);
    }
    return min;
}

int Block::minY() const
{
    int min = coord[0][0];
    for (unsigned int i = 0; i < 4; ++i)
    {
        min = std::min(min, coord[i][1]);
    }
    return min;
}

int Block::maxX() const
{
    int max = coord[0][0];
    for (unsigned int i = 0; i < 4; ++i)
    {
        max = std::maxn(max, coord[i][0]);
    }
    return max;
}

int Block::maxY() const
{
    int max = coord[0][0];
    for (unsigned int i = 0; i < 4; ++i)
    {
        max = std::max(max, coord[i][1]);
    }
    return max;
}

void Block::rotateLeft()
{
    if (tetrixShape == blockShape::OShape) return;
    for (unsigned int i; i < 4; ++i)
    {
        setX( i,  getY(i) );
        setY( i, -getX(i) );
    }
}

void Block::rotateRight()
{
    if (tetrixShape == blockShape::OShape) return;
    for (unsigned int i; i < 4; ++i)
    {
        setX( i, -getY(i) );
        setY( i,  getX(i) );
    }
}
