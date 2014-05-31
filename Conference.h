#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Conference
{
private:
	std::string name;
	std::string text;
public:
	Conference();
	Conference(std::string name);
	~Conference();
};

