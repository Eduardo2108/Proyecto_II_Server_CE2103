#include "src/BPGame/BPManager.h"

int main() {
    GameSettings *settings = new GameSettings();
    settings->setPlayer1Name("Edu")->setPlayer2Name("Jose")->setObstacles(19)->setMaxGoals(3);
    BPManager *bp = new BPManager(settings);
    auto *shoot = new Shoot();
    shoot->setStrength(3);
    shoot->setDirX(1);
    shoot->setDirY(0);
    bp->shoot(shoot)->show();
    return 0;
}
