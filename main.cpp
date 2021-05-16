#include <iostream>
#include "src/BPGame/Pathfinding/Pathfinding.h"
#include "src/BPGame/Components/Field.h"

int main() {
    auto *f = new Field(9, 18);
    f->generateField();
    Matrix *m = f->getMatrix();
    m->get(5, 2)->setHasBall(true);
    m->show();
    cout << endl << "----------" << endl;

    auto *shoot = new Shoot();shoot->setStrength(50);
    shoot->setDirX(1);
    shoot->setDirY(0);
    shoot->setStrength(50);
    Ball *ball = new Ball();
    Route *r = Pathfinding::calculateShoot(shoot, m, ball);
    ball->show();
    r->show();
    m->show();

    return 0;
}
