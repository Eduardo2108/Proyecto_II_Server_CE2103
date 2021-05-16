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
    int length = 9;
    int height = 18;

public:
    Field() {
        this->height = height;
        this->length = length;
        this->matrix = new Matrix(this->height, this->length);
    }

    void generateField(int obstacles) {

        for (int i = 1; i <= this->length; i++) {
            matrix->add(1, i, new BoundBox());
            matrix->add(this->height, i, new BoundBox());
        }
        for (int i = 1; i <= this->height; i++) {
            if (i <= 6 and i >= 4) {
                matrix->add(i, 1, new GoalLineBox());
                matrix->add(i, this->length, new GoalLineBox());
            } else {
                matrix->add(i, 1, new BoundBox());
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
