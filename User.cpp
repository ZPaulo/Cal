#include "User.h"


User::User(string name)
{
	this->name = name;

	string open = "users/" + name;
	open += ".txt";

	ifstream user;
	user.open(open.c_str());
	string locals;
	string interests;

	if (user.is_open())
	{
		getline(user, interests);
		getline(user, locals);
		//User *user; //que merda é esta, zé? explica-me quando vires isto, pfv - zoid
	}

	user.close();

	istringstream ss(interests);

	while (ss)
	{
		string interest;
		if (!getline(ss, interest, ',')) break;
		this->interests.push_back(interest);
	}

	istringstream sss(locals);

	while (sss)
	{
		string local;
		if (!getline(sss, local, ',')) break;
		this->local.push_back(local);
	}

}

User::User(string name, vector<string> local, vector <string> interests)
{
	this->name = name;
	this->local = local;
	this->interests = interests;
}

vector<string> User::getInterests()
{
	return interests;
}

vector<string> User::getLocal()
{
	return local;
}

string User:: getName()
{
	return name;
}