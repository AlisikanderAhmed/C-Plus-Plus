// Alisikander Ahmed
// Write a C++ program to implement the matrix operations using a Class and Constructors. The operations supported are: (5)

/*a) Reading a matrix.
b) Addition of matrices.
c) Printing a matrix.
d) Subtraction of matrices.
e) Multiplication of matrices.*/

#include <iostream>
#include<tuple>
using namespace std;


class Matrix{
  public:
    int** inputMatrix;
    int rows, columns;
    Matrix();
    Matrix (const int, const int);
    void printMatrix(int row, int col);
    void readMatrix(int row, int columns);
    Matrix* readMatrix2();
};

Matrix* addMatrix(Matrix m1, Matrix m2);

Matrix::Matrix(const int x, const int y){
  inputMatrix = new int *[x];
  rows=x;
  columns=y;
  for (int i = 0; i < x; i++)
      inputMatrix[i] = new int[y];
}

Matrix::Matrix(){
  cout << "Please input number of rows for this matrix: " << endl;
  scanf("%d", &rows);  //Take rows as input form user
  cout << "Please input number of cols for this matrix: " << endl;
  scanf("%d", &columns);  //Take cols as input form user

  inputMatrix = new int *[rows];
  for (int i = 0; i < rows; i++)
      inputMatrix[i] = new int[columns];
}

void Matrix::readMatrix(int row, int columns){
  for (int i = 0; i < row; i++)
    for (int j = 0; j < columns; j++)
      inputMatrix[i][j] = rand() % 100;
}

void Matrix::printMatrix(int row, int col){
  cout << endl;
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++)
      printf ("%8d ", inputMatrix[i][j]);
    cout << endl;
  }
  cout << endl;
}

Matrix* addMatrix(Matrix* m1, Matrix* m2){
    Matrix *m = new Matrix(m1->rows,m1->columns);
   for (int i = 0; i < m1->rows; i++)
     for (int j = 0; j < m1->columns; j++)
        m->inputMatrix[i][j] = (m1->inputMatrix[i][j] + m2->inputMatrix[i][j]);
    return m;
}

Matrix* subtratMatrix(Matrix* m1, Matrix* m2){
    Matrix *m = new Matrix(m1->rows,m1->columns);
   for (int i = 0; i < m1->rows; i++)
     for (int j = 0; j < m1->columns; j++)
        m->inputMatrix[i][j] = (m1->inputMatrix[i][j] - m2->inputMatrix[i][j]);
    return m;
}

int main(){
  char input;
  Matrix *a;
  Matrix *b;

  cout << endl;
  cout << "Hello and Welcome!\n\nMatrix Operations are as follows:\na) Reading a matrix.\nb) Addition of matrices.\nc) Printing a matrix.\nd) Subtraction of matrices.\ne) Multiplication of matrices.\n" << endl;
  cout << endl;

  while(input!='x'){
    cin >> input;
    switch(input){
      case 'a':
        cout << "welcome " << input <<endl;
        break;
      case 'b':
        cout  << "welcome " << input <<endl;
        break;
      case 'c':
        cout  << "welcome " << input <<endl;
        break;
      case 'd':
        cout  << "welcome " << input <<endl;
        break;
      case 'e':
        cout  << "welcome " << input <<endl;
        break;
      case 'x':
        cout  << "GoodBye!" <<endl;
        break;
    }
  }

  // Matrix *a = new Matrix();
  // Matrix *b = new Matrix();
  // Matrix *c = new Matrix();
  //
  // a->readMatrix(5, 5);
  // b->readMatrix(5, 5);
  //
  // c = subtratMatrix(a, b);
  // a->printMatrix(5, 5);
  // b->printMatrix(5, 5);
  // c->printMatrix(5, 5);

  return 0;
}

//cout << endl;
//cout <<"**UNABLE TO ADD MATRICS OF DIFFERENT SIZES**"<< endl;
//cout << endl;

//printf ("%d ", m.inputMatrix[i][j]);
//inputMatrix[a][b] = rand() % 100;
