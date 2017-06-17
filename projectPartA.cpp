	/* 
	Author: <Yasmeen>
	Course: {135}
 	Instructor: <Gilbert Pajela>
	Assignment: <Project1>

	This program requests for the user to enter a sentence. Then
	that sentence is run through a series of is statements to
	detect the word count. After the word count is discovered
	the program checks which sentence rule is qualified in according to
	the word count. The words then run through bool functions to check 
	the file for an equal value, if no value is equal to the word
	the user input, it returns false. If the user input matches a word 
	it returns true. In the end if the word follows the grammar guidelines 
	and the word is present in the file, the program outputs a statement that
	the sentences are legala and by which rule.

   */
#include <iostream>
#include <string>
#include <fstream>
//#include <cstring>
using namespace std;

bool adjectives(string input)
{
	// create the ifstream object
	ifstream find;
	// open the file
	find.open("adjectives");
	// if file successfully opens
	// loop till we are able to read from file
	string adj;
	while(find >> adj)
	{
		// check if string matches the parameter "input"
		if (adj == input)
			return true; // true if match success
	}

	// if loop ends without match, false
	return false;
}

bool nouns(string input)
{
	ifstream fin;
	fin.open("nouns");
	string noun;
	while (fin >> noun)
	{
		if (noun == input)
			return true;
	}

	return false;
}

bool verbs(string input)
{
	ifstream fi;
	fi.open("verbs");

	string verb;
	while (fi >> verb)
	{
		if (verb == input)
			return true;
	}
	return false;
}
bool pronouns(string input)
{
	ifstream f;
	f.open("pronouns");

	string pronoun;
	while (f >> pronoun)
	{
		if (pronoun == input)
			return true;
	}
	return false;
}
bool grammarOne(string word1, string word2, string word3)
{
	//<sentence> ::= <noun><verb><noun>
	if (nouns(word1) && verbs(word2) && nouns(word3))
		return true;
	else
		return false;
}

bool grammarTwo(string word1, string word2, string word3, string word4)
{
	//<sentence> ::= <noun><verb><adjective><noun>
	if (nouns(word1) && verbs(word2) && adjectives(word3) && nouns(word4))
		return true;
	else
		return false;
}

bool grammarThree(string word1, string word2, string word3)
{
	//<sentence> ::= <pronoun><verb><noun>
	if(pronouns(word1) && verbs(word2) && nouns(word3))
		return true;
	else 
		return false;
}
bool grammarFour(string word1, string word2, string word3, string word4)
{
	//<sentence> ::= <pronoun><verb><adjective><noun> 
	if(pronouns(word1) && verbs(word2) && adjectives(word3) && nouns(word4))
		return true;
	else 
		return false;
}
bool grammarFive(string word1, string word2, string word3)
{
	//<sentence> ::= <pronoun><verb><pronoun>
	if(pronouns(word1) && verbs(word2) && pronouns(word3))
		return true;
	else 
		return false;
}
int main()
{
	//user unputs a sentence
	cout<<"Enter a sentence: "<<endl;
	char str[100];
	// getline(cin, yoda);
	cin.getline(str,100);

	int words = 0; // Holds number of words	
	for(int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ') //Checking for spaces
		{
			words++;
		} 		
	}
	words++;
	//extracting 3-4 words from str
	int i;
	string word1 = "";
	for (i = 0; str[i] != '\0' && str[i] != ' '; i++)// checks for space or null, runs if not
	{
		if (str[i] >= 'a' && str[i] <= 'z')// cheks that letter valuse is a-z 
			word1 += str[i];// stores char
		else
			word1 += str[i] + 32;//detected Caps so it adds 32 ti change ti l
	}
	string word2 = "";
	for (i = i+1; str[i] != '\0' && str[i] != ' '; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			word2 += str[i];
		else
			word2 += str[i] + 32;
	}
	string word3 = "";
	for (i=i+1; str[i] != '\0' && str[i] != ' '; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			word3 += str[i];
		else
			word3 += str[i] + 32;
	}
	string word4 = "";
	if (words > 3)
	{
		for (i=i+1; str[i] != '\0' && str[i] != ' '; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				word4 += str[i];
			else
				word4 += str[i] + 32;
		}
	}
	//cout<<word1<<word2<<word3<<word4;
	if (words == 3)
	{
		// check rules 1,3,5
		if (grammarOne(word1, word2, word3))
		{
			cout << "Your sentence is a legal sentence by rule 1." << endl;
		}
		else if (grammarThree(word1, word2, word3))
		{
			cout << "Your sentence is a legal sentence by rule 3." << endl;
		}
		else if (grammarFive(word1, word2, word3))
		{
			cout << "Your sentence is a legal sentence by rule 5." << endl;
		}
		else
		{
			cout << "Your sentence is not a legal sentence." << endl;
		}
	}
	else
	{
		// check rules 2,4
		if (grammarTwo(word1, word2, word3, word4))
		{
			cout << "Your sentence is a legal sentence by rule 2." << endl;
		}
		else if (grammarFour(word1, word2, word3, word4))
		{
			cout << "Your sentence is a legal sentence by rule 4." << endl;
		}
		else
		{
			cout << "Your sentence is not a legal sentence." << endl;
		}
	}

}
