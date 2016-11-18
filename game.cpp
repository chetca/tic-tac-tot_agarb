#include "game.h"

#include <QDebug>

Coords Game::m_directions[4] = {
    Coords(1,0),
    Coords(1,1),
    Coords(0,1),
    Coords(-1,1)
};

GameField Game::field() const
{
    return m_field;
}

Mark Game::currentMark() const
{
    return m_currentMark;
}

Mark Game::winnerMark() const
{
    return m_winnerMark;
}

bool Game::isEnded() const
{
    return m_isEnded;
}

bool Game::move(const Coords &coords, Mark mark)
{
    qDebug() << coords.i << coords.j << int(mark);

    if (!isMovementPossible(coords, mark))
        return false;

    qDebug() << coords.i << coords.j << int(mark);

    moveImpl(coords, mark);

    processMovement(coords, mark);

    return true;
}

bool Game::isMovementPossible(const Coords &coords, Mark mark) const
{
    return !m_isEnded
            && m_field.mark(coords) == Mark::None
            && m_currentMark == mark;
}

void Game::moveImpl(const Coords &coords, Mark mark)
{
    m_field.setMark(coords, mark);

    m_currentMark = nextMark(m_currentMark);

    qDebug() << coords.i << coords.j << int(mark);

    emit moved(coords, mark);
}

void Game::processMovement(const Coords &coords, Mark mark)
{
    if (isWinnerState(coords)) {
        m_isEnded = true;
        m_winnerMark = mark;

        emit ended(mark);
    }
    else if (isAllFilled()) {
        m_isEnded = true;
        m_winnerMark = Mark::None;

        emit ended(Mark::None);
    }
}

Mark Game::nextMark(Mark mark) const
{
    switch (mark) {
    case Mark::Cross: return Mark::Nought;
    case Mark::Nought: return Mark::Cross;
    }

    return Mark::None;
}

bool Game::isAllFilled() const
{
    for (int i=0; i<3; ++i)
        for (int j=0; j<3; ++j)
            if(m_field.mark(i,j) == Mark::None)
                return false;

    return true;
}

bool Game::isWinnerState(const Coords &coords) const
{
    for (const Coords &direction: m_directions)
        if (isWinnerDirection(coords, direction))
            return true;

    return false;
}

bool Game::isWinnerDirection(const Coords &coords, const Coords &dir) const
{
    int len1 = lengthInDirection(coords, dir);
    int len2 = lengthInDirection(coords, -dir);

    return len1+len2-1 == 3;
}

int Game::lengthInDirection(Coords coords, const Coords &dir) const
{
    Mark mark = m_field.mark(coords);

    int len = 1;
    for(;;) {
        coords += dir;
        if (!coords.isValid() || m_field.mark(coords) != mark)
            break;
        ++len;
    }

    return len;
}
