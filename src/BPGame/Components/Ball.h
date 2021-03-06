//
// Created by eduardozumbadog on 5/15/21.
//

#ifndef PROYECTO_II_SERVER_CE2103_BALL_H
#define PROYECTO_II_SERVER_CE2103_BALL_H

#include <iostream>
#include "string"

using namespace std;

/**
 * @brief Class that represents the ball into the game.
 */
class Ball {
private:
public:

private:
    //posicion en i
    int row = 5;
    // posicion en j
    int column = 9;
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

    /**
     * @brief This method checks the ball x_movement and y_movement fields and updates the ball position
     * in the proper way.
     */
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

    /**
     * @brief Method used for collisions, inverts the vertical movement.
     */
    void invert_y_movement() {
        this->y_movement = this->y_movement * -1;

    }

    /**
     * @brief Method used for collisions, inverts the horizontal movement.
     */
    void invert_x_movement() {
        this->x_movement = this->x_movement * -1;

    }

    /**
     * @brief Method for calculating the next column in the matrix
     */
    int getNextColumn() const {
        if (this->x_movement == 0)
            return this->column;
        return (this->x_movement > 0) ? (this->column + 1) : (this->column - 1);
    }

    /**
     * @brief Method for calculating the next row in the matrix
     */
    int getNextRow() const {
        if (this->y_movement == 0)
            return this->row;
        return (this->y_movement > 0) ? (this->row - 1) : (this->row + 1);
    }
};


#endif //PROYECTO_II_SERVER_CE2103_BALL_H
