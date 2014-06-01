#include <iostream>
#include "Database.h"
#include <conio.h>

using namespace std;

string convertToUpperCase (string Word){ //Function to do a case-insensitive search

	for (unsigned int i = 0; i < Word.size(); i++){
		Word[i] = toupper(Word[i]);
	}
	return Word;
}


bool KMP(string sentence, string match)
{
	string S = convertToUpperCase(sentence);//converte a string para maiúsculas
	string M = convertToUpperCase(match);

	vector<int> T(M.size() + 1, -1);
	bool foundMatch = false;

	if(M.size() == 0)//string está vazia, devove falso
	{
		return foundMatch;
	}

	for(unsigned int i = 1; i <= M.size(); i++)//pre-procesasmento do padrão
	{
		int pos = T[i-1];
		while(pos != -1 && M[pos] != M[i-1]) 
			pos = T[pos];
		T[i] = pos + 1;
	}

	int sp = 0;
	int kp = 0;

	while(sp < S.size())//processamento
	{
		while(kp != -1 && (kp == M.size() || M[kp] != S[sp])) 
			kp = T[kp];
		kp++;
		sp++;
		if(kp == M.size()) 
			foundMatch=true;
		if (sp-(M.size()+1) <= 0){
			if ((S[sp-(M.size()+1)] == ' ' || S[sp-(M.size()+1)] == '\0'))
			{
				if (foundMatch && (S[sp] < 'a' || S[sp] > 'z'))					
					return foundMatch;
				else
					foundMatch = false;
			}
			else
				foundMatch =false;
		}
		else{
			if (foundMatch && (S[sp] < 'a' || S[sp] > 'z'))				
				return foundMatch;
			else
				foundMatch = false;
		}
	}

	return foundMatch;
}


int main()
{
	Database db;

	db.initialize();
	db.matches();

	cout << "Press any key to exit\n";
	_getch();
	return 0;
}