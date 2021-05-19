#ifndef CPU_H
#define CPU_H

#include "vars.h"
#include "player.h"
#include "gameships.h"
#include <QRandomGenerator>


class CPU : public Player
{
public:
    CPU();
    virtual ~CPU();
    TARGET_POINT Turn(int, int, MYPOINT* OPGrid[WID][LEN]);
    TARGET_POINT CPU_Turn(MYPOINT* OPGrid[WID][LEN]);
    bool setUpCPUShips();

    bool isDeciding;
    CPU_POINT* CPUGrid[WID][LEN];
    int* hits;
    int* direction;
    TARGET_POINT* target;
    TARGET_POINT* lasttarget;
    //CPU-specific displayships
};

//CPU_Turn functions
    void findTarget(CPU_POINT* CPUGrid[WID][LEN], TARGET_POINT* target);
        bool allPointsAroundAreMisses(CPU_POINT* CPUGrid[WID][LEN], TARGET_POINT* target);
        int howmanyMSPoints(CPU_POINT* CPUGrid[WID][LEN]);
        int randomnum(int bound);
        void findMSPoint(CPU_POINT* CPUGrid[WID][LEN], TARGET_POINT* target, int mspoints);
        void findRandomPoint(CPU_POINT* CPUGrid[WID][LEN], TARGET_POINT* target);
        int howmanyUnknownPoints(CPU_POINT* CPUGrid[WID][LEN]);
    void CPUFire(CPU_POINT* CPUGrid[WID][LEN], MYPOINT* OPGrid[WID][LEN], int* hits, TARGET_POINT* target, TARGET_POINT* lasttarget, int* direction);
        void setDirection(TARGET_POINT* target, TARGET_POINT* lasttarget, int* direction);
        bool shipIsSunk(MYPOINT* OPGrid[WID][LEN], TARGET_POINT* target);
        void revealShipToCPUGrid(CPU_POINT* CPUGrid[WID][LEN], MYPOINT* OPGrid[WID][LEN], TARGET_POINT* target);
    void resetMSPoints(CPU_POINT* CPUGrid[WID][LEN]);
    void findUnidentifiedShips(CPU_POINT* CPUGrid[WID][LEN], int* hits, TARGET_POINT *lasttarget);
        void whatShouldHitsBe(CPU_POINT* CPUGrid[WID][LEN], int* hits);
            int foundHitsAroundPoint(CPU_POINT* CPUGrid[WID][LEN], int x, int y, int r);
    void suspectPoints(CPU_POINT* CPUGrid[WID][LEN], TARGET_POINT* target);
    void cutOffMSPoints(CPU_POINT* CPUGrid[WID][LEN], TARGET_POINT* target, int* direction);
    void suspectPoint(CPU_POINT* CPUGrid[WID][LEN], TARGET_POINT* target, int* direction);
    void changePointsAround(CPU_POINT* CPUGrid[WID][LEN], int x, int y, int pointiscurrent, int pointbecomes);

#endif // CPU_H
