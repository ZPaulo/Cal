
#include <vector>
#include "User.h"
#include "Conference.h"

class Database{

private:
	std::vector<User> users;
	std::vector<Conference> conferences;

public:
	Database();
	~Database();
	void initialize();//cria os dados da classe
	void matches();//verifica a percentagem de interesses de cada utilizador que estão em cada conferência

	friend bool KMP(string SWord, string KWord);
};