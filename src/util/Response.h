//
// Created by eduardozumbadog on 5/17/21.
//

#ifndef PROYECTO_II_SERVER_CE2103_RESPONSE_H
#define PROYECTO_II_SERVER_CE2103_RESPONSE_H

#include "../../lib/rapidjson/rapidjson.h"
#include "../../lib/rapidjson/document.h"
#include "../../lib/rapidjson/writer.h"
#include "../../lib/rapidjson/stringbuffer.h"
class Response {
private:
    string log;
    string message;
    int statusCode;
public:
    const string &getLog() const {
        return log;
    }

    void setLog(const string &log) {
        Response::log = log;
    }

    const string &getMessage() const {
        return message;
    }

    void setMessage(const string &message) {
        Response::message = message;
    }

    int getStatusCode() const {
        return statusCode;
    }

    void setStatusCode(int statusCode) {
        Response::statusCode = statusCode;
    }

    bool Serialize(rapidjson::Writer <rapidjson::StringBuffer> *writer) {
        writer->StartObject();

        writer->String("status");
        writer->Int(this->getStatusCode());
        writer->String("log");
        writer->String(this->getLog().c_str());
        writer->String("message");
        writer->String(this->getMessage().c_str());


        writer->EndObject();

        return true;
    }

private:
    bool Deserialize(const rapidjson::Value &obj) {

        this->setStatusCode(obj["status"].GetInt());
        this->setLog(obj["log"].GetString());
        this->setMessage(obj["message"].GetString());


        return true;
    }

};


#endif //PROYECTO_II_SERVER_CE2103_RESPONSE_H
