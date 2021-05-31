#include <climits>
#include "src/BPGame/BPManager.h"
#include "src/util/Json.h"
#include "src/ServerManager.h"
#include "src/Socket/Server.h"
#include "src/BPGame/Pathfinding/A_Star.h"

int main() {
    /*
    auto *settings = new GameSettings();
    settings->setPlayer1Name("Edu")->setPlayer2Name("Jose")->setObstacles(19)->setMaxGoals(3);
    BPManager::getInstance(settings);

    auto *msg = new Message();
    msg->setBody(to_string(3));
    msg->setRequest("obstacles");

    cout << Json::convertMessage(msg) << endl;

    string str = ServerManager::processRequest(Json::convertMessage(msg));

    cout << str;
    */
    // Server::GetInstance()->InitServer();
    A_Star *star = new A_Star();
    return 0;
}
