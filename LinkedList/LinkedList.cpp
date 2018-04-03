// Alisikander Ahmed
// A CPP program to allow users to insert, delete and search linked lists.

#include<iostream>

using namespace std;

struct node{  //Creation of node structure to store each nodes, data as an integer and the next node as a node pointer
  int data;
  node *next;
};

class LinkdedList{ //Linkedlist Class
  private:
    node *head, *tail;  //Store head and tail of the linkedList as a pointer
  public:
    LinkdedList(){   //Default all values to NULL
      head=NULL;
      tail=NULL;
    }

    void insertnode(int value){
      node *temp=new node;  //New temp node
      temp->data=value; //Set new node to the user value
      temp->next=NULL;
      if(head==NULL){ //If list is empty set to head
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else{   //Link the new node to the tail
        tail->next=temp;
        tail=temp;
      }
    }

    void display(){ //Display Function
      node *temp=new node; //Set temp to the current head
      temp=head;
      cout << "<--------Linked List: ";
      while(temp!=NULL){  //Loop until NULL and print all data
        cout<<temp->data<<" ";
        temp=temp->next;
      }
      cout << "-------->" << endl;
    }

    void delete_last(){
      node *current=new node; // Make new current and previous nodes
      node *previous=new node;
      current=head;
      while(current->next!=NULL){ //Loop next node until not NULL
        previous=current;   //Set previous to current
        current=current->next;  //Set current to next
      }
      tail=previous;  //Set tail to previous
      previous->next=NULL; //Set next node to NULL
      delete current;
    }

    void search(int value){
      node *temp=new node;
      temp=head;  //Set temp to the current head
      bool found;
      int position = 0;

      while(temp!=NULL){    //Loop temp node
        if(value == temp->data){  //if Equal to value set found to true
          found=true;
          break;
        }
        temp=temp->next;
        position++; //Add index
      }

      if(found) //If found print index
        cout << value << " found at position " << position << "!" << endl;
      else
        cout << value << " not found in array!" <<endl;
    }

  };

int main(){
  LinkdedList list;
  list.insertnode(15);  //Load list
	list.insertnode(5);
	list.insertnode(9);
  int input;  //User input
  int value;  //Value variable
  cout << "\nHello and Welcome!\nPlease choose one of the following options or enter 'x' or any char to exit: " << endl;
  cout << "1. Insertion of a node into Linked List." << endl;
  cout << "2. Deletion of a node into Linked List." << endl;
  cout << "3. Search an element from the Linked List.\n" << endl;

  cout << "Your current linkedList is: ";
  list.display();

  cout << "Please choose an option now: ";
  while(cin >> input){  //Load all user input
    cout << endl;
    switch ((input)) {  //Switch stmt for each user input type
      case 1: //If 1 take list input
        cout << "Please enter the value you would like to insert: ";
        cin >> value;
        list.insertnode(value);
        cout << "The value " << value << " has been inputted into your linkedList! " <<endl;
        list.display();
        cout << "\nPlease choose another option or enter 'x' to exit: ";
        break;
      case 2: //If 2 delete last node
        cout << "Your current linkedList is: ";
        list.display();
        cout << "The node at the end of the linkedlist is now deleted!" << endl;
        list.delete_last();
        list.display();
        cout << "\nPlease choose another option or enter 'x' to exit: ";
        break;
      case 3: //If 3 search for a user value
        cout << "Please enter the element you would like to search now: ";
        cin >> value;
        list.search(value);
        list.display();
        cout << "\nPlease choose another option or enter 'x' to exit: ";
        break;
      default:  //Default for any other input
        cout << "Invalid Input...Try Again!" << endl;
    }
  }
  cout << "\nGoodbye!\n" << endl;
}

//End of Program
