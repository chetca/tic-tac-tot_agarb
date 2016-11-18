#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "mark.h"
#include "coords.h"

#include <array>

class GameField
{
public:
    GameField();

    Mark mark(const Coords &coords) const;
    Mark mark(int i, int j) const;
    void setMark(const Coords &coords, Mark mark);

private:
    std::array<std::array<Mark, 3>, 3> m_data;
};

#endif // GAMEFIELD_H
