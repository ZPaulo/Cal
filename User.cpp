#include "User.h"


User::User(string name)
{
	this->name = name;

	string open = "users/" + name;
	open += ".txt";//the user file

	ifstream user;
	user.open(open.c_str());
	string areas;
	string interests;

	if (user.is_open())
	{
		getline(user, interests);//reads the user's interests
		getline(user, areas);//reads the user's areas
	}

	user.close();

	istringstream ss(interests);

	while (ss)//splits interests 
	{
		string interest;
		if (!getline(ss, interest, ',')) break;
		this->interests.push_back(interest);
	}

	istringstream sss(areas);

	while (sss)//splits areas
	{
		string area;
		if (!getline(sss, area, ',')) break;
		this->area.push_back(area);
	}

}

User::User(string name, vector<string> area, vector <string> interests)
{
	this->name = name;
	this->area = area;
	this->interests = interests;
}

vector<string> User::getInterests()
{
	return interests;
}

vector<string> User::getArea()
{
	return area;
}

string User:: getName()
{
	return name;
}