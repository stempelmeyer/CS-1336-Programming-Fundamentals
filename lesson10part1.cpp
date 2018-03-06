// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          11/12/2017
// Assignment:    Zybooks Lesson 10 Part 1
// Compiler:      Visual C++ Community 2017

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

// fuction prototypes
bool readIn(char arrays[], string studentFileName);
void display(char student[], char answers[]);

// declare input file
ifstream inFS;

int main()
{
   // declare variables for input and output file streams, data values from the file, and arrays
   string studentFileName;
   string answersFileName;
   const int NUM_ELEMENTS = 20;
   char student[NUM_ELEMENTS];
   char answers[NUM_ELEMENTS];

   // read in file name
   cin >> studentFileName;
   cin >> answersFileName;

   // function call and continue to function call if the files can be opened
   if (readIn(student, studentFileName) == true)
   {
      if (readIn(answers, answersFileName) == true)
         display(student, answers);
      else
         return 0;
   }
   else
      return 0;

   return 0;
} // end function main

// this function will attempt to open and read in the file and the file's input
bool readIn(char arrays[], string FileName)
{
   // declare and initialize result value to true
   bool result = true;

   // open file (if able)
   inFS.open(FileName);

   // if input file cannot be opened or does not exist, display error message and assign false to the result
   if (!inFS) {
      cout << "File \"" << FileName << "\" could not be opened" << endl;
      result = false;
   }

   // if input file can be opened, read in the values into a char array using a for loop
   else {
      for (int i = 0; i < 20; ++i) {
         inFS >> arrays[i];
      }
      // close file
      inFS.close();
   }

   return result;
} // end function readIn

// this function will display which and how many answers are incorrect by comparing arrays
void display(char student[], char answers[])
{
   int i = 0;
   int missed = 0;
   // this for loop will compare the arrays with each other for 20 times
   for (i = 0; i < 20; i++) {
      // if the arrays have unequal values, the program will display that it is incorrect and increase the amount missed
      if (student[i]!=answers[i]) {
         cout << "Question " << (i + 1) << " has incorrect answer ";
         cout << "\'" << student[i] << "\', the correct answer is \'";
         cout << answers[i] << "\'";
         cout << endl;
         missed++;
      }
   }
   // these if statements will output how many missed questions and if the student passed or failed
      cout << missed << " questions were missed" << endl;
      if (missed > 6)
         cout << "The student failed" << endl;
      if (missed <= 6)
         cout << "The student passed" << endl;

} // end function display