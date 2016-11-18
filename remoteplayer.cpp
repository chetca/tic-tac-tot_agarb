#include "remoteplayer.h"

#include "protocolevent.h"

#include <QTextStream>

RemotePlayer::RemotePlayer(Mark mark, QObject *parent) :
    AbstractPlayer(mark, parent)
{
    m_server.listen(QHostAddress::Any, 13666);

    connect(&m_server, SIGNAL(newConnection()),
            this, SLOT(onNewConection()));
}

void RemotePlayer::setGame(AbstractGame *game)
{
    AbstractPlayer::setGame(game);

    if (!game)
        return;

    connect(game, SIGNAL(moved(Coords,Mark)),
            this, SLOT(sendMoved(Coords,Mark)));

    connect(game, SIGNAL(ended(Mark)),
            this, SLOT(sendEnded(Mark)));
}

void RemotePlayer::onNewConection()
{
    m_socket = m_server.nextPendingConnection();

    connect(m_socket, SIGNAL(readyRead()),
            this, SLOT(onReadyRead()));
}

void RemotePlayer::onReadyRead()
{
    QTextStream socketStream(m_socket);

    ProtocolEvent event;
    socketStream >> event;

    if (event == ProtocolEvent::PlayerMoved) {
        Coords coords;
        Mark mark;

        socketStream >> coords >> mark;
        AbstractGame *gm = game();
        if (!gm)
            return;

        gm->move(coords, mark);
    }
}

void RemotePlayer::sendMoved(const Coords &coords, Mark mark)
{
    if (!m_socket)
        return;

    QTextStream socketStream(m_socket);

    socketStream << ProtocolEvent::GameMoved << " "
                 << coords << " "
                 << mark << "\n";
}

void RemotePlayer::sendEnded(Mark mark)
{
    if (!m_socket)
        return;

    QTextStream socketStream(m_socket);

    socketStream << ProtocolEvent::GameEnded << " "
                 << mark << "\n";
}

