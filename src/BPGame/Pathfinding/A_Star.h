//
// Created by eduardozumbadog on 30/5/21.
//

#ifndef PROYECTO_II_SERVER_CE2103_A_STAR_H
#define PROYECTO_II_SERVER_CE2103_A_STAR_H

#include "../BPManager.h"
#include "StarAux.h"
#include <cmath>

class A_Star {
private:
    LinkedList<StarAux *> *openList = new LinkedList<StarAux *>();
    LinkedList<StarAux *> *closedList = new LinkedList<StarAux *>();
    //fixme inicializar esto valores
    int finish_x;
    int finish_y;

    static A_Star *pinstance_;

    static std::mutex mutex_;


public:
    static A_Star *GetInstance();

/**
 * @brief Method for getting the next element in the open list
 * @return element with the lowest F (weight+distance)
 */
    StarAux *getNext() {
        StarAux *temp = this->openList->get(0);
        for (int i = 1; i < this->openList->len; i++) {
            StarAux *current = this->openList->get(i);
            if (current->getWeightF() < temp->getWeightF())
                temp = current;
        }
        return temp;
    }

/**
 * @brief Method for getting the 8 boxes next to the one that's being processed
 * @param current actual box
 * @return list of boxes
 */
    void extend(StarAux *current) {

        int actualColumn = current->getBox()->getColumn();
        int actualRow = current->getBox()->getRow();

        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {

                if (i == 0 && j == 0) continue;
                Box *temp = BPManager::getInstance()->getField()->getMatrix()->get(actualRow + i, actualColumn + j);

                if (temp != nullptr && dynamic_cast<ObstacleBox *>(temp) == nullptr) {
                    int index = this->findOpenList(temp);
                    int movement_cost = ((abs(i) == abs(j)) ? 14 : 10);

                    if (index == -1) {
                        auto *newElement = new StarAux();
                        newElement->setBox(temp);
                        int distance = this->calculateDistance(newElement);
                        newElement->setPredecessor(current->getBox());
                        newElement->setWeight(current->getWeight() + movement_cost);
                        newElement->setDistanceH(distance);
                        newElement->setWeightF();

                        this->openList->append(newElement);

                    } else {
                        StarAux *old_value = this->openList->get(index);
                        int possibleWeight = current->getWeight() + movement_cost;
                        if (possibleWeight < old_value->getWeight()) {
                            old_value->setWeight(possibleWeight);
                            old_value->setPredecessor(current->getBox());
                            old_value->setWeightF();
                        } else {
                            continue;
                        }
                    }
                }
            }
        }
        current->setVisited(true);
        this->openList->del(current);
        this->closedList->append(current);
    }

    /**
     * @brief Method for calculating the heuristic distance
     * @param starAux element.
     * 
     */
    int calculateDistance(StarAux *starAux) {
        Box *box = starAux->getBox();
        int dist_x = abs(box->getColumn() - finish_x);
        int dist_y = abs(box->getRow() - finish_y);
        return ((dist_x + dist_y) * 10);

    }

    /**
     * @brief Search in the open list if there's an element with the given box
     * @param box element to search
     * @return position of the box
     *
     */
    int findOpenList(Box *box) {
        int result = -1;
        for (int i = 0; i < this->openList->getLen(); i++) {
            if (openList->get(i)->getBox() == box) {
                result = i;
                break;
            }
        }
        return result;
    }


    /**
     * @brief Search in the open list if there's an element with the given box
     * @param box element to search
     * @return position of the box
     *
     */
    StarAux *findClosedList(Box *box) {
        for (int i = 0; i < this->closedList->getLen(); i++) {
            if (closedList->get(i)->getBox() == box) {
                return closedList->get(i);

            }
        }
    }

/**
 * @brief this method calculates the pathfinding A* algorithm in the matrix
 * @param path an instance containing the start and ending points.
 * @return the fastest route between the points.
 */
    Route *aStar(Path *path) {
        // Inicializacion del algoritmo
        Box *f = BPManager::getInstance()->getField()->getMatrix()->get(path->getEndX(), path->getEndY());
        Box *s = BPManager::getInstance()->getField()->getMatrix()->get(path->getStartX(), path->getStartY());
        this->finish_x = f->getColumn();
        this->finish_y = f->getRow();


        auto *start = new StarAux();
        start->setBox(s);
        start->setPredecessor(nullptr);
        start->setWeight(0);
        int distance = this->calculateDistance(start);
        start->setDistanceH(distance);

        this->openList->append(start);

        //inicializacion de variables
        StarAux *current = this->getNext();;
        while (current->getBox() != f) {
            //obtener el siguiente
            current = this->getNext();
            //obtener los que estan cerca
            this->extend(current);
        }
        auto *route = new Route();
        StarAux *endPoint = this->findClosedList(f);
        while (endPoint->getPredecessor() != nullptr) {
            route->addFirst(endPoint->getBox());
            endPoint = this->findClosedList(endPoint->getPredecessor());
        }
        return route;

    }

/**
 * @brief This method calculates pathfinding and then uses the result to calculate a direction for the AI to shot.
 * the strength is a constant value.
 *
 * @param path receives the position of the AI and the goal line on which it has to score.
 *
 * @return a Shoot instance with the values of the shot.
 */
    Shoot *calculateShotAI(Path *path) {
        Box *start = this->aStar(path)->getFirst();
        int dir_x = 0;
        int dir_y = 0;
        if (path->getStartY() < start->getColumn()) {
            dir_x = 1;
        }
        if (path->getStartY() > start->getColumn()) {
            dir_x = -1;
        }
        if (path->getStartX() < start->getRow()) {
            dir_y = -1;
        }
        if (path->getStartX() > start->getRow()) {
            dir_y = 1;
        }


        Shoot *result = new Shoot();
        result->setDirX(dir_x);
        result->setDirY(dir_y);
        result->setStrength(70);
        return result;
    }

};


#endif //PROYECTO_II_SERVER_CE2103_A_STAR_H
