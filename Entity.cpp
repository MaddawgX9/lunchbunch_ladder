#include "Entity.h"
#include <string>
#include <sstream>
using namespace std;

Entity::Entity():_weight_count(0),_match_count(0)
{
}

bool Entity::init(TiXmlElement* entity_e)
{
    //name
    TiXmlNode* name_node = entity_e->FirstChild("Name");
    TiXmlElement* name_e = name_node->ToElement();
    if(!name_e)return false;
    set_name(name_e->GetText());

    //match count
    TiXmlNode* mc_node = entity_e->FirstChild("Match_count");
    if(mc_node)
    {
	TiXmlElement* mc_e = mc_node->ToElement();
	if(!mc_e)return false;
	set_match_count(atoi(mc_e->GetText()));
    }
    
    //weight count
    TiXmlNode* weight_node = entity_e->FirstChild("Weight_count");
    if(weight_node)
    {
	TiXmlElement* weight_e = weight_node->ToElement();
	if(!weight_e)return false;
	set_weight_count(atoi(weight_e->GetText()));
    }    
    return true;
}

TiXmlElement* Entity::create_xml_element()
{
    TiXmlElement * entity_e = new TiXmlElement("Entity");

    //name
    TiXmlElement * name_e = new TiXmlElement("Name");
    TiXmlText * name_text_e = new TiXmlText(get_name().c_str());
    name_e->LinkEndChild(name_text_e);
    entity_e->LinkEndChild(name_e);

    //match count
    TiXmlElement * mc_e = new TiXmlElement("Match_count");
    stringstream out;
    out << get_match_count();
    TiXmlText * mc_text_e = new TiXmlText(out.str().c_str());
    mc_e->LinkEndChild(mc_text_e);
    entity_e->LinkEndChild(mc_e);

    //weight count
    TiXmlElement * weight_e = new TiXmlElement("Weight_count");
    out.str("");
    out << get_weight_count();
    TiXmlText * weight_text_e = new TiXmlText(out.str().c_str());
    weight_e->LinkEndChild(weight_text_e);
    entity_e->LinkEndChild(weight_e);
    
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
