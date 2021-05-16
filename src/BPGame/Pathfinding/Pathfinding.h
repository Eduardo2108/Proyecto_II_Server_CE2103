//
// Created by eduardozumbadog on 5/15/21.
//

#ifndef PROYECTO_II_SERVER_CE2103_PATHFINDING_H
#define PROYECTO_II_SERVER_CE2103_PATHFINDING_H

#include "Route.h"
#include "string"
#include "../Structures/Matrix.h"
#include "../Components/Ball.h"

class Shoot {
    int strength;
    int dir_x;
public:
    int getStrength() const {
        return strength;
    }

    void setStrength(int strength) {
        Shoot::strength = strength;
    }

    int getDirX() const {
        return dir_x;
    }

    void setDirX(int dirX) {
        dir_x = dirX;
    }

    int getDirY() const {
        return dir_y;
    }

    void setDirY(int dirY) {
        dir_y = dirY;
    }

private:
    int dir_y;
};

class Path {
    int start_x;
    int start_y;
public:
    int getStartX() const {
        return start_x;
    }

    void setStartX(int startX) {
        start_x = startX;
    }

    int getStartY() const {
        return start_y;
    }

    void setStartY(int startY) {
        start_y = startY;
    }

    int getEndX() const {
        return end_x;
    }

    void setEndX(int endX) {
        end_x = endX;
    }

    int getEndY() const {
        return end_y;
    }

    void setEndY(int endY) {
        end_y = endY;
    }

private:

    int end_x;
    int end_y;
};

class Pathfinding {
public:
    static Route *calculateShoot(Shoot *shoot, Matrix *matrix, Ball *ball) {
        //SET THE BALL MOVEMENT
        setMovement(ball, shoot);
        int column = ball->getColumn();
        int row = ball->getRow();
        int x_movement = ball->getXMovement();
        int y_movement = ball->getYMovement();


        while (x_movement != 0 or y_movement != 0) {
            cout << "Ball x position: " << column << endl;
            cout << "Ball y position: " << row << endl;
            if (x_movement < 0) {
                column--;
                x_movement++;
            } else {
                column++;
                x_movement--;
            }
            if (y_movement < 0) {
                row--;
                y_movement++;
            } else {
                row++;
                y_movement--;
            }
            cout << "New Ball x position: " << column << endl;
            cout << "New Ball y position: " << row << endl;
            cout << "--------------------" << endl;
        }
        cout << "Final Ball x position: " << column << endl;
        cout << "Final Ball y position: " << row << endl;
    }

    static void setMovement(Ball *ball, Shoot *shoot) {
        int strength = shoot->getStrength();
        int ball_move_x;
        int ball_move_y;
        // ASIGNAR M0VIMIENTO AL BALÓN
        //caso de movimiento normal.
        if (!shoot->getDirX() or !shoot->getDirY()) {
            ball_move_x = strength * shoot->getDirX();
            ball_move_y = strength * shoot->getDirY();
        } else {
            //CASO DE MOVIMIENTO DIAGONAL
            ball_move_x = (strength / 2) * shoot->getDirX();
            ball_move_y = (strength / 2) * shoot->getDirY();
        }
        ball->setXMovement(ball_move_x);
        ball->setYMovement(ball_move_y);
    }
};


#endif //PROYECTO_II_SERVER_CE2103_PATHFINDING_H
