#include <iostream>
#include "tinyxml.h"

using namespace std;

class Xml_util
{
 public:
    string get_string(TiXmlElement* entity,string key);
    int get_int(TiXmlElement* entity,string key);
    void set_string(TiXmlElement* entity,string key,string value);
    void set_int(TiXmlElement* entity,string key,int value);
};
