#include <iostream>
#include "tinyxml.h"

using namespace std;

class Entity
{
private:
    string _name;
    int _match_count;
    int _weight_count;
    int _wins;
    int _losses;
    string _pending_match;
    
    void set_match_count(int match_count);
    void set_weight_count(int weight_count);
    void set_num_wins(int num_wins);
    void set_num_losses(int num_losses);

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
    string get_pending_match();
    void set_pending_match(string opponant);
    int get_num_wins();
    void inc_wins();
    int get_num_losses();
    void inc_losses();
};
