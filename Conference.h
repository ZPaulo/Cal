#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Conference
{
private:
	std::string name;
	std::string text;
public:
	Conference();
	Conference(std::string name);
	string getText();
	string getName();
	~Conference();
};

