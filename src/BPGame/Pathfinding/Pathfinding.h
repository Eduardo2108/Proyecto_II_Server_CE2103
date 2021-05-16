//
// Created by eduardozumbadog on 5/15/21.
//

#ifndef PROYECTO_II_SERVER_CE2103_PATHFINDING_H
#define PROYECTO_II_SERVER_CE2103_PATHFINDING_H

#include "Route.h"
#include "string"
#include "../Structures/Matrix.h"
#include "../Components/Ball.h"
#include "../Components/Field.h"

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
    static Route *calculateShoot(Shoot *shoot, Field *field, Ball *ball) {
        Matrix *matrix = field->getMatrix();
        //SET THE BALL MOVEMENT
        setMovement(ball, shoot);
        int column = ball->getColumn();
        int row = ball->getRow();
        int x_movement = ball->getXMovement();
        int y_movement = ball->getYMovement();
        auto *route = new Route();
        field->setBall(false, row, column);
        while (x_movement != 0 or y_movement != 0) {
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
            Box *box = matrix->get(row, column);
            if (dynamic_cast<NormalBox *>(box) == nullptr) {
                if (dynamic_cast<GoalLineBox *>(box) != nullptr) {
                    cout << "La casilla siguiente es de gol: " << endl;
                    cerr << "siiiiiiiiiiiiiiiiuuuuuuuuuuuuuuuuuuuuuuuu" << endl;
                    box->show();
                }
                if (dynamic_cast<ObstacleBox *>(box) != nullptr) {
                    cout << "La casilla siguiente es de obstaculo: " << endl;
                    box->show();
                }
                if (dynamic_cast<BoundBox *>(box) != nullptr) {
                    cout << "La casilla siguiente es de limite: " << endl;
                    box->show();
                }
                route->addStep(box);
                break;
            } else {
                cout << "La casilla siguiente es normal: " << endl;
                box->show();
                route->addStep(box);
            }


        }
        matrix->get(row, column)->setHasBall(true);
        cout << "Final Ball x position: " << column << endl;
        cout << "Final Ball y position: " << row << endl;
        return route;
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
