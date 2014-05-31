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
	{
		while (!userList.eof())
		{
			getline(userList, fileName);
			User user(fileName);
			users.push_back(user);
		}
		userList.close();
	}

	ifstream conferenceList;
	conferenceList.open("ConferenceList.txt");


	if (conferenceList.is_open())
	{
		while (!conferenceList.eof())
		{
			getline(conferenceList, fileName);
			Conference conference(fileName);
			this->conferences.push_back(conference);
		}
		conferenceList.close();
	}
}

void Database:: matches()
{
	int count, totalWords;
	for(int i = 0; i < users.size(); i++)
	{
		cout << "The User: " << users[i].getName() << endl;
		count = 0;
		vector<string> area = users[i].getLocal();
		vector<string> interests = users[i].getInterests();
		totalWords = area.size() + interests.size();
		for(int j = 0; j < conferences.size();j++)
		{
			for(int k = 0; k < area.size();k++)
			{
				if(KMP(conferences[j].getText(),area[k]))
					count++;
			}
			if(count > 0)
			{
				for(int k = 0; k < interests.size();k++)
				{
					if(KMP(conferences[j].getText(),interests[k]))
						count++;
				}
				

			}
		cout <<  "- Has " << (double) count/totalWords <<  "% matches with the conference: " <<  conferences[j].getName() << "." << endl;
		}
		cout << endl;
	}
}


Database::~Database()
{

}