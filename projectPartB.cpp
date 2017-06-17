/* 
	Author: <Yasmeen>
	Course: {135}
 	Instructor: <Gilbert Pajela>
	Assignment: <Project1>

	This program opens a file called "engsents" and it ouputs the elbonian
	version of the sentence into a new file that it creates called "engsents"
	if the sentence is illegal it outputs illegal in the new "engsents" file

   */
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
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
	return true;
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
	//cout<<"G1"<<endl;
	//<sentence> ::= <noun><verb><noun>
	if (nouns(word1) && verbs(word2) && nouns(word3))// calls all three functions to validate each word
		return true;
	else
		return false;
}
bool grammarTwo(string word1, string word2, string word3, string word4)
{
	//cout<<"G2"<<endl;
	//<sentence> ::= <noun><verb><adjective><noun>
	if (nouns(word1) && verbs(word2) && adjectives(word3) && nouns(word4))
		return true;
	else
		return false;
}
bool grammarThree(string word1, string word2, string word3)
{
	//cout<<"G3"<<endl;
	//<sentence> ::= <pronoun><verb><noun>
	if(pronouns(word1) && verbs(word2) && nouns(word3))
		return true;
	else 
		return false;
}
bool grammarFour(string word1, string word2, string word3, string word4)
{
	//cout<<"G4"<<endl;
	//<sentence> ::= <pronoun><verb><adjective><noun> 
	if(pronouns(word1) && verbs(word2) && adjectives(word3) && nouns(word4))
		return true;
	else 
		return false;
}
bool grammarFive(string word1, string word2, string word3)
{
	//cout<<"G5"<<endl;
	//<sentence> ::= <pronoun><verb><pronoun>
	if(pronouns(word1) && verbs(word2) && pronouns(word3))
		return true;
	else 
		return false;
}
int main()
{
	string str;
	ifstream f; //Input file: Opens the file engsents which contains all the english sentences
	ofstream out("elbsents"); //Output file: For translating the english file into the elbonian language
	// open the file
	f.open("engsents"); 
	while(getline(f,str)){ //For reading each sentence line by line
		//cout<<str<<endl; //Print the english sentence (check)
		//Code which breaks the sentence down into letters
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
		string w1= "";
		for (i = 0; str[i] != '\0' && str[i] != ' '; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				word1 += str[i];
			else
				word1 += str[i] + 32;
				w1+= str[i];
		}
		string word2 = "";
		string w2 = "";
		for (i = i+1; str[i] != '\0' && str[i] != ' '; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				word2 += str[i];
			else
				word2 += str[i] + 32;
				w2+= str[i];
		}
		string word3 = "";
		string w3= "";
		for (i=i+1; str[i] != '\0' && str[i] != ' '; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				word3 += str[i];
			else
				word3 += str[i] + 32;
				w3+= str[i];
		}
		string word4 = "";
		string w4 = "";
		if (words > 3)
		{
			for (i=i+1; str[i] != '\0' && str[i] != ' '; i++)//checks if the char is null or a space
			{
				if (str[i] >= 'a' && str[i] <= 'z')//checks for caps
					word4 += str[i];//no caps so it stores the letter
				else
					word4 += str[i] + 32;//caps detected so its changed to the lower case by adding 32
					w4+= str[i];// additional stored word to preserve cases
			}
		}
		//cout<<word1<<word2<<word3<<word4;
		string final = ""; //The string which you'll be writing into the new file
		if (words == 3)
		{
			// check rules 1,3,5
			if (grammarOne(word1, word2, word3))
			{
				//cout << "Your sentence is a legal sentence by rule 1." << endl;
				final = w2 + " " + w1 + " " + w3; //Elbonian sentence
				//cout<<word2<<word1<<word3<<endl;
			}
			else if (grammarThree(word1, word2, word3))
			{
				//cout << "Your sentence is a legal sentence by rule 3." << endl;
				final = w2 + " " + w1 + " " + w3; //Elbonian sentence
				//cout<<word2<<word1<<word3<<endl;
			}
			else if (grammarFive(word1, word2, word3))
			{
				//cout << "Your sentence is a legal sentence by rule 5." << endl;
				final = w2 + " " + w1 + " " + w3; //Elbonian sentence
				//cout<<word2<<word1<<word3<<endl;
			}
			else
			{
				final = "Your sentence is not a legal sentence.";
				//cout << "Your sentence is not a legal sentence." << endl;
			}
		}
		else
		{
			// check rules 2,4
			if (grammarTwo(word1, word2, word3, word4))
			{
				string t=word3.substr(1);//takes the substring leaving the first character
				final = w2 + " " + w1 + " " + w3[0] + w4 + t; //Elbonian sentence
				//cout << "Your sentence is a legal sentence by rule 2." << endl;
			}
			else if (grammarFour(word1, word2, word3, word4))
			{
				string t=word3.substr(1);// stores modified noun
				final = w2 + " " + w1 + " " + w3[0] + w4 + t; //Elbonian sentence
				//cout<<word2<<word1<<word3[0]<<word4<<t<<endl;
				//cout << "Your sentence is a legal sentence by rule 4." << endl;
			}
			else
			{
				final = "Your sentence is not a legal sentence."; 
				//cout << "Your sentence is not a legal sentence." << endl;
			}
		}
		//cout<<final<<endl; //Print the final elbonian sentence (check)
		out<<final<<endl; //Write the sentence into the output
	}
}