#include "Entity.h"
#include <string>
#include <sstream>
#include "Xml_util.h"

using namespace std;

Entity::Entity():_weight_count(0),_match_count(0),_wins(0),_losses(0)
{
}

bool Entity::init(TiXmlElement* entity_e)
{
    Xml_util xml_util;

    string name = xml_util.get_string(entity_e,"Name");
    if(name=="")
    {
	printf("Failed to load entity, Name missing! Deleting entry.\n");
	return false;
    }
    set_name(name);

    int match_count = xml_util.get_int(entity_e,"Match_count");
    set_match_count(match_count);
    
    int weight_count = xml_util.get_int(entity_e,"Weight_count");
    set_weight_count(weight_count);

    string pending_match = xml_util.get_string(entity_e,"Pending_match");
    set_pending_match(pending_match);
    
    int num_wins = xml_util.get_int(entity_e,"Num_wins");
    set_num_wins(num_wins);

    int num_losses = xml_util.get_int(entity_e,"Num_losses");
    set_num_losses(num_losses);

    return true;
}

TiXmlElement* Entity::create_xml_element()
{
    TiXmlElement * entity_e = new TiXmlElement("Entity");

    Xml_util xml_util;

    xml_util.set_string(entity_e,"Name",get_name());
    
    xml_util.set_int(entity_e,"Match_count",get_match_count());

    xml_util.set_int(entity_e,"Weight_count",get_weight_count());

    xml_util.set_string(entity_e,"Pending_match",get_pending_match());
    
    xml_util.set_int(entity_e,"Num_wins",get_num_wins());

    xml_util.set_int(entity_e,"Num_losses",get_num_losses());

    return entity_e;
}

void Entity::set_name(string name)
{
    _name=name;
}

string Entity::get_name()
{
    return _name;
}

void Entity::clear_weight_count()
{
    _weight_count=0;
}

void Entity::inc_weight_count()
{
    _weight_count++;
}

void Entity::inc_match_count()
{
    _match_count++;
}

void Entity::set_match_count(int match_count)
{
    _match_count=match_count;
}

void Entity::set_weight_count(int weight_count)
{
    _weight_count=weight_count;
}

int Entity::get_match_count()
{
    return _match_count;
}

int Entity::get_weight_count()
{
    return _weight_count;
}

int Entity::get_num_wins()
{
    return _wins;
}

void Entity::set_num_wins(int num_wins)
{
    _wins=num_wins;
}

void Entity::inc_wins()
{
    _wins++;
}

int Entity::get_num_losses()
{
    return _losses;
}

void Entity::set_num_losses(int num_losses)
{
    _losses=num_losses;
}

void Entity::inc_losses()
{
    _losses++;
}

string Entity::get_pending_match()
{
    return _pending_match;
}

void Entity::set_pending_match(string opponant)
{
    _pending_match=opponant;
}
