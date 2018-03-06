// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          11/6/2017
// Assignment:    Lecture Homework 7 Exercise 2
// Compiler:      Visual C++ Community 2017

// Description: 
// This program reads numbers from a file, counts, and calculates
// an average of the valid numbers between 0 and 110 inclusive.
// Invalid numbers are counted and written to an ouput file.

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
   // declare variables
   int nextValue;
   double totalCount = 0;
   double sum = 0;
   double average = 0;
   int largestNum = -2;
   int secLargestNum = -1;
   int smallestNum = 1001;
   int secSmallestNum = 1001;

   // file stream objects
   ifstream inFS;

   // open file (if able)
   inFS.open("random.txt");

   // if file cannot be opened or does not exist
   if (!inFS.is_open())
      cout << "File \"random.txt\" could not be opened" << endl;

   // if file can be opened
   else {
      // read in values from file 
      while (inFS >> nextValue)
      {
         if (nextValue < secSmallestNum && nextValue > smallestNum)
            secSmallestNum = nextValue;
         if (nextValue < smallestNum)
            smallestNum = nextValue;
         if (nextValue > largestNum){
            secLargestNum = largestNum;
            largestNum = nextValue;
         }

         sum += nextValue;
         totalCount++;
      }

      // use this equation to calculate the average
      average = sum / totalCount;

      // display number of numbers, sum, average, largest, smallest, second largest, and second smallest numbers
      cout << "Number of numbers:     " << setw(6) << totalCount << endl;
      cout << "Sum of numbers:        " << setw(6) << sum << endl;
      cout << fixed << setprecision(1);
      cout << "Average of numbers:    " << setw(6) << average << endl;
      cout << setprecision(0);
      cout << "Largest number:        " << setw(6) << largestNum << endl;
      cout << "Smallest number:       " << setw(6) << smallestNum << endl;
      cout << "Second largest number: " << setw(6) << secLargestNum << endl;
      cout << "Second smallest number:" << setw(6) << secSmallestNum << endl;

      // close the file
      inFS.close();
   }

   system("pause");
   return 0;
} // end function main