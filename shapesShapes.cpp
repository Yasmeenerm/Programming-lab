/*
        Author: <Yasmeen>
        Course: {135,136}
        Instructor: Gilbert Pajela
        Assignment: <Shapes,"Lab 3"

Task 1   This part of the program prompts the user to enter the height and
         width of a rectangle. The user input is stored and then output  
         through nested for loops. These for loops generate a rectangle
         specific to the users inputs using asteriks

Task 2  This part of the program prompts the user to enter the length of a square
        It then takes that input and outputs the length entirely, starting
        from the top line it out puts one *, then increments by one, until
        entire length is output, generating the bottom triangle of the square

Task 3  This part of the program prompts the user to input the height and side 
        measurements of the trapezoid generating the bottom half of any triangle

Task 4  This part of the program executes the same measuremnets of the previous
        square in task 2, and outputs the reflecting side of the square.

Task 5  This part of the program prompts the user to enter a radius, then generates
        a circle using the x^2+y^2=r^2\

*/

#include <iostream>
using namespace std;
int main (){
        int width, height;//variables to store rectangle parameters
        int space;//variable for the space in the rectangle
        int i;

        cout<<"\nInput the width of your rectangle"<<endl;
        cin>> width;//user input of width
		if(!cin || (width< 0)){
			cout<< "invalid number, stay positive!\n"<<endl;
		}

        cout<<"\nInput the height of your rectangle"<<endl;
        cin>>height;//user input of height
		if(!cin ||(height<0)){
			cout<<"invalid number, stay positive!\n"<<endl;
		}
        for(i=0;i<width;i++){//outputs first line without space, for the top border of the rectangle
       		 cout<<"*";
        }
        cout<<endl;

        space = width - 2;//space within the rectangle
        int j = 0;
        height=height-2;//takes into account the first and bottom lines printed with seperate for loops

		for(i=0;i<height;i++){// while i is less than the height, it outputs just once "*"
		  	cout<<"*";

        	for(j=0;j<space;j++){//this nested loop runs only when i<height, , then checks the condition j<space, if true it runs iif false, its skipped
            	cout<<" ";
				}
	    	 cout<<"*"<<endl;

        }

        for(i=0;i<width;i++){
			cout<<"*";
        }

		//Task 2
        int length;
        cout<<"\nEnter the side length of your square, for the output of the left half: "<<endl;
        cin>>length;
		if(!cin ||(length<0)){
            cout<<"invalid number, stay positive!\n"<<endl;
		 }   

		cout<<endl;
        for (int a=0;a<=length;a++){//this for loop runs as long as a is less than the users input for length

       		 for(int b =0; b<a; b++){//in this nested loop runs as many times as the value of a, so if a =1 it runs once, if a = 4 it'll output 4 asteriks
             	cout<<"*";
             }
             cout<<endl;//ends a row
        }


		//Task 3
		int tHeight, tSide;//declares in variables

        cout<<"Enter the height of your trapezoid"<<endl;
        cin>>tHeight;//userinput for trapezoid height
       	if(!cin ||(tHeight<0)){
	       cout<<"invalid number, stay positive!\n"<<endl;
		}   

		cout<<"Enter the length of your trapezoid"<<endl;
        cin>>tSide;//userinput for side length
		if(!cin ||(tSide<0)){
           cout<<"invalid number, stay positive!\n"<<endl;
		}   

        for(int e=tHeight; e>0; e--){//this loop decrements the height until its less than 0        
       		 for(int d=tSide-e; d>=0; d--){//this nested loop stores side into d after subtracting height from the side, it decrements until d>0 is false
            	 cout<<"*";
             }
             cout<<endl;
        }

		//Task 4

        cout<<"\n\n\nThis is the output of the opposite half of your square:\n \n"<<endl;
        int c= length;
        int b=0;
	
        for(c;c>0;c--){//runs loop until c<0
        	int a;
            a=length-c;
            for(a; a>0;a--){
           		 cout<<" ";
            }
            for(int b=0;b<c;b++){//each time this loop runs, one less "*" is printed
           		 cout<<"*";
			}
			cout<<endl;
        }
		cout<<endl;

		//Task 5

        float r;
        float radius;// radius var
        cout<<"Enter the Radius?"<<endl;
        cin>> r;//userinput stored in this variable
  		if(!cin ||(r<0)){
            cout<<"invalid number, stay positive!\n"<<endl;
		}   

		float pr = 2; // pr is the aspected pixel ratio which is almost equal to 2

        for(int i = -r; i <= r; i++)//y square < radius, vertical 
        {
            for(int j = -r; j <= r; j++){// x square is less than radius, horizontal
           		 float lfc = ((2*i*i) + (j*j))/(r*r); // y^2 + x^2 divided by r^2, 2 - pixel aspect ratio
                 if(lfc >= 0 && lfc < 1.08){// aspect ratio , the larger the range, more stars will be printed						
                	 cout<<"*";
                 }
                 else {
                	 cout<<" ";
				 }
			}
            cout << endl;
        }
 }
                                 

