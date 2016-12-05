#include "Ladder.h"
#include "tinystr.h"
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <random>
#include <regex>

using namespace std;

Ladder::Ladder()
{
}

Ladder::~Ladder()
{
    while(!_entity_list.empty())
    {
	delete _entity_list.back();
	_entity_list.pop_back();
    }
}

bool Ladder::load(char * filename)
{
    _filename=filename;

    TiXmlDocument doc(filename);
    if(!doc.LoadFile()) return false;

    bool result=true;
    for(TiXmlElement* entity_e=doc.FirstChildElement();result&&entity_e;entity_e=entity_e->NextSiblingElement())
    {
	result=load_entity(entity_e);
    }
    return result;
}


bool Ladder::load_entity(TiXmlElement* entity_e)
{
    Entity* entity = new Entity();
    if(entity->init(entity_e))
	_entity_list.push_back(entity);
    else
	delete entity;
    return true;
}

bool Ladder::save()
{
    if(_filename)
    {
	TiXmlDocument doc;
	TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0","","");
	doc.LinkEndChild(decl);

	vector<Entity*>::iterator cur = _entity_list.begin();
	vector<Entity*>::iterator end = _entity_list.end();
	
	for(;cur!=end;cur++)
	{
	    Entity * entity = *cur;

	    TiXmlElement * entity_e = entity->create_xml_element();
	    
	    doc.LinkEndChild(entity_e);
	    doc.SaveFile(_filename);
	}
    }
}

void Ladder::create_entity(string name)
{
    if(name.length()>0)
    {
	Entity * entity = new Entity();
	entity->set_name(name);
	cout << "SET ENTITY NAME TO: " << name;
	_entity_list.push_back(entity);
    }
    else
	cout << "Failed to create entity! Invalid Name." << endl;
}

void Ladder::print()
{
    cout << string(20,'=') << endl;
    cout << "LunchBunch Ladder:" << endl;
    cout << string(20,'=') << endl;
    
    vector<Entity*>::iterator cur = _entity_list.begin();
    vector<Entity*>::iterator end = _entity_list.end();

    string row_format="%-4s %-20s %-6s %12s %-20s %3s %3s\n";
    printf(row_format.c_str(),"Rank","Name","Weight","Match Count","Pending Match","Wins","Losses");
    
    row_format="%-4d %-20s %-6d %12d %-20s %3d %3d\n";
    int count = 1;
    for(;cur!=end;cur++,count++)
    {
	Entity * entity = *cur;

	int match_count = entity->get_match_count();
	int weight = entity->get_weight_count();
	const char * name = entity->get_name().c_str();
	int num_wins = entity->get_num_wins();
	int num_losses = entity->get_num_losses();
	const char * pending_match = entity->get_pending_match().c_str();

	printf(row_format.c_str(),count,name,weight,match_count,pending_match,num_wins,num_losses);
    }
}

void Ladder::generate_matchup()
{
    if(_entity_list.size()>1)
    {
	Entity* entity_1=get_random_entity();
	Entity* entity_2=get_random_entity();
	while(entity_1==entity_2)
	{
	    entity_2=get_weighted_entity();
	}
	cout << "The Matchup is:" << endl;
	cout << entity_1->get_name() << " vs. " << entity_2->get_name() << endl;
	cout << endl;
	cout << "Do you wish to initiate this matchup? (y/n)" << endl;
	string result;
	getline(cin,result);
        if(regex_match(result,regex("y|yes",regex_constants::icase)))
        {
	    entity_1->set_pending_match(entity_2->get_name());
	    entity_2->set_pending_match(entity_1->get_name());
	    adjust_match_counts(entity_1,entity_2);
	    cout << "Matchup Approved!" << endl;
	}
	else
	    cout << "Matchup Cancelled" << endl;
    }
    else
	cout << "Not enough entities to generate a match!" << endl;
}

Entity* Ladder::get_weighted_entity()
{
    vector<Entity*> weighted_entity_list;
    vector<Entity*>::iterator cur = _entity_list.begin();
    vector<Entity*>::iterator end = _entity_list.end();

    int add_count=0;
    for(;cur!=end;cur++)
    {
	Entity * entity = *cur;

	bool added=false;
	for(int weight=entity->get_weight_count();weight>0;weight--)
        {
	    weighted_entity_list.push_back(entity);
	    added=true;
	}
	if(added)
	    add_count++;
    }
    if(add_count<2)
    {
	cur = _entity_list.begin();
        for(;cur!=end;cur++)
	{
	    Entity * entity = *cur;
	    entity->inc_weight_count();
	}
	return get_weighted_entity();
    }
    
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0,_entity_list.size()-1);
    int index=dist(mt);
    
    Entity * entity=weighted_entity_list[index];
    return entity;
}

Entity* Ladder::get_random_entity()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0,_entity_list.size()-1);
    int index=dist(mt);
    
    /*    srand(time(0));   
	  int random_num = rand();
	  int index = random_num % _entity_list.size(); // for now not weighted
    */
    Entity * entity=_entity_list[index];
    return entity;
}

void Ladder::adjust_match_counts(Entity* entity_1,Entity* entity_2)
{

    vector<Entity*>::iterator cur = _entity_list.begin();
    vector<Entity*>::iterator end = _entity_list.end();

    for(;cur!=end;cur++)
    {
	Entity * entity = *cur;
	
	if(entity==entity_1||entity==entity_2)
        {
	    entity->clear_weight_count();
	    entity->inc_match_count();
	}	
	else
	    entity->inc_weight_count();
    }    
}
