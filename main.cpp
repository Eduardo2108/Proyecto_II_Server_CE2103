#include "src/BPGame/BPManager.h"
#include "src/util/Json.h"

int main() {
    auto *settings = new GameSettings();
    settings->setPlayer1Name("Edu")->setPlayer2Name("Jose")->setObstacles(19)->setMaxGoals(3);
    auto *bp = new BPManager(settings);
    auto *shoot = new Shoot();
    shoot->setStrength(10);
    shoot->setDirX(1);
    shoot->setDirY(0);

    auto *r = new Response();

    Route *route = bp->shoot(shoot);
    r->setMessage(Json::convertRoute(route));
    r->setLog("Log of server");
    r->setStatusCode(20);
    cout << Json::convertResponse(r);
    return 0;
}
