//
// Created by eduardozumbadog on 5/14/21.
//
#include "LinkedList.h"
#include "../Components/Box/Box.h"
#include "../Components/Box/NormalBox.h"
#include "../Components/Box/ObstacleBox.h"
#include "../Components/Box/GoalLineBox.h"
#include "../Components/Box/BoundBox.h"

#ifndef BACKEND_MATRIX_H
#define BACKEND_MATRIX_H


class Matrix {

private:
    int columns;// vertical lines in the matrix

    int rows; // horizontal lines in the matrix

    LinkedList<LinkedList<Box *> *> *list;
public:
    Matrix(int rows, int columns) {
        this->rows = rows;
        this->columns = columns;
        this->list = new LinkedList<LinkedList<Box *> *>();
        //add the horizontal rows
        for (int i = 1; i <= rows; i++) {
            auto *newRow = new LinkedList<Box *>();
            for (int j = 1; j <= columns; j++) {
                NormalBox *new_element = new NormalBox();
                new_element->setRow(i);
                new_element->setColumn(j);
                newRow->append(new_element);
            }
            this->list->append((newRow));
        }
    }

    /**
     * Method for adding an element in the matrix position (i, j)
     * @param row i position of the new element on the matrix, must be minor to the rows field set in the constructor
     * @param column j position of the element.
     * @param element to be added on the matrix
     */
    void add(int row, int column, Box *element) {
        if (row > this->rows or column > this->columns) {
            cerr << "Element: " << element << " not added, index out of range" << endl;
            return;
        } else {
            LinkedList<Box *> *matrix_row = this->list->get(row - 1);
            matrix_row->append(element, column - 1);
        }
    }

    string getBoxType(Box *c) {
        string temp;
        if (dynamic_cast<GoalLineBox *>(c) != nullptr) {
            temp = "|";
        }
        if (dynamic_cast<ObstacleBox *>(c) != nullptr) {
            temp = "O";
        }
        if (dynamic_cast<NormalBox *>(c) != nullptr) {
            temp = (c->isHasBall()) ? "x" : "-";
        }
        if (dynamic_cast<BoundBox *>(c) != nullptr) {
            temp = (c->isHasBall()) ? "x" : "*";
        }
        return temp;
    }

    void show() {
        if (this->rows == 0 and this->columns == 0)
            cout << "[]" << endl;
        else {
            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < this->columns; j++) {
                    cout << getBoxType(this->list->get(i)->get(j)) << " ";
                }
                cout << endl;
            }
        }
    }

    Box *get(int row, int column) {
        Box *result;
        if (this->rows == 0 and this->columns == 0)
            result = nullptr;
        else {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    result = this->list->get(i)->get(j);
                }
            }
        }
        return result;
    }
};


#endif //BACKEND_MATRIX_H
