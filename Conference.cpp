#include "Conference.h"

Conference::Conference()
{
}


Conference::~Conference()
{
}

Conference::Conference(string name)
{
	this->name = name;
	string open = "texts/" + name;
	open += ".txt";//the complete file name
	ifstream conference;
	conference.open(open.c_str());
	text = "";
	string textIn;

	ostringstream out;

	out << conference.rdbuf();//inputs the whole file into a bufffer

	string s = out.str();//inputs the whole file into a string
	text = s;
}

string Conference:: getText()
{
	return text;
}

string Conference:: getName()
{
	return name;
}