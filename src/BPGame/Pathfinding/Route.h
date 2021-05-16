//
// Created by eduardozumbadog on 5/15/21.
//

#ifndef PROYECTO_II_SERVER_CE2103_ROUTE_H
#define PROYECTO_II_SERVER_CE2103_ROUTE_H

#include "../Structures/LinkedList.h"
#include "../Components/Box/Box.h"

class Route {

private:
    LinkedList<Box *> *route;
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
};


#endif //PROYECTO_II_SERVER_CE2103_ROUTE_H
