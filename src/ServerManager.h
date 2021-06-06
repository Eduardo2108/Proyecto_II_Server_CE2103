//
// Created by eduardozumbadog on 5/19/21.
//

#ifndef PROYECTO_II_SERVER_CE2103_SERVERMANAGER_H
#define PROYECTO_II_SERVER_CE2103_SERVERMANAGER_H

#include "BPGame/BPManager.h"
#include "util/Json.h"
#include "BPGame/Pathfinding/Route.h"
#include "BPGame/Pathfinding/A_Star.h"

class ServerManager {
private:


public:

    static string processRequest(const string json_request) {

        auto *settings = new GameSettings();
        settings->setPlayer1Name("Edu")->setPlayer2Name("Jose")->setObstacles(19)->setMaxGoals(3);

        BPManager::getInstance(settings);

        auto *msg = new Message();
        msg->Deserialize(json_request);
        string result;

        if (msg->getRequest() == "shot") {
            auto *shoot = new Shoot();
            if (shoot->Deserialize(msg->getBody())) {
                Route *route = BPManager::getInstance(settings)->shoot(shoot);
                string str = Json::convertRoute(route);

                auto *r = new Response();
                r->setMessage(str);
                r->setLog("ShotLOG");
                r->setStatusCode(200);
                result = Json::convertResponse(r);
            }
        } else if (msg->getRequest() == "obstacles") {
            int obstacles = stoi(msg->getBody());
            Route *route = BPManager::getInstance()->getField()->generateObstacles(obstacles);
            string str = Json::convertRoute(route);
            auto *r = new Response();
            r->setMessage(str);
            r->setLog("ObsLog");
            r->setStatusCode(200);
            result = Json::convertResponse(r);
        } else if (msg->getRequest() == "star") {
            auto *path = new Path();
            if (path->Deserialize(msg->getBody())) {

                auto *star = new A_Star();
                Route *route = star->aStar(path);
                route->show();
                string str = Json::convertRoute(route);
                auto *r = new Response();

                r->setMessage(str);
                r->setLog("PathLog");
                r->setStatusCode(200);

                result = Json::convertResponse(r);
            }
            cerr << result << endl;
            return result;
        } else if (msg->getRequest() == "ai_shot") {
            auto *path = new Path();
            if (path->Deserialize(msg->getBody())) {

                auto *star = new A_Star();
                Shoot *shot = star->calculateShotAI(path);

                string str = Json::convertShot(shot);
                auto *r = new Response();

                r->setMessage(str);
                r->setLog("Calculated shot for AI");
                r->setStatusCode(200);

                result = Json::convertResponse(r);
            }
        }
        cerr << result << endl;
        return result;
    }
};

#endif //PROYECTO_II_SERVER_CE2103_SERVERMANAGER_H
