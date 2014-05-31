#include <iostream>
#include "Database.h"

using namespace std;

string convertToUpperCase (string Word){ //Function to do a case-insensitive search

	for (unsigned int i = 0; i < Word.size(); i++){
		Word[i] = toupper(Word[i]);
	}
	return Word;
}


bool KMP(string SWord, string KWord)
{
	string S = convertToUpperCase(SWord);
	string K = convertToUpperCase(KWord);

	vector<int> T(K.size() + 1, -1);
	bool foundMatch = false;

	if(K.size() == 0)
	{
		return foundMatch;
	}

	for(int i = 1; i <= K.size(); i++)
	{
		int pos = T[i - 1];
		while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
		T[i] = pos + 1;
	}

	int sp = 0;
	int kp = 0;

	while(sp < S.size())
	{
		while(kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
		kp++;
		sp++;
		if(kp == K.size()) foundMatch=true;
		if (sp-(K.size()+1) <= 0){
			if ((S[sp-(K.size()+1)] == ' ' || S[sp-(K.size()+1)] == '\0'))
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
	string keyWord = "Traffic";

	


	cout << "Found match: ";
	if (KMP(s, keyWord))
		cout << "true"<<endl;
	else
		cout << "false" <<endl ;

	system("pause");
	return 0;
}