// Alisikander Ahmed
// A C++ program to implement the matrix operations using a Class and Constructors. The operations supported are:

/*a) Reading a matrix.
b) Addition of matrices.
c) Printing a matrix.
d) Subtraction of matrices.*/

#include <iostream>
#include<tuple>
using namespace std;


class Matrix{
  public:
    int** inputMatrix;
    int rows, columns;
    bool loaded;

    //Declerations
    Matrix();
    Matrix (const int, const int);
    void printMatrix(int row, int col);
    void readMatrix(int row, int columns);
    Matrix* readMatrix2();
};

Matrix* addMatrix(Matrix m1, Matrix m2);

Matrix::Matrix(const int x, const int y){ //Constructors for making a matrix of a given size
  inputMatrix = new int *[x];
  rows=x;
  columns=y;
  for (int i = 0; i < x; i++)
      inputMatrix[i] = new int[y];
}

Matrix::Matrix(){ //Defualt Constructors, Ask for size and make a new array;
  cout << "Please input the size for this matrix: ";
  scanf("%d", &rows);  //Take rows as input form user
  columns = rows;
  loaded = false;
  inputMatrix = new int *[rows];
  for (int i = 0; i < rows; i++)
      inputMatrix[i] = new int[columns];
}

void Matrix::readMatrix(int row, int columns){  //Matrix Read Function, loads matrix with a random number for simplicity
  loaded = true;
  for (int i = 0; i < row; i++)
    for (int j = 0; j < columns; j++)
      inputMatrix[i][j] = rand() % 100;
}

void Matrix::printMatrix(int row, int col){ //Matrix Print Function
  cout << endl;
  for(int i=0; i<row; i++){ //Loop the Matrix
    for(int j=0; j<col; j++)
      printf ("%8d ", inputMatrix[i][j]); //Print value, right justified
    cout << endl;
  }
  cout << endl;
}

Matrix* addMatrix(Matrix* m1, Matrix* m2){  //Matrix Add Function
    Matrix *m = new Matrix(m1->rows,m1->columns); //Make new Matrix to return with the added values
   for (int i = 0; i < m1->rows; i++) //Loop rows
     for (int j = 0; j < m1->columns; j++)  //Loop columns
        m->inputMatrix[i][j] = (m1->inputMatrix[i][j] + m2->inputMatrix[i][j]); //Add values
    return m;
}

Matrix* subtratMatrix(Matrix* m1, Matrix* m2){  //Matrix Subtraction Function
    Matrix *m = new Matrix(m1->rows,m1->columns); //Make new Matrix to return with the subtracted values
   for (int i = 0; i < m1->rows; i++) //Loop rows
     for (int j = 0; j < m1->columns; j++)  //Loop columns
        m->inputMatrix[i][j] = (m1->inputMatrix[i][j] - m2->inputMatrix[i][j]); //Subtract values
    return m;
}

int main(){
  char input;
  Matrix *a;
  Matrix *b;
  Matrix *c;
  cout << endl;
  cout << "Hello and Welcome!\n\nMatrix Operations are as follows:\na) Reading a matrix.\nb) Addition of matrices.\nc) Printing a matrix.\nd) Subtraction of matrices.\n" << endl;
  cout << "Please choose an option now: ";

  while(input!='x'){
    cin >> input;
    switch(input){
      case 'a':
        cout << endl;
        a = new Matrix();
        a->readMatrix(a->rows, a->columns);
        b = new Matrix();
        b->readMatrix(b->rows, b->columns);
        cout << "Please choose another entry or enter 'x' to exit: ";
        break;
      case 'b':
        cout << endl;
        c = new Matrix(a->rows, a->columns);
        c = addMatrix(a, b);
        cout << "<----------Array A Added to Array B---------->";
        c->printMatrix(c->rows, c->columns);
        cout << "Please choose another entry or enter 'x' to exit: ";
        break;
      case 'c':
        cout << endl;
        cout << "<----------Array A---------->";
        a->printMatrix(a->rows, a->columns);
        cout << "<----------Array B---------->";
        b->printMatrix(b->rows, b->columns);
        cout << "Please choose another entry or enter 'x' to exit: ";
        break;
      case 'd':
        cout << endl;
        c = subtratMatrix(a, b);
        cout << "<----------Array A Subrtracted By Array B---------->";
        c->printMatrix(c->rows, c->columns);
        cout << "Please choose another entry or enter 'x' to exit: ";
        break;
      case 'x':
        cout  << "GoodBye! \n" <<endl;
        break;
      default:
        cout  << "Please Enter a Valid Entry!" <<endl;
        cout << "Please choose another entry or enter 'x' to exit: ";
    }
  }

  return 0;
}

//End Of Program
