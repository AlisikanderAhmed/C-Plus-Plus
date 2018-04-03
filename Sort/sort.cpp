// Alisikander Ahmed
// A cpp program to take unsorted array from user and use bubble sort and selection sort to sort the array.
// Also allow user to binarySearch.

#include <iostream>
#include <vector>

using namespace std;

//Declarations
int countArray(vector<int> v);
void swap(vector<int> xp, vector<int> yp);
int binarySearch(vector<int> arr, int left, int right, int x);
vector<int> bubbleSort(vector<int> *inputArr, int size);
vector<int> selectionSort(vector<int> *inputArr, int size);
void printArray(vector<int> arr);

int countArray(vector<int> v){  //A counter for get array size
  int count = 0;
  for (auto i: v){  //Loops all elements of v
    count++;
  }
  return count;
}

void swap(vector<int> a, vector<int> b) //A simple swap function to swap a with b
{
  vector<int> temp = a;
  a = b;
  b = temp;
}

vector<int> selectionSort(vector<int> inputArr, int size)
{
  int i, j, smallest;

  // Loop each element of unsorted array
  for (i = 0; i < size-1; i++)
  {
    // Find the smallest element in unsorted array
    smallest = i;
    for (j = i+1; j < size; j++)
      if (inputArr[j] < inputArr[smallest])//If smaller number is found, set as smallest
        smallest = j;

    // Swap the found smallest element with the first available index
    printArray(inputArr);
    swap(inputArr[smallest], inputArr[i]);
  }
  printArray(inputArr);

  return inputArr;
}

vector<int> bubbleSort(vector<int> inputArr, int size)
{
  int i, j;
  for (i = 0; i < size-1; i++)  //Loop All Elements
  for (j = 0; j < size-i-1; j++){ //Loop All Elements again from the current index
    if (inputArr[j] > inputArr[j+1]){ //If value is bigger swap the values
      printArray(inputArr);
      swap(inputArr[j], inputArr[j+1]);
    }
  }
  printArray(inputArr);
  return inputArr;
}

void printArray(vector<int> arr){ //Simple print array function
  printf("%7c ", ' ');
  for (auto i: arr) //Loop all of arr
    printf("%-5d ", i);
  cout << endl;
}

int binarySearch(vector<int> arr, int left, int right, int x)
{
  if (right >= left)
  {
    int middle = left + (right - left)/2;    //Get mid point

    // If the element is in the middle
    if (arr[middle] == x)
      return middle;

    // If element is smaller than the middle, then search left side of array
    if (arr[middle] > x)
      return binarySearch(arr, left, middle-1, x);

    // Else search right side of array
    return binarySearch(arr, middle+1, right, x);
  }

  // Return -1 if element is not found
  return -1;
}


int main(){
  int size, input, counter;

  cout << "\nHello and Weclome!\n\nPlease enter the size of the array your will be filling: ";
  cin >> size;
  vector<int> unsortedNumbers(size);  //Create an unsorted array of Size, size

  cout << "Please enter " << size << " numbers each seperated by a space now: ";
  for(int i=0; i<size; i++){  //Loop Size and get all inputs from user
    cin >> input;
    unsortedNumbers[i] = input;
  }

  vector<int> bsortedNumbers(unsortedNumbers.size()); //Create a selectionSort Array
  vector<int> ssortedNumbers(unsortedNumbers.size()); //Create a bubbleSort Array


  cout << "\nUsing BubbleSort to Sort Your Array!" << endl;
  cout << "*-----------------------------------*" << endl;
  bsortedNumbers = bubbleSort(unsortedNumbers,unsortedNumbers.size());
  cout << "*-----------------------------------*\n" << endl;
  cout << "Using SelectionSort to Sort Your Array!" << endl;
  cout << "*-----------------------------------*" << endl;
  ssortedNumbers = selectionSort(unsortedNumbers,unsortedNumbers.size());
  cout << "*-----------------------------------*\n" << endl;


  cout << "The total number of elements in the array is " << countArray(unsortedNumbers) << "." << endl;
  cout << "The minimum number in the array is " << bsortedNumbers[0] << "." << endl;
  cout << "The maximum number in the array is " << bsortedNumbers[bsortedNumbers.size()-1]  << "." << endl;

  cout << "\nPlease enter a number you would like to search: ";
  int searchNum = 0, result = 0;
  cin >> searchNum;

  result = binarySearch(bsortedNumbers, 0, bsortedNumbers.size()-1, searchNum);

  if(result==-1){
    cout << searchNum << " Not Found in Array!" << endl;
  }
  else {
    cout << searchNum << " is located at index, " << result << " in the bubbleSort Array. " << endl;
    result = binarySearch(ssortedNumbers, 0, ssortedNumbers.size()-1, searchNum);
    cout << searchNum << " is located at index, " << result << " in the selectionSort Array. " << endl;
  }

  cout << endl;
}

//End of Program
