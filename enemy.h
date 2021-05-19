#ifndef ENEMY_H
#define ENEMY_H

#include "vars.h"
#include "player.h"
#include "gameships.h"

class Enemy : public Player
{
public:
    Enemy();
    virtual ~Enemy();
    TARGET_POINT Turn(int, int, MYPOINT* OPGrid[WID][LEN]);
    TARGET_POINT Enemy_Turn(MYPOINT* OPGrid[WID][LEN]);



};

#endif // ENEMY_H
