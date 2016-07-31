#include <iostream>
#include <vector>
#include "Entity.h"
#include "tinyxml.h"

class Ladder
{
private:
    char * _filename;
    vector<Entity*> _entity_list;

    bool load_entity(TiXmlElement * entity_e);
    Entity* get_random_entity();
    Entity* get_weighted_entity();
public:

    Ladder();
    ~Ladder();
    
    bool load(char * filename);
    bool save();
    void create_entity(string name);
    void generate_matchup();
    void adjust_match_counts(Entity* entity_1,Entity* entity_2);
    void print();
};
