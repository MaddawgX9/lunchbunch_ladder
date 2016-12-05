#include "Xml_util.h"
#include <string>
#include <sstream>
using namespace std;

string Xml_util::get_string(TiXmlElement* entity_e,string key)
{
    TiXmlNode* node = entity_e->FirstChild(key.c_str());
    TiXmlElement* elem = node->ToElement();
    string text_to_return;
    if(elem)
    {
	const char * elem_text = elem->GetText();
	if(elem_text != NULL && elem_text[0] != '\0')
	    text_to_return = elem->GetText();
    }
    return text_to_return;
}

int Xml_util::get_int(TiXmlElement* entity_e, string key)
{
    TiXmlNode* node = entity_e->FirstChild(key.c_str());
    if(node)
    {
	TiXmlElement* elem = node->ToElement();
	if(!elem)
	    return 0;
	else
	    return stoi(elem->GetText());
    }

}

void Xml_util::set_string(TiXmlElement* entity_e,string key,string value)
{
    TiXmlElement * elem = new TiXmlElement(key.c_str());
    TiXmlText * text_elem = new TiXmlText(value.c_str());
    elem->LinkEndChild(text_elem);
    entity_e->LinkEndChild(elem);
}

void Xml_util::set_int(TiXmlElement* entity_e,string key,int value)
{
    TiXmlElement * elem = new TiXmlElement(key.c_str());
    stringstream out;
    out << value;
    TiXmlText * text_elem = new TiXmlText(out.str().c_str());
    elem->LinkEndChild(text_elem);
    entity_e->LinkEndChild(elem);

}
