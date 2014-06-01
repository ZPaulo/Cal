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
	std::vector <std::string> area;

public:
	User();
	User(std::string name);
	User(std::string name, std::vector <std::string> area, std::vector <std::string> interests);

	std::vector<std::string> getInterests();
	vector <std::string> getArea();
	string getName();

};

