// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          10/14/2017
// Assignment:    Zybooks Lesson 6 Part 2
// Compiler:      Visual C++ Community 2017

// Description: 
// Using boundaries and increments inputted by the user 
// display the values between the starting and ending values
// in fahrenheit and celsius

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   // declare variables
   double startingTempFah;
   double endingTempFah;
   double increment;
   double startingTempCels;
   double endingTempCels;

   // read in the starting and ending temps and increments
   cin >> startingTempFah >> endingTempFah >> increment;

   // use a while loop until the user inputs valid values
   while (startingTempFah > endingTempFah || increment <= 0) {
      // prompt the user to input valid values and read in 
      cout << "Starting temperature must be <= ending temperature and increment must be > 0.0" << endl;
      cin >> startingTempFah >> endingTempFah >> increment;
   }

   // display this output regardless of input and set output to display numbers with three digits
   // after the decimal place
   cout << fixed << setprecision(3);
   cout << setw(15) << "Fahrenheit" << setw(15) << "Celsius" << endl;

   // calculate and display the starting temps in fahrenheit and celsius
   startingTempCels = (startingTempFah - 32) / 1.8;
   cout << setw(15) << startingTempFah << setw(15) << startingTempCels << endl;

   // display the temperatures in Fahrenheit and Celsius using the increments 
   // inputted by the user and give them a set width so the numbers are right justified
   while (startingTempFah <= endingTempFah - increment) {
      startingTempFah += increment;
      startingTempCels = (startingTempFah - 32) / 1.8;

      cout << setw(15) << startingTempFah << setw(15) << startingTempCels << endl;

   }

   return 0;
} // end function main