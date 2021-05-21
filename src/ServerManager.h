//
// Created by eduardozumbadog on 5/19/21.
//

#ifndef PROYECTO_II_SERVER_CE2103_SERVERMANAGER_H
#define PROYECTO_II_SERVER_CE2103_SERVERMANAGER_H

#include "BPGame/BPManager.h"
#include "util/Json.h"

class ServerManager {

public:
    static string processRequest(const string &json_request) {
        auto *msg = new Message();
        msg->Deserialize(json_request);
        string result;

        if (msg->getRequest() == "shot") {
            auto *shoot = new Shoot();
            if (shoot->Deserialize(msg->getBody())) {
                Route *route = BPManager::getInstance()->shoot(shoot);
                string str = Json::convertRoute(route);

                auto *r = new Response();
                r->setMessage(str);
                r->setLog("Log of server");
                r->setStatusCode(200);
                result = Json::convertResponse(r);
            }
        }
        return result;
    }
};


#endif //PROYECTO_II_SERVER_CE2103_SERVERMANAGER_H
