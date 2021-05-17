#include "src/BPGame/BPManager.h"
#include "src/util/Json.h"

int main() {
    GameSettings *settings = new GameSettings();
    settings->setPlayer1Name("Edu")->setPlayer2Name("Jose")->setObstacles(19)->setMaxGoals(3);
    BPManager *bp = new BPManager(settings);
    auto *shoot = new Shoot();
    shoot->setStrength(50);
    shoot->setDirX(1);
    shoot->setDirY(0);


    Route *route = bp->shoot(shoot);
    cout << Json::convertRoute(route);
    return 0;
}
