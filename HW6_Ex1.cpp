// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          10/27/2017
// Assignment:    Lecture Homework #6 Exercise #1
// Compiler:      Visual C++ Community 2017

// Description: 
// This program demonstrates the different types of iteration
// loops

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   // declare variable, counter, and accumulator
   int i = 99;
   int count = 0;
   long long total = 0;
   int minutes = 0;
   double calories = 0;

   // program prints out even integers between 2 and 100 using
   // a for loop with an initialization, test, and update
   for (i = 2; i <= 100; i = i + 2)
   {
      // set width length to 5 right justified
      cout << setw(5) << i;
      // begin new line after printing out 10 integers
      if (i % 20 == 0) {
         cout << endl;
      }
      // increase the counter each time the loop occurs
      count++;
   }
   // display how many numbers are printed out using the counter
   cout << "Number of numbers = " << count << "." << endl << endl;

   // set counter back to 1 (re-initialize)
   count = 1;
   i = 99;
   // use while loop to print out integers that are multiples of 3 (99 to 3)
   while (i >= 3) {
      // set width length to 5 right justified
      cout << setw(5) << i;
      // begin new line after printing out 10 integers
      if (count % 10 == 0 && count != 0) {
         cout << endl;
      }
      // decrease i by 3 to create multiples of 3, and increase count for each loop
      i = i - 3;
      count++;
   }
   // subtract the counter by 1, because the counter begins at 1 and display how many integers
   count = count - 1;
   cout << endl << "Number of numbers = " << count << "." << endl << endl;

   // set counter and total back to 1
   count = 1;
   total = 1;
   // print out integers between 2 and 1048576 that are integer powers of 2
   do
   {
      // multiply total by 2 each time to create an exponential function b 2
      total = total * 2;
      // set width length to 5 right justified
      cout << setw(9) << total;
      // begin new line after printing out 8 integers
      if (count % 8 == 0) {
         cout << endl;
      }
      // increase the counter each time the loop occurs
      count++;
   } while (count <= 20);
   // subtract the counter by 1 and display how many numbers are printed out
   count = count - 1;
   cout << endl << "Number of numbers = " << count << "." << endl << endl;

   // set counter back to 1 and total to 2^20
   // print out integers between 1048576 down to 2 that are integers of power 2
   for (total = 1048576, count = 1; total >= 2;count++)
   {
      // set width legth to 5 after prnting out 8 integers
      cout << setw(9) << total;
      // divide total by 2 to decrease exponentially by a power of 2
      total = total / 2;
      // begin new line after printing out 8 integers
      if (count % 8 == 0) {
         cout << endl;
      }
   }
   // subtract the counter by 1 and display how many numbers are printed out
   count = count - 1;
   cout << endl << "Number of numbers = " << count << "." << endl << endl;

   // running on a treadmill, you burn 3.5 calories per minute. This program 
   //displays the number of calories burned after 5, 10, 15, 20, 25, and 30 minutes
   calories = 0;
   minutes = 5;
   count = 0;
   do
   {
      // multiply the calories per minute rate (3.5) by minutes
      calories = minutes * 3.5;
      // increase the counter
      count++;
      // ouput how many calories are burned in the time calculated
      cout << "You burn " << calories << " calories in " << minutes << " minutes" << endl;
      minutes += 5;
   } while (minutes <= 30);
   // display how many numbers are printed out
   cout << "Number of numbers = " << count << "." << endl << endl;


   system("pause");
   return 0;
}