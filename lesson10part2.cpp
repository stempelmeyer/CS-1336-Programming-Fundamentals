// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          11/14/2017
// Assignment:    Zybooks Lesson 10 Part 1
// Compiler:      Visual C++ Community 2017

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

// declare global constants
const int MAX_COLUMNS = 5;

// fuction prototypes
int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName);
double average(double values[][MAX_COLUMNS], int numberRows);
double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows);
double smallestValue(double values[][MAX_COLUMNS], int numberRows);

int main()
{
   // declare variables for input and output file streams, data values from the file, and arrays
   string inputFileName;
   const int MAX_ROWS = 20;
   double grades[MAX_ROWS][MAX_COLUMNS];
   int actualRows;
   double averageVal;
   double columnAvg;
   double smallestVal;

   // read in file name
   cin >> inputFileName;

   // function call and assign result of readFile to the number of actual rows
   actualRows = readFile(grades, MAX_ROWS, inputFileName);
   // end the program if the file cannot be read
   if (actualRows == -1)
      return 0;
   // if the function returns 0 (the file does not contain any or enough data)
   if (actualRows == 0)
      return 0;

   // display how many rows were read in by the array
   cout << "Processing " << actualRows << " rows, and 5 columns" << endl;

   // calculate the total average value and assign it to a variable
   averageVal = average(grades, actualRows);

   // display the average calculated by the average function
   cout << fixed << setprecision(2);
   cout << "Average for all values is " << averageVal << endl;

   // display an average value for each column by assigning the function call to a variable
   for (int i = 0; i < MAX_COLUMNS; i++) {
      columnAvg = columnAverage(grades, i, actualRows);
      cout << "Average for column " << i << " is " << columnAvg << endl;
   }

   // display the smallest value of each row by assigning the function call to a variable
   for (int i = 0; i < actualRows; i++) {
      smallestVal = smallestValue(grades, i);
      cout << "Smallest value for row " << i << " is " << smallestVal << endl;
   }

   return 0;
} // end function main

  // read input file and populate the array
int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName) {
   // declare input file and local variables 
   ifstream inFS;
   double number;
   int numRows = 0;
   int i = 0;
   int j = 0;

   // open file (if able)
   inFS.open(inputFileName);

   // if input file cannot be opened or does not exist, display error message and assign false to the result
   if (!inFS) {
      cout << "File \"" << inputFileName << "\" could not be opened" << endl;
      return -1;
   }

   // read in the values into an array
   for (i = 0; i < maxRows; i++) {
      for (j = 0; j < MAX_COLUMNS && inFS >> number; j++) {
         values[i][j] = number;
         numRows++;
      }
   }

   // if the input file does not contain data, numRows isn't incremented and should display this error message
   if (numRows == 0) {
      cout << "The input file \"" << inputFileName << "\" did not contain any data" << endl;
      return 0;
   }

   // close file
   inFS.close();

   // numRows will equal how many times the inner for loop reads in values divided by 5 (the number of columns)
   numRows = numRows / 5;

   return numRows;
} // end function read file

// this function calculates and returns an average of all values read into the array
double average(double values[][MAX_COLUMNS], int numberRows)
{
   // declare local variables
   double accumulator = 0;
   double totalNumValues;
   double result;

   // for loop used to add values into an accumulator (sum)
   for (int i = 0; i < numberRows; i++) {
      for (int j = 0; j < MAX_COLUMNS; j++)
      accumulator += values[i][j];
   }

   // this will divide the sum of the numbers by the number of numbers
   totalNumValues = (numberRows * MAX_COLUMNS);
   result = accumulator / totalNumValues;

   return result;
} // end function average

// this function calculates and returns an average for the specified column
double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows)
{
   // declare local variables
   double accumulator = 0;
   double result;

   // this for loop will only pay attention to the numbers in the column inputted through the argument in function call
   for (int j = 0; j < numberRows; j++) {
         accumulator += values[j][column];
   }

   // this equation calculates the average of the values
   result = accumulator / numberRows;

   return result;
} // end function columnAverage

// this function finds the smallest value in a specified row
double smallestValue(double values[][MAX_COLUMNS], int numberRows)
{
   // declare local variables
   double accumulator = 0;
   double result = 2000;

   // this for loop will determine the smallest number in each row by comparing theme to each other
   for (int i = 0; i < MAX_COLUMNS; i++) {
      if ((values[numberRows][i]) < result) 
         result = values[numberRows][i];
   }

   // the function returns the smallest number back to the point of call
   return result;
} // end function smallestValue