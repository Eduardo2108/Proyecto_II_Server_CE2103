//
// Created by eduardozumbadog on 5/19/21.
//

#ifndef PROYECTO_II_SERVER_CE2103_MESSAGE_H
#define PROYECTO_II_SERVER_CE2103_MESSAGE_H

#include "string"
#include "../../lib/rapidjson/rapidjson.h"
#include "../../lib/rapidjson/document.h"
#include "../../lib/rapidjson/writer.h"
#include "../../lib/rapidjson/stringbuffer.h"

using namespace std;

class Message {
private:
    string body;
    string request;
public:
    const string &getBody() const {
        return body;
    }

    void setBody(const string &body) {
        Message::body = body;
    }

    const string &getRequest() const {
        return request;
    }

    void setRequest(const string &request) {
        Message::request = request;
    }

public:
    /**
 * @brief Method for loading the object's information into a json
 * @param writer rapidjson writer instance.
 * @return true is success.
 */
    bool Serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) {
        writer->StartObject();

        writer->String("body");
        writer->String(this->getBody().c_str());
        writer->String("request");
        writer->String(this->getRequest().c_str());

        writer->EndObject();

        return true;
    }

    /**
 * @brief Method for loading the information of a json string into the object
 * @param string1 rapidjson object of the string parsed into a json.
 * @return true if success
 */
    bool Deserialize(const string &string1) {
        rapidjson::Document obj;
        obj.Parse(string1.c_str());
        this->setBody(obj["body"].GetString());
        this->setRequest(obj["request"].GetString());

        return true;
    }
};


#endif //PROYECTO_II_SERVER_CE2103_MESSAGE_H
