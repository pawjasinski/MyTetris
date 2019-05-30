#ifndef BLOCK_H
#define BLOCK_H
#include <array>

enum class blockShape { NoShape, IShape, TShape, OShape, LShape, JShape, SShape, ZShape };

class Block
{
private:
    blockShape tetrixShape;
    std::array<std::array<int,2>,4> coord;

    void setX(unsigned int ind, int x) { coord[ind][0] = x; }
    void setY(unsigned int ind, int y) { coord[ind][1] = y; }

public:
    Block(): tetrixShape(blockShape::NoShape) {}

    blockShape getShape() const {return tetrixShape;}
    void setShape(blockShape shape);
    void setRandomShape();

    int getX(unsigned int ind) const {return coord[ind][0];}
    int getY(unsigned int ind) const {return coord[ind][0];}
    int minX() const;
    int minY() const;
    int maxX() const;
    int maxY() const;

    void rotateLeft();
    void rotateRight();

};
#endif // BLOCK_H
