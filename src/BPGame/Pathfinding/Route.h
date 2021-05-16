//
// Created by eduardozumbadog on 5/15/21.
//

#ifndef PROYECTO_II_SERVER_CE2103_ROUTE_H
#define PROYECTO_II_SERVER_CE2103_ROUTE_H

#include "../Structures/LinkedList.h"
#include "../Components/Box/Box.h"

class Route {

private:
    LinkedList<Box *> *route = new LinkedList<Box *>();
public:
    const LinkedList<Box *> *getRoute() const {
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
            cout << i << " --> ";
            route->get(i)->show();
        }
        cout << "---- ---- ----" << endl;

    }
};


#endif //PROYECTO_II_SERVER_CE2103_ROUTE_H
