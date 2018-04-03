//Alisikander Ahmed
// A C++ Program to receive from a user the Item Code, Quantity, and Price. Calculate the Amount and display the data in the following format:
// (A) Sr. No., Item Code and Quantity are left Justified. 
// (B) The Price and Amount is right Justified.
// (C) Three digits Precision for Amount field.

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main(){
  cout << "\nHello and Welcome to our Store! \n" <<endl;

  cout << "Please enter the following information, Item Code, Quantity, and Price (Example: \"0101 10 55.15\") type \"quit\" to end input stream: \n" <<endl;
  cout << "Example Input: \n  0101 10 55.15 \n  quit" << endl;

 cout << "\nPlease enter input now: " << endl;

  int srNo = 1; //Serial Number
  string input; //Input as a string
  cin >> input; // Takes input with cin
  string array[3]; //Array full of all user entries
  int i = 0;
  while (input != "quit"){ //Loop inputs until user quits, this will add every string the user inputs into the array
    array[i]=input;
    i++;
    cin.clear();
    cin >> input;
  }
  cout << endl;
  cout << endl;

  cout << setw(20) << "Sr. No." << setw(15) << "Item Code" << setw(15) <<  "Quantity" << setw(13) <<  "Price" << setw(15) <<  "Amount" << endl;
  cout << setw(20) <<  "=======" << setw(15) << "=========" << setw(15) <<  "========" << setw(15) <<  "=======" << setw(15) <<  "========" << endl;

  double amount;
  double quantity;
  string word;

  for (int count = 0; count<sizeof(array)/sizeof(*array); count++){ // Loop over the user input array and parse at every position using mod to get the Name, Age and DOB
    if(count == 0){ // Print item code and sr No.
      printf ("%12s %02d", "", srNo);
      cout << setw(15) << array[count];
      srNo++;
    }
    if(count == 1){ // Print Quantity
      cout << setw(14) << array[count];
      word = array[count];
      quantity = atof(word.c_str()); //change input to double
      continue;
    }
    if(count == 2){ // Print amount using setprecision 3
      cout << setw(21) << array[count];
      word = array[count];
      amount = atof(word.c_str()); //change user input into double
      cout << fixed << showpoint;
      cout << setprecision(3);
      cout << setw(15) << amount*quantity << endl;
      continue;
    }
    amount=0;
    quantity=0;
    word="";
  }


  cout << endl;

  return 0; // End of Program
}
