#include "Conference.h"
#include <fstream>

using namespace std;

Conference::Conference()
{
}


Conference::~Conference()
{
}

Conference::Conference(string name)
{
	ifstream conference;
	conference.open(name + ".txt");
	this->text = "";
	string text;

	if (conference.is_open())
	{
		getline(conference, text);
		this->text += text;
	}
}