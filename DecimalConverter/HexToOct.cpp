// Alisikander Ahmed
// Write a C++ Program to declare two classes Euro and CanadianDollar. Declare objects of both the classes. Convert euro to dollars and vice versa. Perform conversion using user-defined conversion functions and appropriate exception handling concepts.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int dectooct(long int decNum);
string hextooct(long int decNum);

int main(){

	/*Variable Declarations*/
	long int input; //Input as a string
	int inputSize;
	int i = 0;

	cout << "\nWelcome, Please enter how many number you will be entering today: ";
	cin >> inputSize;

	long int inputArray[inputSize];

	cout << "Please enter " << inputSize << " decimals (Base 10) that will be converted to Hexadecimal & Octal\nOnce "<< inputSize << " number(s) are entered input will exit!\n" << endl;

	for(i=1; i<=inputSize; i++){
		cin.clear();
    cin >> input;
    inputArray[i]=input;
  }

	//Call decimal to Hexadecimal function over the array.
	cout<<endl;
	for(i=1; i<=inputSize; i++)
		cout<<"Hexadecimal value of "<< inputArray[i] << " is : " << hextooct(inputArray[i]) << endl;

	//Call decimal to Octal function over the array.
	cout << "------------------------------------" << endl;
	for(i=1; i<=inputSize; i++)
		cout<<"Octal value of "<< inputArray[i] << " is : " << dectooct(inputArray[i]) << endl;
	cout<<endl;

	return 0;
}

/*Function for converting decimal to Octal and displaying result*/
int dectooct(long int decNum)
{
    int quot, i = 1, octalNum = 0;
    while (decNum != 0)
    {
        quot = decNum % 8;	//Get quotient by mod 8 decimal Value
        decNum /= 8;				//Divide decimal by 8 to get remainder
        octalNum += quot * i; //Multiple quotient by multiplier i to get octalNum
        i *= 10; //Multiple i by 10 each round to get apporiate position
    }
    return octalNum;
}

/*Function for converting decimal to Hexadecimal and displaying result*/
string hextooct(long int decNum)
{
    int quot, i = 1;
		string hexNum;
    while (decNum != 0)
    {
        quot = decNum % 16;	//Get quotient by mod 16 to the decimal value
				if(quot<10){
					quot+=48;				// Convert quotient using ascii if it is less than 10 by adding 48(0 in ascii)
				}
				else {
					quot+=55;				// Convert quotient into character using ascii by adding 55(7 in ascii) (*A in ascii starts at 65)
				}
				hexNum+=quot;
				decNum /= 16;				//Divide decimal by 16 to get remainder
		}
		reverse(hexNum.begin(), hexNum.end()); //Reverse hexNum as we are storing in the opposite order.
    return hexNum;
}
/*End of program*/
