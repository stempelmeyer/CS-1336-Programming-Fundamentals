// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          11/1/2017
// Assignment:    Lecture Homework 7 Exercise 1
// Compiler:      Visual C++ Community 2017

// Description: This program utilizes input validation loops to ask the user to
// input a value and outputs four patterns with heights equal to the number
// provided by the user

#include <iostream>

using namespace std;

int main()
{
   // declare variables
   int userValue;
   int space;
   int i;
   int j;

   // prompt the user to enter a valid value and read in
   cout << "Please enter an integer between 1 and 15: ";
   cin >> userValue;
   cout << endl;

   // input validation loop for invalid values and reads in a new value
   while (userValue < 1 || userValue > 15)
   {
      cout << "The value must be between 1 and 15" << endl;
      cout << "Please enter an integer between 1 and 15: ";
      cin >> userValue;
   }

   // this loop will print an inverted triangle lined up on the left side
   for (i = userValue; i >= 1; i--)
   { // the first for loop controls the number of rows
      for (j = 1; j <= i; j++) // the second for loop controls how many asterisks are displayed
         cout << "*";
      cout << endl;
   }
   cout << endl; // space between loops

   // this loop will print an inverted triangle lined up on the right side
   for (i = userValue; i >= 1; i--)
   { // the first for loop controls the number of rows
      for (space = 0; space < userValue - i; space++) // the second for loop controls the spaces
         cout << " ";
      for (j = 1; j <= i; j++) // the third loop controls how many asterisks are displayed
         cout << "*";
      cout << endl;
   }

   // this loop will print a triangle with a height of the user-entered value
   for (i = 0; i <= userValue; i++)
   { // the first for loop controls the number of rows
      for (space = userValue; space > i; space--) // the second for loop controls the spaces
         cout << " ";
      for (j = 1; j <= i * 2 - 1; j++) // the third loop controls how many asterisks are  printed
         cout << "*";
      cout << endl;
   }

   // this loop will print a hollow triangle with a height of the user-entered value
   for (i = 0; i <= userValue; i++)
   { // the first for loop controls the rows
      for (space = i; space < userValue; space++) // the second for loop controls the outer spaces
         cout << " ";
      for (j = 1; j <= i * 2 - 1; j++) { // the third for loop controls the asterisks and spaces within the triangle
         if (i == userValue || j == 1 || j == i * 2 - 1)
            cout << "*";
         else
            cout << " ";
      }
      cout << endl;
   }

   // prompt the user to enter a valid value and read in
   cout << "Please enter an odd integer between 1 and 15: ";
   cin >> userValue;
   cout << endl;

   // input validation loop for invalid values (odd or out of range) and reads in a new value
   while (userValue < 1 || userValue > 15 || userValue % 2 == 0)
   {
      cout << "The value must be an odd number between 1 and 15" << endl;
      cout << "Please enter an integer between 1 and 15: ";
      cin >> userValue;
   }



   // this is the first line of the hourglass bonus problem, printing out alternating stars and spaces
   for (i = 0; i < 2 * userValue; i++) {
      if (i % 2 == 0)
         cout << "*"; // this outputs the stars
      else
         cout << " "; // this outputs the spaces
   }
   cout << endl;

   // this controls the upper half of the hourglass, excluding the very top
   for (i = 2, j = 0; i < userValue; i += 2, j += 4) { // this loop controls the number of rows
      for (space = 0; space <= i - 1; space++) // this for loop controls the first set of spaces
         cout << " "; 
      cout << "*"; // this ouputs the star on the left side of the hourglass
      for (space = userValue - (7-userValue); space > j; space--) // this loop controls the spacing within the top part
         cout << " ";
      if (i != userValue - 1)
         cout << "*"; // this outputs the star on the right edge of the hourglass
      cout << endl; // this begins a new row
   }

   // this controls the lower half of the hourglass, excluding the middle and bottom
   for (i = userValue - 2, j = 2; i > 2; i -= 2, j+=4) { // this loop controls the number of rows
      for (space = i-2; space >= 0; space--) // this for loop controls the first set of spaces on the right
         cout << " ";
      cout << "*"; // this outputs a star on the left side of the hourglass
      for (space = 0; space <= j; space++) // this loop controls the spacing within the bottom part
         cout << " ";
      if (i != userValue - 1)
         cout << "*"; // this outputs the star on the right side of the hourglass
      cout << endl;
   }
   // this is the last line of the hourglass bonus problem
   for (i = 0; i < 2 * userValue; i++) {
      if (i % 2 == 0)
         cout << "*"; // this outputs the stars
      else
         cout << " "; // this outputs the spaces
   }
   cout << endl;

   system("pause");
   return 0;
} // end function main
