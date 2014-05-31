#include "Conference.h"

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
	text = "";
	string textIn;

	if (conference.is_open())
	{
		getline(conference, textIn);
		text += textIn;
	}
}