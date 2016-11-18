#include "gameviewbutton.h"

#include <QDebug>

GameViewButton::GameViewButton(QWidget *parent) : QPushButton(parent)
{
    connect(this, SIGNAL(clicked(bool)),
            this, SLOT(onClicked()));
}

Mark GameViewButton::mark() const
{
    return m_mark;
}

void GameViewButton::setMark(const Mark &mark)
{
    m_mark = mark;

    QString text = markText(mark);

    qDebug() << text;

    setText(text);
}

QString GameViewButton::markText(Mark mark)
{
    switch (mark) {
    case Mark::Cross: return "X";
    case Mark::Nought: return "O";
    }

    return QString();
}

Coords GameViewButton::coords() const
{
    return m_coords;
}

void GameViewButton::setCoords(int i, int j)
{
    m_coords.i = i;
    m_coords.j = j;
}

void GameViewButton::onClicked()
{
    emit clicked(coords());
}
