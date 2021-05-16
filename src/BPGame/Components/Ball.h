//
// Created by eduardozumbadog on 5/15/21.
//

#ifndef PROYECTO_II_SERVER_CE2103_BALL_H
#define PROYECTO_II_SERVER_CE2103_BALL_H

#include <iostream>
#include "string"

using namespace std;

class Ball {
private:
public:

private:
    //posicion en i
    int row = 5;
    // posicion en j
    int column = 2;
public:
    int getYMovement() const {
        return y_movement;
    }

    void setYMovement(int yMovement) {
        y_movement = yMovement;
    }

    int getXMovement() const {
        return x_movement;
    }

    void setXMovement(int xMovement) {
        x_movement = xMovement;
    }

    void show() {
        cout << "Position in matrix: " << "(" + to_string(this->row) + ", " + to_string(this->column) + ")" << endl
             << "Movement: " << "X= " + to_string(this->x_movement) + " Y= " + to_string(this->y_movement) << endl;
    }

private:
    //cantidad de movimiento en x
    int y_movement = 0;
    //cantidad de movimiento en y
    int x_movement = 0;
public:
    int getRow() const {
        return row;
    }

    void setRow(int row) {
        Ball::row = row;
    }

    int getColumn() const {
        return column;
    }

    void setColumn(int column) {
        Ball::column = column;
    }
};


#endif //PROYECTO_II_SERVER_CE2103_BALL_H
