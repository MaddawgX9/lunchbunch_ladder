#include <iostream>
#include "tinyxml/tinyxml.h"

using namespace std;

class Entity
{
private:
    string _name;
    int _match_count;
    int _weight_count;
    
    void set_match_count(int match_count);
    void set_weight_count(int weight_count);

public:
    Entity();
    
    bool init(TiXmlElement* entity_e);
    TiXmlElement* create_xml_element();
    void set_name(string name);
    string get_name();
    void clear_weight_count();
    void inc_weight_count();
    void inc_match_count();
    int get_weight_count();
    int get_match_count();
};
