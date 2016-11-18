#include "gameviewplayer.h"

#include <QDebug>

bool GameViewPlayer::move(const Coords &coords)
{
    AbstractGame *game = AbstractPlayer::game();
    if (!game)
        return false;

    qDebug() << coords.i << coords.j;

    return game->move(coords, mark());
}
