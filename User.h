#include <iostream>
#include <string>
#include <vector>




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
	std::string getLocal();

};

