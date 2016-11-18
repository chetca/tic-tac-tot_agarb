#ifndef ABSTRACTPLAYER_H
#define ABSTRACTPLAYER_H

#include "mark.h"
#include "abstractgame.h"

#include <QObject>

class AbstractPlayer : public QObject
{
    Q_OBJECT
public:
    explicit AbstractPlayer(Mark mark, QObject *parent = 0);

    AbstractGame *game() const;
    virtual void setGame(AbstractGame *game);

    Mark mark() const;

private:
    AbstractGame *m_game = 0;
    Mark m_mark = Mark::None;
};

#endif // ABSTRACTPLAYER_H
