/* 
    Author: <Yasmeen>
    Course: {136}
    Instructor: <Gilbert Pajela>
    Assignment: <Project3>

    This program requests for the user to enter a sentence. 

   */
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Word{
    //Class word, saves the string for a word    
    string word;
public:
    //constructors, run automatically
    Word(){
        
    }
    //stores string in word
    Word(string s){
        word = s;
    }
    //prints word
    string getWord(){
        return word;
    }
    
};

class WordType{
    /*
        common class that nouns, pronouns and others will inherit from
        overloads the  >> operator to read words from a file and save them in a vector
        
    */
protected:
    vector<string> list;
public:
    friend istream & operator >> (istream &in, WordType &c)
    {
        string s;
        while(in >> s)
        {   
            //insert the word in the list of words
            c.list.push_back(s);
        }
        return in;
    }
};


// following are classes derived from word types, with a boolean function in each of them
// that tells if a given word is in the list or not
class Nouns : public WordType{
public:
    bool isNoun(Word w){
        for(int i=0;i<list.size();i++){
            if(w.getWord() == list[i]){
                // word found so return true
                return true;
            }  
        //word not found, return false
        }
        return false;
    }
};


class Verbs : public WordType{
public:
    bool isVerb(Word w){
        for(int i=0;i<list.size();i++){
            if(w.getWord() == list[i]){
                return true;
            }
        }
        return false;
    }
};

class Adjectives : public WordType{
public:
    bool isAdjective(Word w){
        for(int i=0;i<list.size();i++){
            if(w.getWord() == list[i]){
                return true;
            }
        }
        return false;
    }
};

class Pronouns : public WordType{
public:
    bool isPronoun(Word w){
        for(int i=0;i<list.size();i++){
            if(w.getWord() == list[i]){
                return true;
            }
        }
        return false;
    }
};

class Sentence{
    /*
        stors a vector of words
        overloads the >> operators, that asks the user for a sentence, splits the sentence into words and saves them 
    in a vector
    */
    vector<Word> words;
public:
    friend istream & operator >> (istream &in, Sentence &c)
    {
        cout << "Enter your sentence "<<endl;
        string str;
        //input the string
        getline(in,str);
        
        //used for the substr function
        int wordStart = 0;
        
        for(int i=0; i<str.length(); i++){
            if(str[i] == ' '){
                //found a space
                //so current word goes from wordStart to i-1
                int wordLength = (i) - wordStart;
                if(wordLength > 0){
                    //create word using substr function
                    Word w(str.substr(wordStart, i - wordStart));
                    c.words.push_back(w);
                }
                wordStart = i+1;
            }
        }
        
        Word w(str.substr(wordStart, str.length() - wordStart ));
        c.words.push_back(w);
        return in;
    }
    
    void printWords(){
        for(int i=0;i<words.size();i++){
            cout<<words[i].getWord()<<endl;
        }
    }
    vector<Word> getWords(){
        return words;
    }
};

class GrammerChecker{

    Nouns nouns;
    Adjectives adjectives;
    Pronouns pronouns;
    Verbs verbs;
public:
    GrammerChecker(){
        ifstream fin;
        fin.open("nouns");
        fin>>nouns;
        fin.close();
        
        fin.open("verbs");
        fin>>verbs;
        fin.close();
    
        fin.open("adjectives");
        fin>>adjectives;
        fin.close();

        fin.open("pronouns");
        fin>>pronouns;
        fin.close();
    }
    
    int getGrammerRule(Sentence s){
        // if invalid sentence, we return -1
        int ruleMatched = -1;
        // get words from sentence
        vector<Word> words = s.getWords();
        
        
        // check for the grammer rules
        if (nouns.isNoun(words[0]) && verbs.isVerb(words[1]) && nouns.isNoun(words[2])){
            ruleMatched = 1;
        }else if (nouns.isNoun(words[0]) && verbs.isVerb(words[1]) && adjectives.isAdjective(words[2]) && nouns.isNoun(words[3])){
            ruleMatched = 2;
        }else if (pronouns.isPronoun(words[0]) && verbs.isVerb(words[1]) && nouns.isNoun(words[2])){
            ruleMatched = 3;
        }else if (pronouns.isPronoun(words[0]) && verbs.isVerb(words[1]) && adjectives.isAdjective(words[2]) && nouns.isNoun(words[3])){
            ruleMatched = 4;
        }else if (pronouns.isPronoun(words[0]) && verbs.isVerb(words[1]) && pronouns.isPronoun(words[2])){
            ruleMatched = 5;
        }
        
        return ruleMatched;
    }
};


int main()
{
    
    Sentence s;
    cin>>s;
    
    GrammerChecker gm;
    int rule = gm.getGrammerRule(s);
    
    if(rule > 0){
        cout << "Your sentence is a legal sentence by rule "<<rule<<"."<< endl;
    }else{
        cout << "Your sentence is not a legal sentence." << endl;
    }
    

}