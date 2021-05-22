#include "enemy.h"

Enemy::Enemy()
{
    isEnemy = true;
    isDeciding = false;
    for(int w = 0; w < WID; ++w)
    {
        for(int l = 0; l < LEN; ++l)
        {
            CPUGrid[w][l] = new cpupoint;
            CPUGrid[w][l]->pointis = unknown;
            CPUGrid[w][l]->shipis = 0;
        }
    }
    direction = new int;
    *direction = NoD;
    target = new TARGET_POINT;
    lasttarget = new TARGET_POINT;
}
Enemy::~Enemy()
{
    qDebug()<<"delete enemy";
}
TARGET_POINT Enemy::Turn(int, int, MYPOINT *OPGrid[WID][LEN])
{
    return CPU_Turn(OPGrid);
}
TARGET_POINT Enemy::CPU_Turn(MYPOINT *OPGrid[WID][LEN])
{
    qDebug()<<"i,m enemy";
    target->x = 1;
    target->y = 1;
    qDebug()<<"received enemy point";
    OPGrid[target->x][target->y]->hit = true;
    if(OPGrid[target->x][target->y]->shipis > 0)
    {
        CPUGrid[target->x][target->y]->pointis = hit;
        if(shipIsSunk(OPGrid, target))
            revealShipToCPUGrid(CPUGrid, OPGrid, target);
    }
    else
        CPUGrid[target->x][target->y]->pointis = miss;
    target->cpupnt = *CPUGrid[target->x][target->y];
    return *target;
}

