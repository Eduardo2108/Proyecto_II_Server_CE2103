//
// Created by eduardozumbadog on 5/15/21.
//

#ifndef PROYECTO_II_SERVER_CE2103_ROUTE_H
#define PROYECTO_II_SERVER_CE2103_ROUTE_H

#include "../../util/Structures/LinkedList.h"
#include "../Components/Box/Box.h"

class Route {

private:
    LinkedList<Box *> *route = new LinkedList<Box *>();
public:
    /**
 * @brief Method for loading the information of a json string into the object
 * @param obj rapidjson object of the string parsed into a json.
 * @return true if success
 */
    bool Deserialize(const std::string &s) {
        rapidjson::Document doc;
        doc.Parse(s.c_str());
        if (!doc.IsArray())
            return false;
        for (rapidjson::Value::ConstValueIterator itr = doc.Begin(); itr != doc.End(); ++itr) {
            Box *p = new Box();
            p->Deserialize(*itr);
            this->route->append(p);
        }
        return true;

    };

/**
 * @brief Method for loading the object's information into a json
 * @param writer rapidjson writer instance.
 * @return true is success.
 */
    bool Serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const {
        writer->StartArray();

        for (int i = 0; i < this->route->len; i++) {
            Box *b = this->route->get(i);
            (b)->Serialize(writer);
        }
        writer->EndArray();
        return true;

    };

    LinkedList<Box *> *getRoute() {
        return route;
    }

    void addStep(Box *box) {
        this->route->append(box);
    }

    void addFirst(Box *box) {
        this->route->addFirst(box);
    }

    Box *getFirst() {
        return this->route->get(0);
    }

    Box *getLast() {
        return this->route->get(this->route->len - 1);
    }

    void show() {
        cout << "---- Route ----" << endl;
        for (int i = 0; i < this->route->len; ++i) {
            cout << i + 1 << " --> ";
            route->get(i)->show();
        }
        cout << "---- ---- ----" << endl;

    }
};


#endif //PROYECTO_II_SERVER_CE2103_ROUTE_H
