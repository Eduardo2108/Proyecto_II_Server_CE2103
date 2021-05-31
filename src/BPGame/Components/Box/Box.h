//
// Created by eduardozumbadog on 5/14/21.
//

#ifndef BACKEND_BOX_H
#define BACKEND_BOX_H


#include <ostream>
#include "../../../../lib/rapidjson/rapidjson.h"
#include "../../../../lib/rapidjson/document.h"
#include "../../../../lib/rapidjson/writer.h"
#include "../../../../lib/rapidjson/stringbuffer.h"

class Box {
private:
    //Position to draw the box in
    int pos_x;
    //Position to draw the box in
    int pos_y;

    //
    int row = INT16_MAX;
    int column = INT16_MAX;
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

    bool Deserialize(const rapidjson::Value &obj) {

        this->setRow(obj["row"].GetInt());
        this->setColumn(obj["column"].GetInt());


        return true;
    }

    bool Serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) {
        writer->StartObject();

        writer->String("row");
        writer->Int(this->getRow());
        writer->String("column");
        writer->Int(this->getColumn());


        writer->EndObject();

        return true;
    }

    friend ostream &operator<<(ostream &os, const Box &box) {
        os << "pos_x: " << box.pos_x << " pos_y: " << box.pos_y;
        return os;
    }

    bool operator==(const Box &rhs) const {
        return row == rhs.row &&
               column == rhs.column;
    }

    bool operator!=(const Box &rhs) const {
        return !(rhs == *this);
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
