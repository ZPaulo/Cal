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
	open += ".txt";
	ifstream conference;
	conference.open(open.c_str());
	text = "";
	string textIn;

	ostringstream out;

	out << conference.rdbuf();

	string s = out.str();
	text = s;
}