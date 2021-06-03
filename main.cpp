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
    BPManager::getInstance()->getField()->generateObstacles(5);
    BPManager::getInstance()->getField()->show();


    auto *path = new Path();
    path->setStartX(8);
    path->setStartY(9);

    path->setEndX(5);
    path->setEndY(18);


    auto *msg = new Message();
    string path_str = Json::convertPath(path);
    msg->setBody(path_str);
    msg->setRequest("ai_shot");


    string str = ServerManager::processRequest(Json::convertMessage(msg));

    cout << str;

    Response * r = new Response();
    r->Deserialize(str);

    auto *pathfindingResultado = new Route();
    pathfindingResultado->Deserialize(r->getMessage());*/
    Server::GetInstance()->InitServer();
    //A_Star *star = new A_Star();
    return 0;
};
