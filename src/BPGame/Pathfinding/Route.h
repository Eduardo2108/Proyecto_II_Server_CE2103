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
