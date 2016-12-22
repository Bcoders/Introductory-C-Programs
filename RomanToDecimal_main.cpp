/* ConsoleApplication4.cpp
Binamrata Sharma
Homework Assignment Number 1
Program that converts roman numeral to decimal numbers.
*/


#include "RomanToDec.h"
#include<iostream>
#include<string>

using namespace std;
int main()
{
	int ans;
	RomanToDec Rome;
	string roman;

	//Get the roman numeral from user and set the numeral 
	std::cout << "Enter the Roman numerals:"; 
	cin >> roman;
	Rome.SetRoman(roman);    

	//Convert the roman numeral into decimal value by first setting an array of the decimal value and summing them up
	Rome.SetDec();
	Rome.sumOfDec();
	
	//Output based on users reply
	cout << "Do you want the roman value and dec value?"<< endl;
	cout << "Type '0' if you want both, '1' if just roman numeral  and '2' if just dec:" << endl;
	cin >> ans;
	//to get both roman numeral and decimal value
	if (ans == 0) {
		cout << "Hey;";
		cout << "The decimal value of the numeral is:" << Rome.getDec() << endl;
		cout << "The roman numeric value of the numeral is: " << Rome.getRoman() << endl;
	}
	//to get roman numeral value
	else if (ans == 1) {
		cout << "The roman numeric value of the numeral is: " << Rome.getRoman() << endl;
	}
	//to get decimal numeral value
	else if (ans == 2) {
		cout << "The decimal value of the numeral is: " << Rome.getDec() << endl;
	}

	else { cout << "You entered a wrong value. So, as a punishment restart the program."; }

	return 0;
}

