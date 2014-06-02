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

	if (userList.is_open())//l� os utilizadores todos
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


	if (conferenceList.is_open())//l� as confer�ncias todas
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
	int countInt,countAre, totalWords;//contagem de palavras
	bool hasMatches = false;//verfica se houve correspond�ncias entre um user e alguma das confer�ncias
	string interestsName, areas, conferenceName;

	for(int i = 0; i < users.size(); i++)//percorre todos os utilizadores
	{
		cout << "The User: " << users[i].getName() << endl;
		vector<string> area = users[i].getArea();
		vector<string> interests = users[i].getInterests();
		totalWords = interests.size();//actualiza o total de palavras que est�o a ser procuradas
		conferenceName = "";

		for(int j = 0; j < conferences.size();j++)//percorre as confer�ncias todas
		{
			interestsName = "";
			areas = "";
			countAre = 0;
			countInt = 0;
			for(int k = 0; k < area.size();k++)//percorre todas as �reas do utilizador
			{
				if(KMP(conferences[j].getText(),area[k]))//procura a �rea na confer�ncia
				{
					countAre++;
					if (!KMP (areas, area[k]))
						areas += area[k]  + " ";
				}
			}
			if(countAre > 0)//se nao encontrou nenhuma �rea, n�o procura os interesses
			{
				for(int k = 0; k < interests.size();k++)
				{
					if(KMP(conferences[j].getText(),interests[k])){
						countInt++;
						if (!KMP (interestsName, interests[k]))
							interestsName += interests[k]  + " ";
					}
				}				
			}
			if ((double) countInt /totalWords > 0)//caso tenha encontrado pelo menos uma correspond�ncia nesta confer�ncia
			{
				double match = (double)80 * (log(countInt) / log(totalWords)) + countAre*(20 / area.size());
				cout <<  "- Has " << match <<  "% matches with the conference: " <<  conferences[j].getName() << "\n\tIn the areas: " << areas <<"\n\tWith the interests: "  << interestsName << endl;
				hasMatches = true;
				if (match > 70)
					conferenceName += conferences[j].getName() + " ";
				
			}

		}

		if (!hasMatches)//caso n�o tenha encontrado nenhuma correspond�ncia em nenhuma confer�ncia
			cout << "No matches were found!" << endl;
		else if (conferenceName != "")
			cout << endl << endl << users[i].getName() << " has the following suggested conferences: " << conferenceName << endl;
			
		hasMatches = false;
		cout << endl;
	}
}
Database::~Database()
{

}