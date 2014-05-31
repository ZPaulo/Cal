#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;




class User{

private:
	std::string name;
	std::vector <std::string> interests;
	std::vector <std::string> local;

public:
	User();
	User(std::string name);
	User(std::string name, std::vector <std::string> local, std::vector <std::string> interests);

	std::vector<std::string> getInterests();
	vector <std::string> getLocal();
	string getName();

};

