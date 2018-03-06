// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          10/21/2017
// Assignment:    Zybooks Lesson 7 Part 1
// Compiler:      Visual C++ Community 2017

// Description: 
// This program reads numbers from a file, counts, and calculates
// an average of the valid numbers between 0 and 110 inclusive.
// Invalid numbers are counted and written to an ouput file.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
   // declare variables
   int countValid = 0;
   int countInvalid = 0;
   int totalCount;
   double number;
   double totalValid = 0;
   double average;

   // file stream object and file name string
   ifstream inFS;
   ofstream invalidFile;
   string fileName;

   // read in file name
   cin >> fileName;

   // open files (if able)
   inFS.open(fileName);
   invalidFile.open("invalid-numbers.txt");

   // if file cannot be opened or does not exist
   if (!inFS.is_open())
      cout << "File \"" << fileName << "\" could not be opened" << endl;

   // if file can be opened
   else {
      // read in values from file 
      while (inFS >> number)
      {
         // if the values are valid, increase valid count and add numbers
         if ( number >= 0 && number <= 110)
         {
            totalValid += number;
            countValid++;
         }

         // if the values are invalid, increase invalid count and write out
         else
         {
            invalidFile << fixed << setprecision(2);
            invalidFile << number << endl;
            countInvalid++;
         }
      }

      // use equations to calculate the total numbers inputted and valid average
      totalCount = countInvalid + countValid;
      average = totalValid / countValid;

      // display total values, invalid values, valid values, and valid average
      cout << "Reading from file \"" << fileName << "\"" << endl;
      cout << "Total values: " << totalCount << endl;
      cout << "Invalid values: " << countInvalid << endl;
      cout << "Valid values: " << countValid << endl;
      // display average if possible
      if (countValid >= 2)
      {
         cout << fixed << setprecision(2);
         cout << "Average of valid values: " << average << endl;
      }
      else
         cout << "An average cannot be calculated" << endl;

         // close both files
         inFS.close();
         invalidFile.close();
      }

   return 0;
} // end function main