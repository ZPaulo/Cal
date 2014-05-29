
#include <vector>
#include "User.h"
#include "Conference.h"

class Database{

private:
	std::vector<User*> users;
	std::vector<Conference*> conferences;

public:
	Database();
	~Database();
	void initialize();
};