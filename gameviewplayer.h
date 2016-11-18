#ifndef GAMEVIEWPLAYER_H
#define GAMEVIEWPLAYER_H

#include "abstractplayer.h"

class GameViewPlayer : public AbstractPlayer
{
    Q_OBJECT
public:
    using AbstractPlayer::AbstractPlayer;

    bool move(const Coords &coords);
};

#endif // GAMEVIEWPLAYER_H
