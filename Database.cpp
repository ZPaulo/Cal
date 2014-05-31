#include "Database.h"
#include <fstream>
#include <string>

using namespace std;

Database::Database()
{

}

void Database::initialize()
{
	ifstream userList;
	userList.open("UserList.txt");
	string fileName;

	if (userList.is_open())
	while (!userList.eof())
	{
		getline(userList, fileName);
		User *user = new User(fileName);
		this->users.push_back(user);
	}
	userList.close();

	ifstream conferenceList;
	userList.open("ConferenceList.txt");
	

	if (conferenceList.is_open())
	while (!conferenceList.eof())
	{
		getline(conferenceList, fileName);
		Conference *conference = new Conference(fileName);
		this->conferences.push_back(conference);
	}
	userList.close();
}