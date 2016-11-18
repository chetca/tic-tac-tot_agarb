#ifndef ABSTRACTGAME_H
#define ABSTRACTGAME_H

#include "mark.h"
#include "coords.h"
#include "gamefield.h"

#include <QObject>

class AbstractGame : public QObject
{
    Q_OBJECT
public:
    explicit AbstractGame(QObject *parent = 0);

    virtual GameField field() const = 0;

    virtual Mark currentMark() const = 0;
    virtual Mark winnerMark() const = 0;
    virtual bool isEnded() const = 0;

    virtual bool move(const Coords &coords, Mark mark) = 0;

signals:
    void moved(const Coords &coords, Mark mark);
    void ended(Mark mark);
};

#endif // ABSTRACTGAME_H
