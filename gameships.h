#ifndef GAMESHIPS_H
#define GAMESHIPS_H

#include <QMainWindow>
#include <vector>
#include "vars.h"


bool shipsAreInLine(MYPOINT* theGrid[WID][LEN], QPoint beginSquare, int size, bool toRight);



class gameships
{
public:
    gameships(int sn);
    ~gameships();
    void setDirection(int direct);
    bool placeThisShip(MYPOINT* theGrid[WID][LEN], QPoint noseSquare);
    void removeThisShip(MYPOINT* theGrid[WID][LEN]);
    bool getHitAt(int x,int y);
    int pointTouched(int x, int y);

    bool placed;
    int direction;
    int shipnum;
    int size;
    QVector<QPoint> points;
    QVector<bool> hitpoints;
};

#endif // GAMESHIPS_H
