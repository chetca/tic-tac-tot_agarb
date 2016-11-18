#include "gameview.h"

#include "gameviewplayer.h"
#include "gamefield.h"

#include <QDebug>

GameView::GameView(QWidget *parent) : QWidget(parent)
{
    m_layout = new QGridLayout(this);

    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            auto button = new GameViewButton;
            button->setCoords(i,j);
            connect(button, SIGNAL(clicked(Coords)),
                    this, SLOT (onButtonClicked(const Coords&)));
            m_layout->addWidget(button, i, j);
        }
    }
}

AbstractGame *GameView::game() const
{
    return m_game;
}

void GameView::setGame(AbstractGame *game)
{
//    resetGame();

    if (!game)
        return;

    m_game = game;

    applyGameField();
    connect(m_game, SIGNAL(moved(Coords,Mark)),
            this, SLOT(applyGameField()));
}

void GameView::onButtonClicked(const Coords &coords)
{
    if (!m_game)
        return;

    Mark mark = m_game->currentMark();

    AbstractPlayer *abstractPlayer = markPlayer(mark);
    GameViewPlayer *player = qobject_cast<GameViewPlayer*> (abstractPlayer);
    if (!player)
        return;

    qDebug() << coords.i << coords.j;

    player->move(coords);
}

void GameView::applyGameField()
{
    qDebug() << m_game;

    if (!m_game)
        return;

    GameField field = m_game->field();
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            GameViewButton *btn = button(i,j);
            qDebug() << btn;
            if (!btn)
                continue;
            Mark mark = field.mark(i,j);
            qDebug() << int(mark);
            btn->setMark(mark);
        }
    }
}

void GameView::setupPlayer(AbstractPlayer *&player, AbstractPlayer *newPlayer)
{
    player = newPlayer;

    if (player && m_game)
        player->setGame(m_game);
}

AbstractPlayer *GameView::markPlayer(Mark mark) const
{
    switch (mark) {
    case Mark::Cross: return m_crossPlayer;
    case Mark::Nought: return m_noughtPlayer;
    }

    return 0;
}

GameViewButton *GameView::button(int i, int j)
{
    QLayoutItem *item = m_layout->itemAtPosition(i, j);

    return qobject_cast<GameViewButton*>(item->widget());
}

AbstractPlayer *GameView::crossPlayer() const
{
    return m_crossPlayer;
}

void GameView::setCrossPlayer(AbstractPlayer *crossPlayer)
{
    setupPlayer(m_crossPlayer, crossPlayer);
}

AbstractPlayer *GameView::noughtPlayer() const
{
    return m_noughtPlayer;
}

void GameView::setNoughtPlayer(AbstractPlayer *noughtPlayer)
{
    setupPlayer(m_noughtPlayer, noughtPlayer);
}
