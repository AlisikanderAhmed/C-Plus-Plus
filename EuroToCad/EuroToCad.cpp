// Alisikander Ahmed
// A simple c++ program allowing users to convert currencies using two classes Euro and CanadianDollar. Users can make their own conversion function using given words.

#include <iostream>
#include <tuple>
#include <string>
#include <stdlib.h>

using namespace std;

class Euro{
  public:
    double converstionRate;
    Euro(){         //EURO dollar Constructor
      converstionRate = 0.632362;
    }
};

class CanadianDollar{
  public:
    double converstionRate;
    CanadianDollar(){       //CAD dollar Constructor
      converstionRate = 1.58160;
    }
};

int main(){
  cout << "\nHello, Welcome to Conversion Rate Calculator!\n" << endl;
  cout << "Please enter call a conversion function: \n(Please use words: Euro, European, Cad, Canadian) \n(Example Input: Euro to Cad 1.25)\n(Example Input 2: EuropeanToCad 1.25)\n" << endl;

  string input;
  string canadian="cad";
  string canadian2="canadian";
  string euro="euro";
  string lowerCaseInput = "";

  int cadIndex; //Index of CAD $
  int euroIndex; //Index of EURO $
  int digitIndex; //Index of Dollar Amount
  double amount;  //User enter amount
  double result; //Result after conversion

  getline(cin, input); //Get First Line of Input
  input.erase(0, input.find_first_not_of(' ')); //Error Handling, Remove Spaces before input
  input.erase(input.find_last_not_of(' ')+1);   //Error Handling, Remove Spaces after input

  for (int i=0; i<input.length(); i++){ //Convert to lower Case
    lowerCaseInput += tolower(input[i]);
  }
  for (int i=0; i<input.length(); i++) //Get Digit Index for getting the Amount
    if(isdigit(input[i])){
      digitIndex = i;
      break;
    }

  amount = atof((input.substr(digitIndex)).c_str());  //Substring to get the dollar amount
  cout << "\nYour amount entered is: $" << amount << endl;

  cadIndex = lowerCaseInput.find(canadian);    //Check if user entered CAD
  if(cadIndex==-1)                  //Else Check if they entered Canadian
    cadIndex = lowerCaseInput.find(canadian2);

  euroIndex = lowerCaseInput.find(euro);        //Check if user input has EURO

  if(cadIndex==-1 || euroIndex==-1)
    cout << "Please enter valid input! \nGoodbye!" << endl;

  Euro e;   //Make new euro object
  CanadianDollar c; //Make new cad object

  if(cadIndex>euroIndex){
    cout << "Euro converted to Canadian is: $" << amount*c.converstionRate << "\n\nGoodbye!\n" << endl;
  }

  else{
    cout << "Canadian converted to Euro is: €" << amount*e.converstionRate << "\n\nGoodbye\n" << endl;
  }

  return 0;
}
