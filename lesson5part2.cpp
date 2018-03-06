// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          9/22/2017
// Assignment:    Zybooks Lesson 5 Part 2
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
   unsigned int medium;
   double distance = 0.0;
   double time;

   // read out prompt for user
   cout << "Select the medium that sound is traveling through:" << endl;
   cout << "1 Carbon Dioxide" << endl;
   cout << "2 Air" << endl;
   cout << "3 Helium" << endl;
   cout << "4 Hydrogen" << endl;

   // read user input
   cin >> medium;

   // output calculations (if valid)
   if (medium == 0 || medium > 4) {
      cout << "The menu value is invalid. Please run the program again." << endl;
   }
   else {
      // if medium is valid, display prompt for the user to input time
      cout << "Enter time (in seconds)" << endl;
      cin >> time;
      // if time not in a valid range
      if (time < 0 || time > 30) {
         cout << "The time must be between 0.0 and 30.0 (inclusive)" << endl;
      }
      else {
         // if medium and time are valid, read out seconds and distance traveled based on the specific equation
         if (medium == 1) {
            cout << fixed << setprecision(1) << "Carbon Dioxide: " << time << " seconds" << endl;
            distance = time * 258.0;
            cout << fixed << setprecision(2) << "Traveled " << distance << " meters" << endl;
         }
         // if medium and time are valid, read out seconds and distance traveled based on the specific equation
         if (medium == 2) {
            cout << fixed << setprecision(1) << "Air: " << time << " seconds" << endl;
            distance = time * 331.5;
            cout << fixed << setprecision(2) << "Traveled " << distance << " meters" << endl;
         }
         // if medium and time are valid, read out seconds and distance traveled based on the specific equation
         if (medium == 3) {
            cout << fixed << setprecision(1) << "Helium: " << time << " seconds" << endl;
            distance = time * 972.0;
            cout << fixed << setprecision(2) << "Traveled " << distance << " meters" << endl;
         }
         // if medium and time are valid, read out seconds and distance traveled based on the specific equation
         if (medium == 4) {
            cout << fixed << setprecision(1) << "Hydrogen: " << time << " seconds" << endl;
            distance = time * 1270.0;
            cout << fixed << setprecision(2) << "Traveled " << distance << " meters" << endl;
         }
      }
   }
   return 0;
}