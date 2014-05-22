#include "User.h"



User::User(){
}

User::User(string name, string local, vector <string> interests)
{
	this->name = name;
	this->local = local;
	this->interests = interests;
}

vector<string> User::getInterests()
{
	return interests;
}

string User::getLocal()
{
	return local;
}