//
// Created by eduardozumbadog on 30/5/21.
//

#ifndef PROYECTO_II_SERVER_CE2103_STARAUX_H
#define PROYECTO_II_SERVER_CE2103_STARAUX_H
using namespace std;

#include <climits>
#include "../Components/Box/Box.h"

class StarAux {
private:
    int weight = INT_MAX;
    int distance_H;
    int weight_F;
    Box *box;
    Box *predecessor;
    bool visited;
public:
    int getWeight() const {
        return weight;
    }

    void setWeight(int weight) {
        StarAux::weight = weight;
    }

    int getDistanceH() const {
        return distance_H;
    }

    void setDistanceH(int distanceH) {
        distance_H = distanceH;
    }

    int getWeightF() {
        return weight_F;
    }

    void setWeightF(int weightF) {
        weight_F = weightF;
    }

    void setWeightF() {
        weight_F = this->weight + this->distance_H;
    }

    Box *getBox() {
        return box;
    }

    void setBox(Box *box) {
        StarAux::box = box;

    }

     Box *getPredecessor() {
        return predecessor;
    }

    void setPredecessor(Box *predecessor) {
        StarAux::predecessor = predecessor;
    }

    bool isVisited() const {
        return visited;
    }

    void setVisited(bool visited) {
        StarAux::visited = visited;
    }

    bool operator<(const StarAux &rhs) const {
        return weight_F < rhs.weight_F;
    }

    bool operator>(const StarAux &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const StarAux &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const StarAux &rhs) const {
        return !(*this < rhs);
    }
};


#endif //PROYECTO_II_SERVER_CE2103_STARAUX_H
