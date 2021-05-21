#include "src/BPGame/BPManager.h"
#include "src/util/Json.h"
#include "src/ServerManager.h"
#include "src/Socket/Server.h"

int main() {
/*    auto *settings = new GameSettings();
    settings->setPlayer1Name("Edu")->setPlayer2Name("Jose")->setObstacles(19)->setMaxGoals(3);
    BPManager::getInstance(settings);


    auto *shoot = new Shoot();
    shoot->setStrength(10);
    shoot->setDirX(1);
    shoot->setDirY(0);


    auto *msg = new Message();
    msg->setBody(Json::convertShot(shoot));
    msg->setRequest("shot");
    string str = ServerManager::processRequest(Json::convertMessage(msg));

    cout << str;*/
    Server::GetInstance()->InitServer();
    return 0;
}
