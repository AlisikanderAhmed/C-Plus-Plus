// Alisikander Ahmed
// Write a C++ Program to define three distinct classes. Define a friend function which’ll be friend of all three classes. Read and display the data for three classes using common functions and friend functions. (5)

#include<iostream>
using namespace std;

// Forward declaration
class A;
class B;
class C;
void add(A,B,C);

class A{  //First class
    private:
      int a;  //Private variable that will be used by our friend function
    public:
      void setA(int num); //Function to set Value for integer in class A
      friend void add(A,B,C); //Shared Friend Function to add all values in each class
};

class B{  //Second class
    private:
      int b;  //Private variable that will be used by our friend function
    public:
      void setB(int num); //Function to set Value for integer in class B
      friend void add(A,B,C); //Shared Friend Function to add all values in each class
};

class C{  //Third class
    private:
      int c;  //Private variable that will be used by our friend function
    public:
      void setC(int num); //Function to set Value for integer in class C
      friend void add(A,B,C); //Shared Friend Function to add all values in each class
};

// Function to use integers from all friends to add all three values
void add (A objA, B objB, C objC){
    cout << "Using friend function 'add()' which is a friend of all three classes: " << objA.a << "+" << objB.b << "+" << objC.c << " is " << (objA.a + objB.b + objC.c) << endl;
    cout << endl;
}

void A::setA(int num){  //Set A's value
  a=num;
}
void B::setB(int num){  //Set B's value
  b=num;
}
void C::setC(int num){  //Set C's value
  c=num;
}

int main(){
    //Create Objects
    A objectA;
    B objectB;
    C objectC;

    //Create inputs
    int inputA, inputB, inputC;

    //Get input from user
    cout << endl;
    cout << "Hello and Welcome!" << endl;
    cout << "Please input integer A: ";
    cin >> inputA;

    cout << "Please input integer B: ";
    cin >> inputB;

    cout << "Please input integer C: ";
    cin >> inputC;

    //Set all values to users input
    objectA.setA(inputA);
    objectB.setB(inputB);
    objectC.setC(inputC);

    //Add all values
    add(objectA, objectB, objectC);
    return 0;
}
