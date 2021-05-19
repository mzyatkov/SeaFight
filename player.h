#ifndef PLAYER_H
#define PLAYER_H
#include "vars.h"
#include "gameships.h"


class Player
{
public:
    Player();
    virtual ~Player();
    bool placeShip(int thisship, int x, int y);
    void removeShip(int thisship);
    TARGET_POINT fireAtPoint(MYPOINT* OPGrid[WID][LEN], gameships* OPShips[4]);

    virtual TARGET_POINT Turn(int, int, MYPOINT*[WID][LEN]){TARGET_POINT ret;return ret;}

    bool isCPU;
    bool isEnemy;
    MYPOINT* PlayerGrid[WID][LEN];
    gameships* PlayerShips[4];
    TARGET_POINT targetedPoint;
};

#endif // PLAYER_H
