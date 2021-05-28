//
// Created by eduardozumbadog on 5/14/21.
//

#ifndef BACKEND_FIELD_H
#define BACKEND_FIELD_H


#include "Box/Box.h"
#include "Box/NormalBox.h"
#include "Box/ObstacleBox.h"
#include "Box/GoalLineBox.h"
#include "Box/BoundBox.h"
#include "string"
#include "../../util/Structures/Matrix.h"
#include "../Pathfinding/Route.h"
#include <cstdio>

using namespace std;

class Field {
private:
    Matrix *matrix;
    int length = 18;
    int height = 9;

public:
    Field() {
        this->height = height;
        this->length = length;
        this->matrix = new Matrix(this->height, this->length);
    }

    Route *generateObstacles(int obstacles) {
        auto route = new Route();
        int randomRow;
        int randomColumnLeft;
        int randomColumnRight;
        int randomOffset;
        srand(time(0));

        for (int i = 1; i <= obstacles; i++) {
            auto *obstacleBox = new ObstacleBox();
            auto *obstacleBox2 = new ObstacleBox();


            randomRow = rand() % 7 + 2;
            randomOffset = rand() % 6 + 2;
            randomColumnLeft = 9 - randomOffset;
            randomColumnRight = 10 + randomOffset;


            cerr << "Fila aleatoria " << to_string(randomRow) << endl;
            cerr << "Columnas aleatorias " << to_string(randomColumnLeft) << " " << to_string(randomColumnRight)
                 << endl;
            obstacleBox->setRow(randomRow);
            obstacleBox->setColumn(randomColumnLeft);

            obstacleBox2->setRow(randomRow);
            obstacleBox2->setColumn(randomColumnRight);


             matrix->add(randomRow, randomColumnLeft, obstacleBox);
             matrix->add(randomRow, randomColumnRight, obstacleBox2);


            route->addStep(obstacleBox);
            route->addStep(obstacleBox2);
        }
        return route;
    }

    void generateField(int obstacles) {
        // upper and lower bounds.
        for (int i = 1; i <= this->length; i++) {
            auto *bound1 = new BoundBox();
            auto *bound2 = new BoundBox();
            bound1->setRow(1);
            bound1->setColumn(i);

            bound2->setRow(this->height);
            bound2->setColumn(i);

            matrix->add(1, i, bound1);
            matrix->add(this->height, i, bound2);
        }
        // left and right bounds, and goal lines.
        for (int i = 1; i <= this->height; i++) {
            if (i <= 6 and i >= 4) {
                auto *goal1 = new GoalLineBox();
                auto *goal2 = new GoalLineBox();
                goal1->setRow(i);
                goal1->setColumn(1);
                goal2->setRow(i);
                goal2->setColumn(this->length);
                matrix->add(i, 1, goal1);
                matrix->add(i, this->length, goal2);

            } else {
                auto *bound1 = new BoundBox();
                auto *bound2 = new BoundBox();
                bound1->setRow(i);
                bound1->setColumn(1);
                bound2->setRow(i);
                bound2->setColumn(this->height);
                matrix->add(i, 1, bound1);
                matrix->add(i, this->length, new BoundBox());
            }
        }
    }

    void show() {
        this->matrix->show();

    }

    Matrix *getMatrix() {
        return this->matrix;
    }

    void setBall(bool hasBall, int row, int column) {
        matrix->get(row, column)->setHasBall(hasBall);
    }
};


#endif //BACKEND_FIELD_H
