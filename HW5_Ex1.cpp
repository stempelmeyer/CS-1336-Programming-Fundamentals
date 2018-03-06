// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          10/5/2017
// Assignment:    Lecture Homework #5 Exercise #1
// Compiler:      Visual C++ Community 2017

// Description: 
// This program demonstrates how we can use algebraic
// properties to calculate the minutes, hours, and days 
// given a certain number of seconds entered by the user 

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   // declare variables
   double seconds;
   double minutes;
   double hours;
   double days;

   // read in the number of seconds entered by the user
   cout << "Please enter the number of seconds:          ";
   cin >> seconds;

   // use an if-else-if to determine which of these equations should be calculated
   // calculate these equations and output with two decimals if seconds are within 
   // the constraints
   if (seconds < 60)
   {
      cout << seconds << " seconds is ";
      cout << fixed << setprecision(2) << seconds << " seconds." << endl;
   }

   else if (seconds >= 60 && seconds < 3600)
   // calculate these equations and output with two decimals if seconds are within 
   // the constraints
   {
      minutes = seconds / 60;
      cout << seconds << " seconds is ";
      cout << fixed << setprecision(2) << minutes << " minutes." << endl;
   }
   else if (seconds >= 3600 && seconds < 86400)
   // calculate these equations and output with two decimals if seconds are within 
   // the constraints
   {
      hours = seconds / 3600;
      cout << seconds << " seconds is ";
      cout << fixed << setprecision(2) << hours << " hours." << endl;
   }
   else if (seconds >= 86400)
   // calculate these equations and output with two decimals if seconds are within 
   // the constraints
   {
      days = seconds / 86400;
      cout << seconds << " seconds is ";
      cout << fixed << setprecision(2) << days << " days." << endl;
   }

   system("pause");

   return 0;
} // end function main