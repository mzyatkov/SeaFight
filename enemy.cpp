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
    hits = new int;
    *hits = 0;
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
    static TARGET_POINT* lasttarget = 0;
    if(lasttarget == 0)
    {
        lasttarget = new TARGET_POINT;
    }
    if(target->cpupnt.pointis == hit)
    {
        lasttarget->cpupnt = target->cpupnt;
        lasttarget->x = target->x;
        lasttarget->y = target->y;
    }

    findTarget(CPUGrid, target);

    CPUFire(CPUGrid, OPGrid, hits, target, lasttarget, direction);

    if(target->cpupnt.shipis != 0)
    {
            *hits = 0;
            resetMSPoints(CPUGrid);
            findUnidentifiedShips(CPUGrid, hits, lasttarget);

            return *target;
    }
    else if(target->cpupnt.pointis == hit)
    {

        switch(*hits)
        {
        case 1:
            suspectPoints(CPUGrid, target);

            break;
        case 2:
            cutOffMSPoints(CPUGrid, target, direction);
            suspectPoint(CPUGrid, target, direction);

            break;
        default:
            suspectPoint(CPUGrid, target, direction);

            break;
        }
    }

    if(howmanyMSPoints(CPUGrid) == 0)
    {
        *hits = 0;
        findUnidentifiedShips(CPUGrid, hits, lasttarget);

    }

    return *target;
}

