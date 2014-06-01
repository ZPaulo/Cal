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
	Conference(std::string name);//reads a conference from a txt file
	string getText();//returns the text
	string getName();//returns the name
	~Conference();
};

