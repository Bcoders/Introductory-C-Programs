
#include "RomanToDec.h"
#include<iostream>
#include<string>

using namespace std;

void RomanToDec::SetRoman(string & name) {   //input string passed as a reference 												 
	roman = name;				              //a variable is  created that points to the storage      
	n = roman.length();
}
void RomanToDec::SetDec() {
	
	for (int i = 0; i< n; i++) {                       //sets the element in decimal array according element in roman string.
		if (roman[i] == 'M') dec[i] = 1000;
		else if (roman[i] == 'D') dec[i] = 500;
		else if (roman[i] == 'C') dec[i] = 100;
		else if (roman[i] == 'L') dec[i] = 50;
		else if (roman[i] == 'X') dec[i] = 10;
		else if (roman[i] == 'V') dec[i] = 5;
		else if (roman[i] == 'I') dec[i] = 1;
	}
}

void RomanToDec::sumOfDec() {
	int add = dec[n - 1]; //begins to sum from the end. 	
	for (int i = n - 1; i > 0;i--) {
		if (dec[i - 1] >= dec[i]) { add = add + dec[i - 1]; }//if the second last is smaller than last, it subtracts from the last or else adds. 
		else { add = add - dec[i - 1]; }
	}
	sum = add;
	
}
	

int RomanToDec::getDec() const{  //returns the sum i.e decimal value
	return sum;
	
}

string RomanToDec::getRoman() const { //returns the roman numeral
	return roman;
}