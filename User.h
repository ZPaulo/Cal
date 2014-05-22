#include <iostream>
#include <string>
#include <vector>

using namespace std;



class User{

private:
	string name;
	vector <string> interests;
	string local;

public:
	User();
	User(string name, string local, vector <string> interests);
	vector<string> getInterests();
	string getLocal();

};

