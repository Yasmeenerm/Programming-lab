   /*Author: <Yasmeen>
  	 Course: {136}
     Instructor: <Gilbert Pajela>
   	 Assignment: <Functions, "Lab 5">

	This program prompts the user to enter a any positive number. It then runs that value
	through a while loop to error check for invalid entries. If the value entered is
	valid the program then calls on the sum of digits function, and sums up the value of
	all digits, then checks its digit count and checks for the sum until the digit count is 
	one.
	This program then checks if that number input is divisible by 9, if not its adds 1 until 
	the number is divisivle byy 9
   */
#include <iostream>
using namespace std;

int transformNum(int n1);
// Precondition: num > 0
// Postcondition: the return number of digits in num
int numDigits(int num);


// Precondition: num > 0, index > 0
// Postcondition: return the index'th digit of num
int getDigit(int num, int index);

// Precondition: num > 0
// Postcondition: the return value is the iterated sum of digits of num
int sumOfDigits(int num);

// returns the number of digits in a num
int numDigits(int num) {
	int digitAmount = 0;
	if (num == 0) {
		return 1;
	}
	while (num != 0) {
		num = num / 10;
		digitAmount++;
	}
	return digitAmount;
}// end of the function.

// this function returns each digit in the num.
// return index'th digit of a num
int getDigit(int num, int index) {
	int digit;
	for (int i = 1; i <= index; i++) {
		digit = num % 10;
		num = num / 10;
	}
	return digit;
}// end of the function.

// This function returns the sum of the digits of the num
int sumOfDigits(int number) {
	int sum = 0;
	// call the function numDigits.
	int n = numDigits(number);
	for (int i = 1; i <= n; i++)
		// call the function getDigit.
		sum = sum + getDigit(number, i);
	return sum;
}// end of the function.

// This function transfers the number as divisble by 9.
int transformNum(int n1) {
	int rem = n1 % 9;
	int transfer_num = 9 - rem + n1;
	return transfer_num;
}// end of the function.

// main() function.
int main() {
	int num, index;
	// prompts the user to enter the number.
	cout << "Enter a positive number: " << endl;
	// read the number.
	cin >> num;
	//  check for the validation of the number.
	while ((num <= -1) || !cin) {
		cout << "Inavlid entry, Try again: ";
		cin >> num;
	}
	// call sumOfDigits(0 function to find the sum of the digits in the number.
	int sum_Digits = sumOfDigits(num);
	// display the sum.
	cout << "Sum of digits = " << sum_Digits << endl;
	// run the loop the digits of a number until it eventually
	// results in a single-digit number.
	if (numDigits(sum_Digits) != 1)
	{
		int y = sumOfDigits(sum_Digits);
		cout << "Sum of digits in next iteration= " << y << endl;
	}
	// check if the number is divisible by 9 or not.
	// if the sum of the digits in the num is divisible by 9 // then the number is divisible by 9.
	if (sum_Digits % 9 == 0) {
		cout << "The number is divisible by 9" << endl;
	}
	// if the number is not divisible by 9, then call the transformNum() function
	else if ((sum_Digits % 9 != 0)) {
		int Number_Transfer = transformNum(num);
		cout << " \nTransferred number: " << Number_Transfer <<endl;
	}
	return 0;
}// end of the main() function.
