//
// Created by eduardozumbadog on 5/14/21.
//

#ifndef BACKEND_BOX_H
#define BACKEND_BOX_H


#include <ostream>

class Box {
private:
    //Position to draw the box in
    int pos_x;
    //Position to draw the box in
    int pos_y;

    //
    int row;
    int column;
    bool hasBall = false;
public:
    bool isHasBall() const {
        return hasBall;
    }

    void setHasBall(bool hasBall) {
        this->hasBall = hasBall;
    }

    int getRow() const {
        return row;
    }

    void setRow(int row) {
        Box::row = row;
    }

    int getColumn() const {
        return column;
    }

    void setColumn(int column) {
        Box::column = column;
    }

public:
    virtual ~Box() = default;

    friend ostream &operator<<(ostream &os, const Box &box) {
        os << "pos_x: " << box.pos_x << " pos_y: " << box.pos_y;
        return os;
    }

public:
    int getPosX() const {
        return pos_x;
    }

    int getPosY() const {
        return pos_y;
    }

    void show() {
        cout << "{Row: " << this->row << " Column: " << this->column << " }" << endl;
    }
};


#endif //BACKEND_BOX_H
