#ifndef PROTOCOLEVENT_H
#define PROTOCOLEVENT_H

#include <QTextStream>

enum class ProtocolEvent {
    GameMoved,
    GameEnded,
    PlayerMoved
};

QTextStream &operator<< (QTextStream& stream, ProtocolEvent event);
QTextStream &operator>> (QTextStream& stream, ProtocolEvent &event);

#endif // PROTOCOLEVENT_H
