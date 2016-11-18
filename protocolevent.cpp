#include "protocolevent.h"

#include <QPair>
#include <QString>
#include <QVector>
#include <QHash>

typedef QPair<ProtocolEvent, QString> EventStringPair;
typedef QVector<EventStringPair> EventStringVector;
typedef QHash<ProtocolEvent, QString> EventStringHash;
typedef QHash<QString, ProtocolEvent> StringEventHash;

uint qHash(ProtocolEvent event)
{
    return uint(event);
}

EventStringVector eventStringVector {{
        {ProtocolEvent::GameMoved, "gm"},
        {ProtocolEvent::GameEnded, "ge"},
        {ProtocolEvent::PlayerMoved, "pm"}
                                     }};

EventStringHash createEventStringHash()
{
    EventStringHash hash;

    for(auto p: eventStringVector)
        hash[p.first] = p.second;

    return hash;
}

StringEventHash createStringEventHash()
{
    StringEventHash hash;

    for(auto p: eventStringVector)
        hash[p.second] = p.first;

    return hash;
}

QTextStream &operator<<(QTextStream &stream, ProtocolEvent event)
{
    static auto hash = createEventStringHash();

    return stream << hash[event];
}

QTextStream &operator>>(QTextStream &stream, ProtocolEvent &event)
{
    static auto hash = createStringEventHash();

    QString tmp;
    stream >> tmp;
    event = hash[tmp];

    return stream;
}
