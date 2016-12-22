

#include<iostream>
#include<string>

using namespace std;

class RomanToDec
{
public:
	
	void SetRoman(string &name);
	void SetDec();
	void sumOfDec();
	int getDec() const;
	string getRoman() const;

private:
	int n;    //used for the size of roman numeral
	int sum;   //the decimal value
	string roman;  //to store roman numerals
	int *dec = new int; //to store decimal equivalence of each roman numeral
	 

};

