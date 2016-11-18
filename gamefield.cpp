#include "gamefield.h"

GameField::GameField()
{
    for(int i=0; i<3; ++i)
        for(int j=0; j<3; ++j)
            m_data[i][j] = Mark::None;
}

Mark GameField::mark(const Coords &coords) const
{
    return mark(coords.i, coords.j);
}

Mark GameField::mark(int i, int j) const
{
    return m_data[i][j];
}

void GameField::setMark(const Coords &coords, Mark mark)
{
    m_data[coords.i][coords.j] = mark;
}
