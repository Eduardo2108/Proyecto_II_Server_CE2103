#include <iostream>
#include "src/BPGame/Pathfinding/Route.h"
#include "src/BPGame/Pathfinding/Pathfinding.h"
#include "src/BPGame/Components/Field.h"

int main() {
    Field *f = new Field(9, 18);
    f->generateField();
    Matrix *m = f->getMatrix();
    m->get(2, 2)->setHasBall(true);
    m->show();

    cout << endl << "----------" << endl;
    Shoot *shoot = new Shoot();
    shoot->setDirX(1);
    shoot->setDirY(0);
    shoot->setStrength(10);
    Ball *ball = new Ball();
    Pathfinding::calculateShoot(shoot, m, ball);
    m->show();

    return 0;
}
