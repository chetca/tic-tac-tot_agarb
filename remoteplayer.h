#ifndef REMOTEPLAYER_H
#define REMOTEPLAYER_H

#include "abstractplayer.h"

#include <QTcpServer>
#include <QTcpSocket>

class RemotePlayer : public AbstractPlayer
{
    Q_OBJECT
public:
    explicit RemotePlayer(Mark mark, QObject *parent = 0);

    virtual void setGame(AbstractGame *game);

private slots:
    void onNewConection();
    void onReadyRead();

    void sendMoved(const Coords &coords, Mark mark);
    void sendEnded(Mark mark);

private:
    QTcpServer m_server;

    QTcpSocket *m_socket = 0;
};

#endif // REMOTEPLAYER_H
