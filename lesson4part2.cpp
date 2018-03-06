// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          9/21/2017
// Assignment:    Zybooks Lesson 4 Part 2
// Compiler:      Visual C++ Community 2017

// Description: 
// Use algebraic components to display the 
// days, hours, minutes, and remaining seconds.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
   // declare variables
   long long int totalSeconds;
   long long int minutes;
   long long int hours;
   long long int days;
   long long int remainingSeconds;

   // read in total seconds
   cin >> totalSeconds;

   // display total seconds
   cout << "Total seconds: " << totalSeconds << endl << endl;

   // use if else statements depending on the total seconds
   if (totalSeconds <= 0) {
      cout << "Total seconds must be greater than zero" << endl;
   }
   else {
      // type equations if the total seconds are greater than zero
      days = totalSeconds / 60 / 60 / 24;
      hours = (totalSeconds / 60 / 60) % 24;
      minutes = (totalSeconds / 60) % 60;
      remainingSeconds = totalSeconds % 60;

      // display if days are greater than zero
      if (days > 0) {
         cout << days << " day(s)" << endl;
      }
      else {
      }
      // display if hours are greater than zero
      if (hours > 0) {
         cout << hours << " hour(s)" << endl;
      }
      else {
      }
      // display if minutes are greater than zero
      if (minutes > 0) {
         cout << minutes << " minute(s)" << endl;
      }
      // display if remaining seconds are greater than zero
      if (remainingSeconds > 0) {
         cout << remainingSeconds << " second(s)" << endl;
      }
   }

   return 0;
}