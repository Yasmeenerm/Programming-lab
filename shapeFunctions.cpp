/*	Author: <Yasmeen>
    Course: {136}
    Instructor: Gilbert Pajela
    Assignment: <Input Validation,"Lab 6">
	
	Task0
	This program prompts the user to select a shape they'd like to make
	Choices being a rectangle, triangle, trapezoid and a triangle. This 
	accomplished by a series of function calls, the user must input the 
	corresponding key for a shape they want to create. If a user enters 
	an invalid answer, the program prompts indefinietly unless the user 
	quits the program ^C or selects E(xit)

	Task1
	testcase: if a user enters the an overflow value such as 32687900393,
	the program will print asteriks infinitely unless its force quit.
	Also if a non-numeric value is input such as 'a' the user is prompted 
	again to enter a valid value


    */
#include <iostream>
#include <string>
#include "main.h"
using namespace std;


void drawPixel(char c)
{
    cout<<c;
    return;
}
void Rectangle()
{
	int width,height;
	cout<<"\nInput the width of your rectangle"<<endl;
    cin>> width;//user input of width
	// if(!cin || (width< 0))
	// {
	// 	cout<< "invalid number\n"<<endl;
	// }
	while(width == false || width<0)
    {
    	cout<< "invalid input, try again\n"<<endl;
    	cin.clear();
    	cin.ignore();
    	cin>>width;
    	if(width == true)
    	{
    		return;
    	}
    }
	while(height == false)
    {
    	cout<< "invalid input, try again\n"<<endl;
    	cin.clear();
    	cin.ignore();
    	cin>>height;
    	if(height == true)
    	{
    		return;
    	}
    }
    cout<<"\nInput the height of your rectangle"<<endl;
    cin>>height;//user input of height
	if(!cin ||(height<0))
	{
		cout<<"Invalid number\n"<<endl;
	}
	while(height == false)
    {
    	cout<< "invalid entry, try again\n"<<endl;
    	cin.clear();
    	cin.ignore();
    	cin>>height;
    	if(height == true)
    	{
    		return;
    	}
    }
	int space;       
	int i;
    char random = 'Y';

    for(i=0;i<width;i++)
    {	//outputs first line without space, for the top border of the rectangle
       	drawPixel(random);
    }
    cout<<endl;

    space = width - 2;//space within the rectangle
    int j = 0;
    height=height-2;//takes into account the first and bottom lines printed with seperate for loops
	for(i=0;i<height;i++)
	{	// while i is less than the height, it outputs just once "*"
		drawPixel(random);
		for(j=0;j<space;j++)
		{	//this nested loop runs only when i<height, , then checks the condition j<space, if true it runs iif false, its skipped
        	cout<<" ";
		}
	   	drawPixel(random);
        cout<<endl;
    }
    for(i=0;i<width;i++)
    {
		drawPixel(random);
    }
    cout<<"\n";
    return;
}
void Triangle()
{
	int length;
   	cout<<"\nEnter the side length of your square, for the output of the lower triangle: "<<endl;
    cin>>length;
	if(!cin ||(length<0))
	{
        cout<<"invalid number\n"<<endl;
	} 
	while(length == false)
    {
    	cout<< "invalid entry, try again\n"<<endl;
    	cin.clear();
    	cin.ignore();
    	cin>>length;
    	if(length == true)
    	{
    		return;
    	} 
    } 
	cout<<endl;
    char random = '~';
    for (int a=0;a<=length;a++)
    {	//this for loop runs as long as a is less than the users input for length
    for(int b =0; b<a; b++)
    {	//in this nested loop runs as many times as the value of a, so if a =1 it runs once, if a = 4 it'll output 4 asteriks
        drawPixel(random);
    }
    cout<<endl;//ends a row
    }
    return;
}
void Trapezoid()
{
	int tHeight, tSide;//declares in variables

    cout<<"Enter the height of your trapezoid"<<endl;
    cin>>tHeight;//userinput for trapezoid height
    if(!cin ||(tHeight<0))
    {
		cout<<"invalid number\n"<<endl;
	} 
	while(tHeight == false)
    {
    	cout<< "invalid entry, try again\n"<<endl;
    	cin.clear();
    	cin.ignore();
    	cin>>tHeight;
    	if(tHeight == true)
    	{
    		return;
    	} 
    } 
	cout<<"Enter the length of your trapezoid"<<endl;
    cin>>tSide;//userinput for side length
   	if(!cin ||(tSide<0))
	{
        cout<<"invalid number\n"<<endl;
	}
	while(tSide == false)
    {
   	cout<< "invalid entry, try again\n"<<endl;
   	cin.clear();
    cin.ignore();
    cin>>tSide;
    	if(tSide == true)
    	{
    		return;
    	}
    }
    char random ='#';	
    for(int e=tHeight; e>0; e--)
    {//this loop decrements the height until its less than 0        
    	for(int d=tSide-e; d>=0; d--)
    	{//this nested loop stores side into d after subtracting height from the side, it decrements until d>0 is false
            drawPixel(random);
        }
        cout<<endl;
    }
    return;

}
void Circle()
{
	float r;
    float radius;// radius var
    cout<<"Enter the Radius?"<<endl;
    cin>> r;//userinput stored in this variable
  	if(!cin ||(r<0))
  	{
        cout<<"invalid number\n"<<endl;
	}
	while(r == false)
    {
    	cout<< "invalid entry, try again\n"<<endl;
    	cin.clear();
    	cin.ignore();
    	cin>>r;
    	if(r == true)
    	{
    		return;
    	} 
    } 
	float pr = 2; // pr is the aspected pixel ratio which is almost equal to 2
    char random = 'a';
	for(int i = -r; i <= r; i++)//y square < radius, vertical 
    {
    	for(int j = -r; j <= r; j++)
    	{	// x square is less than radius, horizontal
           	float lfc = ((2*i*i) + (j*j))/(r*r); // y^2 + x^2 divided by r^2, 2 - pixel aspect ratio
            if(lfc >= 0 && lfc < 1.08)
            {	// aspect ratio , the larger the range, more stars will be printed						
                drawPixel(random);
            }
            else 
            {
            	cout<<" ";
			}
		}
    	cout << endl;
    }
    return;
}
int main ()
{	
	string choice;
	cout<<"\nWhat shape would you like to make?\n"<<
	"Select\nR : for a rectangle\n"
	<<"L : for lower side of a Triangle\n"
	<<"T : for a Trapezoid\n"
	<<"C : for a Circle\n"
	<<"E : to exit the program\n"<<endl;

	cin>>choice;
	while(choice != "R"|| choice != "L"||choice != "T"||choice != "C"|| choice != "E")
	{
		if (choice=="R")
		{
			Rectangle();
		}
		if (choice=="L")
		{
			Triangle();
		}
		if (choice=="T")
		{
			Trapezoid();
		}
		if (choice=="C")
		{
			Circle();
		}
		if (choice == "E")
		{
			return 0;
		}
		if (choice != "R" && choice != "L" && choice != "T" && choice != "C" && choice != "E")
		{
			cout<<"Invalid Entry\nYour options are : R(ectangle) L(triangle) T(rapezoid) C(ircle) E(xit)\n";
			cin>>choice;
		}
        else
        {
        	cout<<"Your options are : R(ectangle) L(triangle) T(rapezoid) C(ircle) E(xit)\n";
        	cin>>choice;
        }
	}
	
		// if (choice == )
}