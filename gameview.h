#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "gameviewbutton.h"
#include "abstractgame.h"
#include "abstractplayer.h"

#include <QWidget>
#include <QGridLayout>

class GameView : public QWidget
{
    Q_OBJECT
public:
    explicit GameView(QWidget *parent = 0);

    AbstractGame *game() const;
    void setGame(AbstractGame *game);

    AbstractPlayer *noughtPlayer() const;
    void setNoughtPlayer(AbstractPlayer *noughtPlayer);

    AbstractPlayer *crossPlayer() const;
    void setCrossPlayer(AbstractPlayer *crossPlayer);

private slots:
    void onButtonClicked(const Coords & coords);
    void applyGameField();

private:
    void setupPlayer(AbstractPlayer *&player, AbstractPlayer *newPlayer);
    AbstractPlayer *markPlayer(Mark mark) const;

    GameViewButton *button(int i, int j);

    QGridLayout *m_layout = 0;

    AbstractGame *m_game = 0;

    AbstractPlayer *m_noughtPlayer = 0;
    AbstractPlayer *m_crossPlayer = 0;
};

#endif // GAMEVIEW_H
