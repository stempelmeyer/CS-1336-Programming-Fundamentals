// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          11/30/2017
// Assignment:    Lecture Homework 9 Exercise 1
// Compiler:      Visual C++ Community 2017

// Description: 
// This program reads values from a file into a standard array and compares it
// with a set of values from another file read into another test array. It then 
// uses a function to compare the arrays and returns the index value for when/ if
// the test value is found within the standard array. 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstring>

using namespace std;

// function prototypes
/*********************************************************************************
* Function:      int searchList
* Description:   This function uses the arguments containing the standard array,
*                the number of elements in that array, the value being tested for,
*                and the pass by reference for the index value that the standard 
*                array is being compared with in the loop.
* Input:         standard array, number of elements in standard array, the test
*                value, and the number of elements tested so far in standard array
* Return:        returns an int for the index value where the value for the test  
*                array equals the value of the standard array.
**********************************************************************************/
int searchList(int stdList[], int numElems, int value, int &elemsTested);

int main()
{
   // declare variables for input file stream, maximum size declarators, and arrays
   ifstream inFS;
   const int STDARRAYSIZE = 100;
   const int TESTARRAYSIZE = 50;
   int standard[STDARRAYSIZE];
   int test[TESTARRAYSIZE];
   int standardCount = 0;
   int testCount = 0;
   int value;
   int indexValue;
   int elemsTested = 0;

   // open file for standard values
   inFS.open("LSStandard.txt");

   // if input file cannot be opened or does not exist, display error message
   if (!inFS) {
      cout << "File \"LSStandard.txt\" could not be opened" << endl;
      return 0;
   }

   // using a while loop, read in values to the array
   while (standardCount < STDARRAYSIZE && inFS >> standard[standardCount])
      standardCount++;
   
   // close the file
   inFS.close();

   // open file for test values
   inFS.open("LSTest.txt");

   // if input file cannot be opened or does not exist, display error message
   if (!inFS) {
      cout << "File \"LSTest.txt\" could not be opened" << endl;
      return 0;
   }

   // using a while loop, read in values to the array
   while (testCount < TESTARRAYSIZE && inFS >> test[testCount])
      testCount++;

   // close the file
   inFS.close();

   // this for loop will run through all the test values
   for (int i = 0; i < testCount; i++) {
      // initialize the element tested to 0 each time the loop runs through so that the values in the standard
      // array will be searched beginning at an index value of 0
      elemsTested = 0;
      // set the value being searched for equal to the value in the array
      value = test[i];
      // function call the search list to find if there is the testing value in the standard array
      indexValue = searchList(standard, standardCount, value, elemsTested);
      // if the testing value is not found, the function will return and assign indexValue to -1, display the message
      if (indexValue == -1)
         cout << "Number " << (i + 1) << "(" << setw(3) << test[i] << ") was not located in the file." << endl;
      // if the testing value is found, it will return a value not equal to -1, display the message
      else
      {
         cout << "Number " << (i + 1) << "(" << setw(3) << test[i] << ") was located at index(es) " << indexValue;
         // this for loop function calls searchList to search the rest of the array if there are any other index values
         // and displays them in a list if they are not equal to -1
         for (int j = 0; j < 50; j++) {
            elemsTested += 1;
            indexValue = searchList(standard, standardCount, value, elemsTested);
            if (indexValue != -1)
               cout << ", " << indexValue;
         }
         cout << "." << endl;
      }
   }

   system("pause");
   return 0;
} // end function main

  // this function will return the index position by which the test and standard arrays contain the same values
int searchList(int stdList[], int numElems, int value, int & elemsTested)
{
   // this for loop will compare the arrays with each other
   for (; elemsTested < numElems; elemsTested++) {
      // if the arrays have are equal, the function should return the index position
      if (stdList[elemsTested] == value) {
         return elemsTested;
      }
   }
   // the function should return -1 if no test values are found within the standard array
      return -1;
} // end function display