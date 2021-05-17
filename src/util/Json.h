//
// Created by eduardozumbadog on 5/17/21.
//

#ifndef PROYECTO_II_SERVER_CE2103_JSON_H
#define PROYECTO_II_SERVER_CE2103_JSON_H

#include "../../lib/rapidjson/stringbuffer.h"
#include "../../lib/rapidjson/writer.h"
#include "vector"
#include "../../lib/rapidjson/document.h"

using namespace std;
using namespace rapidjson;

class Json {
public:
    static string convertRoute(Route *route) {

        Document generated_json;
        generated_json.SetArray();
        Document::AllocatorType &allocator = generated_json.GetAllocator();
        StringBuffer strbuf;
        Writer<rapidjson::StringBuffer> writer(strbuf);
        route->Serialize(&writer);

        return strbuf.GetString();
    }

    static string convertBox(Box *box) {

    }
};


#endif //PROYECTO_II_SERVER_CE2103_JSON_H
