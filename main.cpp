#include <iostream>
#include "src/BPGame/Pathfinding/Route.h"
#include "src/BPGame/Pathfinding/Pathfinding.h"

int main() {
    Shoot *shoot = new Shoot();
    shoot->setDirX(1);
    shoot->setDirY(1);
    shoot->setStrength(10);
    Ball *ball = new Ball();

    Matrix *m = new Matrix(10,10);
    m->show();
    Box *b = m->get(1,10);

    //ball->show();
    //Pathfinding::calculateShoot(shoot, nullptr, ball);
    //ball->show();

    return 0;
}
