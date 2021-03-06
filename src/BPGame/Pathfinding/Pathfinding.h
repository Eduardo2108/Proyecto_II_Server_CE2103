//
// Created by eduardozumbadog on 5/15/21.
//

#ifndef PROYECTO_II_SERVER_CE2103_PATHFINDING_H
#define PROYECTO_II_SERVER_CE2103_PATHFINDING_H

#include "Route.h"
#include "string"
#include "../../util/Structures/Matrix.h"
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

    bool Deserialize(string str) {
        rapidjson::Document obj;
        obj.Parse(str.c_str());
        this->setDirX(obj["dir_x"].GetInt());
        this->setDirY(obj["dir_y"].GetInt());
        this->setStrength(obj["strength"].GetInt());


        return true;
    }

    bool Serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) {

        writer->StartObject();

        writer->String("dir_x");
        writer->Int(this->dir_x);
        writer->String("dir_y");
        writer->Int(this->dir_y);
        writer->String("strength");
        writer->Int(this->strength);

        writer->EndObject();

        return true;
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

/**
 * @brief Method for loading the information of a json string into the object
 * @param obj rapidjson object of the string parsed into a json.
 * @return true if success
 */
    bool Deserialize(const string &basicString) {
        rapidjson::Document obj;
        obj.Parse(basicString.c_str());
        this->setStartX(obj["start_x"].GetInt());
        this->setStartY(obj["start_y"].GetInt());

        this->setEndX(obj["end_x"].GetInt());
        this->setEndY(obj["end_y"].GetInt());
        return true;
    }

/**
 * @brief Method for loading the object's information into a json
 * @param writer rapidjson writer instance.
 * @return true is success.
 */
    bool Serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) {
        writer->StartObject();

        writer->String("start_x");
        writer->Int(this->getStartX());
        writer->String("start_y");
        writer->Int(this->getStartY());


        writer->String("end_x");
        writer->Int(this->getEndX());
        writer->String("end_y");
        writer->Int(this->getEndY());

        writer->EndObject();

        return true;
    }

private:

    int end_x;
    int end_y;
};

class Pathfinding {

/**
 * @brief Method for giving the ball movement, based on the strength and direction the user selected
 * @param ball instance of the ball
 * @param shoot instance containing the information of the shot.
 */
    static void setMovement(Ball *ball, Shoot *shoot) {
        int strength = shoot->getStrength();
        int ball_move_x;
        int ball_move_y;
        // ASIGNAR M0VIMIENTO AL BAL??N
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

public:
    /**
     * @brief Method for calculating a shot, it counts the collisions and bound lines.
     * @param shoot instance containing the shot information
     * @param field instance of the field, it has an Matrix
     * @param ball instance of the ball
     * @return a list of boxes, which is the path the ball follows.
     */
    static Route *calculateShoot(Shoot *shoot, Field *field, Ball *ball) {
        Matrix *matrix = field->getMatrix();

        //SET THE BALL MOVEMENT
        setMovement(ball, shoot);
        int column = ball->getNextColumn();
        int row = ball->getNextRow();

        auto *route = new Route();
        field->setBall(false, row, column);

        while (ball->getXMovement() != 0 or ball->getYMovement() != 0) {
            Box *box = matrix->get(row, column);
            if (dynamic_cast<NormalBox *>(box) == nullptr) {
                if (dynamic_cast<GoalLineBox *>(box) != nullptr) {
                    route->addStep(box);
                    ball->setRow(5);
                    ball->setColumn(9);
                    break;
                }
                if (dynamic_cast<ObstacleBox *>(box) != nullptr) {
                    ball->invert_x_movement();
                    ball->invert_y_movement();
                }
                if (dynamic_cast<BoundBox *>(box) != nullptr) {
                    //route->addStep(box);
                    break;
                }
            } else {
                route->addStep(box);
            }
            ball->updateMovement();
            row = ball->getNextRow();
            column = ball->getNextColumn();
        }
        Box *pBox = matrix->get(ball->getRow(), ball->getColumn());
        pBox->setHasBall(true);
        return route;
    }
};


#endif //PROYECTO_II_SERVER_CE2103_PATHFINDING_H
