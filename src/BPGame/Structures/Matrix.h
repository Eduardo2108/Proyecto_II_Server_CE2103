//
// Created by eduardozumbadog on 5/14/21.
//
#include "LinkedList.h"
#include "../Box/Box.h"
#include "../Box/NormalBox.h"
#include "../Box/ObstacleBox.h"
#include "../Box/GoalLineBox.h"
#include "../Box/BoundBox.h"

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
        for (int i = 0; i < rows; i++) {
            auto *newRow = new LinkedList<Box *>();
            for (int j = 0; j < columns; j++) {
                newRow->append(new NormalBox());
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
        if (row >= this->rows or column >= this->columns) {
            cerr << "Element: " << element << " not added, index out of range" << endl;
            return;
        } else {
            LinkedList<Box *> *matrix_row = this->list->get(row);
            matrix_row->append(element, column);
        }
    }

    string getBoxType(Box *c) {
        string temp;
        if (dynamic_cast<GoalLineBox*>(c) != nullptr) {
            temp = "|";
        }
        if (dynamic_cast<ObstacleBox*>(c) != nullptr) {
            temp = "O";
        }
        if (dynamic_cast<NormalBox*>(c) != nullptr) {
            temp = "-";
        }
        if (dynamic_cast<BoundBox*>(c) != nullptr) {
            temp = "*";
        }
        return temp;
    }

    void show() {
        if (this->rows == 0 and this->columns == 0)
            cout << "[]" << endl;
        else {
            for (int i = 0; i < this->rows; ++i) {
                 for (int j = 0; j < this->columns; ++j) {
                    cout << getBoxType(this->list->get(i)->get(j)) << " ";
                }
                cout <<   endl;
            }
        }
    }
};


#endif //BACKEND_MATRIX_H
