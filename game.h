#ifndef GAME_H
#define GAME_H

#include "abstractgame.h"

class Game : public AbstractGame
{
    Q_OBJECT
public:
    using AbstractGame::AbstractGame;

    virtual GameField field() const;

    virtual Mark currentMark() const;
    virtual Mark winnerMark() const;
    virtual bool isEnded() const;

    virtual bool move(const Coords &coords, Mark mark);

private:
    bool isMovementPossible(const Coords &coords, Mark mark) const;
    void moveImpl(const Coords &coords, Mark mark);
    void processMovement(const Coords &coords, Mark mark);

    Mark nextMark(Mark mark) const;

    bool isAllFilled() const;
    bool isWinnerState(const Coords &coords) const;
    bool isWinnerDirection(const Coords &coords, const Coords &dir) const;
    int lengthInDirection(Coords coords, const Coords &dir) const;

    GameField m_field;
    Mark m_currentMark = Mark::Cross;
    Mark m_winnerMark = Mark::None;
    bool m_isEnded = false;

    static Coords m_directions[4];
};

#endif // GAME_H
