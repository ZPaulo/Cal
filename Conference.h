#include <string>
#include <vector>

class Conference
{
private:
	std::string name;
	std::vector<std::string> text;
public:
	Conference();
	Conference(std::string name);
	~Conference();
};

