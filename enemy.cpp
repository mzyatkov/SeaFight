#include "enemy.h"

Enemy::Enemy()
{

}
Enemy::~Enemy(){}
TARGET_POINT Enemy::Turn(int, int, MYPOINT *OPGrid[WID][LEN]) {
    return Enemy_Turn(OPGrid);
}
TARGET_POINT Enemy::Enemy_Turn(MYPOINT *OPGrid[WID][LEN]) {
    TARGET_POINT ret{};
    return ret;
}

