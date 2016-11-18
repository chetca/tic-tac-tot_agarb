#include "game.h"
#include "gameview.h"
#include "gameviewplayer.h"
#include "remoteplayer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game game;

    GameViewPlayer crossPlayer(Mark::Cross);
    RemotePlayer noughtPlayer(Mark::Nought);

    GameView view;
    view.setGame(&game);
    view.setCrossPlayer(&crossPlayer);
    view.setNoughtPlayer(&noughtPlayer);

    view.show();

    return a.exec();
}
