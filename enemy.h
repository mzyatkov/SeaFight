#ifndef ENEMY_H
#define ENEMY_H

#include "vars.h"
#include "cpu.h"
#include "gameships.h"

class Enemy : public CPU
{
public:
    Enemy();
    virtual ~Enemy();
    TARGET_POINT Turn(int, int, MYPOINT* OPGrid[WID][LEN]);
    TARGET_POINT CPU_Turn(MYPOINT* OPGrid[WID][LEN]);



};

#endif // ENEMY_H
