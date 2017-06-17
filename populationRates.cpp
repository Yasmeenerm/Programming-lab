#include <iostream>
using namespace std;
int main(){

int p; //population
int n=0; //year
int m;// carrying capacity
int k;//user input of upto what yr
float h;//min loss rate
float g;//growth rate
float q;


cout<<"\n Enter a population value:\n";
cin>> p;
	if (!cin || (p< 0))
	{
		cout<< "invalid number, stay positive!\n";}

cout<<"\nEnter the carrying capacity:\n";
cin>>m;
	if(!cin || (m<0))
	{
		cout<<"invalid number, stay positive!\n";
	}
cout<< "\nEnter minimim loss rate:\n";
cin>>h;
	if(!cin || (h<0))
	{
		cout<<"invalid number, stay positive!\n";
}

cout<<"\nEnter growth rate:\n";
cin>>g;
	if(!cin || (g<0))
	{
		cout<<"invalid number, stay positive!\n";
	}

cout<< "\n\nUpto what year would you like to see population growth?\n";
cin>>k;

cout<<"Year \t Population\n";

        for(n=0;n<k;n++){//this for loop runs k times



//              float i = p(n);

                q = (1+g-h)*p - g*p*p/m;

                cout<<n<<"\t\t"<<q<<"\n";
                p=q;
                }
}

