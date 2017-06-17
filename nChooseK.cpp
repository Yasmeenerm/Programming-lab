/* Author: <Yasmeen>
   Course: {135,136}
   Instructor: <Gilbert Pajela>
   Assignment: <Numbers, "Lab 4">

	This program calculates the solution of n choose k. This program runs in for different
	computational ways, each resulting in the same value. Each part of the program required a 
	forloop

   Task 1
   This program uses 3 for loops to find the factorial value of, n!, k! and n-k!.
   It then uses those values to plug in to the equation of n!/k!*(n-k)!
   When n= 13, C(n,n-1) is incorrect

   Task 2
   This part of the program uses one loop to find the factorial value of n, by 
   multiplying (n-1)(n-2)...(n-i) until i=n-1.
   This program is more efficient than program 1 because it's only multiplying
   k many times. Where as in task 1 there's multiple for loops 

   Task 3
   This part of the program uses C(n,n-k) to prove that it derives the same answer as 
   C(n,k). At 13 choose 12, the value returned is incorrect.

   Task 4
   This program finds the value of n choose k by a different formula with only
   one value being changed

*/
#include <iostream>
using namespace std;
int main(){

	//Task 1
	int n,k;
	cout<<"\nEnter a value for n: ";
	cin>>n;
	cout<<"Enter a value for k: ";
	cin>>k;
	int a= n-k;
	int factorialn=1;
	int factorialk=1;
	for(int i=1; i<=n; i++){//factorial of n
		factorialn=i*factorialn;
	}
	cout<<"\nThe Factorial of "<<n<<"! =  "<<factorialn<<endl;
	for(int j=1; j<=k; j++){//factorial of k
		factorialk*=j;
	}
	cout<<"The Factorial of "<<k<<"! = "<<factorialk<<endl;
	int factorialnk=1;
	for(int g=1;g<=a;g++){//calculates n-k!
		factorialnk*=g;
	}
	int solution,b;
	b=factorialk*factorialnk;//calculates denominator value of equation k!(n-k)!
	solution=factorialn/b;// divides n! by the value of  k!(n-k)! stored in b
	cout<<"\nThe solution is : "<<solution<<endl;
	//Task 2
	cout<<"Enter a value for n: ";
	cin>>n;
	cout<<"Enter a value for k: ";
	cin>>k;
	factorialn =1;
	factorialk =1;
	for(int i=1; i<=n; i++){//factorial of n
		factorialn=i*factorialn;
	}
	cout<<"\nThe Factorial of "<<n<<"! =  "<<factorialn<<endl;
	for(int j=1; j<=k; j++){//factorial of k
		factorialk*=j;
	}
	cout<<"The Factorial of "<<k<<"! = "<<factorialk<<endl;
	int s=1;
	for(int i=1;i<=k;i++){//this loop runs k amount of times
		s*=n-i;//factorial of n-k, stored in s
	}
	cout<<"s= "<<s;
	s=s/factorialk;// this line is the value of n-k divided by k factorial
	
	int s=1;
	for(int i=0;i<k;i++){//this loop runs n amount of times
		s*=n-i;//factorial of n-k, stored in s
	}
	s=s/factorialk;
	cout<<"\nThe value of "<<n<<" choose "<<k<<" is: "<<s<<endl;
	//Task 3
	s=1;
	factorialnk =1;
	factorialn =1, factorialk=1;
	cout<<"Enter a value for n: ";
	cin>>n;
	cout<<"Enter a value for k: ";
	cin>>k;
	s=n-k;// storing the difference of n-k
	int val=1;//variable for end value
	for(int i=1; i<=s; i++){//factorial of n-k
		factorialnk=i*factorialnk;
	}
	for(int i=1; i<=n; i++){//factorial of n
		factorialn=i*factorialn;
	}
	cout<<"\nThe Factorial of "<<n<<"! =  "<<factorialn<<endl;
	for(int j=1; j<=k; j++){//factorial of k
		factorialk*=j;
	}
	cout<<"The Factorial of "<<k<<"! = "<<factorialk<<endl;

	for(int i=1; i<=s; i++){// value of n-k factorial
		val*=i;
	}
	val=val*factorialk;
	val=factorialn/val;
	cout<<"The value of "<<n<<"choose "<<n-k<<" is: "<<val<<endl;
	//Task 4
	cout<<"Enter a value for n"<<endl;
	cin>>n;
	cout<<"Enter a value for k"<<endl;
	cin>>k;
    double value;
    double product = 1.0;
    double constant = n-k;
    for(int i=1; i<=k; i++){// for loop runs k many times
     	value = (double)(constant/i);//typecasts the value to a double
        value++;//n+1
        product*=value;   
    }
	cout<<"\nThe product is: "<<product<<endl; 
}
	



