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

    void updateMovement() {
        if (x_movement < 0) {
            column--;
            x_movement++;
        } else if (x_movement > 0) {
            column++;
            x_movement--;
        }
        if (y_movement < 0) {
            row++;
            y_movement++;
        } else if (y_movement > 0) {
            row--;
            y_movement--;
        }


    }

    void invert_y_movement() {
        this->y_movement = this->y_movement * -1;

    }

    void invert_x_movement() {
        this->x_movement = this->x_movement * -1;

    }

    int getNextColumn() const {
        if (this->x_movement == 0)
            return this->column;
        return (this->x_movement > 0) ? (this->column + 1) : (this->column - 1);
    }

    int getNextRow() const {
        if (this->y_movement == 0)
            return this->row;
        return (this->y_movement > 0) ? (this->row - 1) : (this->row + 1);
    }
};


#endif //PROYECTO_II_SERVER_CE2103_BALL_H
