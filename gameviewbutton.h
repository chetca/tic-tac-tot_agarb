#ifndef GAMEVIEWBUTTON_H
#define GAMEVIEWBUTTON_H

#include "mark.h"
#include "coords.h"

#include <QPushButton>

class GameViewButton : public QPushButton
{
    Q_OBJECT
public:
    explicit GameViewButton(QWidget *parent = 0);

    Mark mark() const;
    void setMark(const Mark &mark);

    Coords coords() const;
    void setCoords(int i, int j);

signals:
    void clicked(const Coords &coords);

private slots:
    void onClicked();

private:
    static QString markText(Mark mark);

    Coords m_coords;
    Mark m_mark;
};

#endif // GAMEVIEWBUTTON_H
