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
#include "../Structures/Matrix.h"

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

    void generateField(int obstacles) {

        for (int i = 1; i <= this->length; i++) {
            BoundBox *bound1 = new BoundBox();
            BoundBox *bound2 = new BoundBox();
            bound1->setRow(1);
            bound1->setColumn(i);

            bound2->setRow(this->height);
            bound2->setColumn(i);

            matrix->add(1, i, bound1);
            matrix->add(this->height, i, bound2);
        }
        for (int i = 1; i <= this->height; i++) {
            if (i <= 6 and i >= 4) {
                GoalLineBox *goal1 = new GoalLineBox();
                GoalLineBox *goal2 = new GoalLineBox();
                ObstacleBox *ob1;

                ob1 = new ObstacleBox();


                goal1->setRow(i);
                goal1->setColumn(1);
                goal2->setRow(i);
                goal2->setColumn(this->length);


                ob1->setRow(i);
                ob1->setColumn(9);


                matrix->add(i, 1, goal1);
                matrix->add(i, this->length, goal2);
                matrix->add(i, 9, ob1);

            } else {
                BoundBox *bound1 = new BoundBox();
                BoundBox *bound2 = new BoundBox();
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
