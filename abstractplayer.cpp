#include "abstractplayer.h"

AbstractPlayer::AbstractPlayer(Mark mark, QObject *parent) :
    QObject(parent),
    m_mark(mark)
{
}

AbstractGame *AbstractPlayer::game() const
{
    return m_game;
}

void AbstractPlayer::setGame(AbstractGame *game)
{
    m_game = game;
}

Mark AbstractPlayer::mark() const
{
    return m_mark;
}
