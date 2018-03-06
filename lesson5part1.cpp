// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          9/22/2017
// Assignment:    Zybooks Lesson 5 Part 1
// Compiler:      Visual C++ Community 2017

// Description: 
// Use algebraic components to display the 
// seconds it will take for sound to travel
// through a medium

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

   // read out options
   cout << "Select the medium that sound is traveling through:" << endl;
   cout << "1 Air" << endl;
   cout << "2 Water" << endl;
   cout << "3 Steel" << endl;

   // read user input
   cin >> medium;

   // output calculations (if valid)
   switch (medium)
   {
   case 1:
   case 2:
   case 3:
      // read in distance
      cout << "Enter distance (in feet)" << endl;
      cin >> distance;

      // display if distance less than or equal to zero
      if (distance <= 0)
      {
         cout << "The distance must be greater than zero" << endl;
      }
      else
      {
         switch (medium)
         {
         case 1:
            // if medium selected is air... display and plug into equations
            cout << fixed << setprecision(1) << "Air: " << distance << " ft" << endl;
            time = distance / 1100;
            cout << "Traveled for " << time << " seconds" << endl;
            break;

            // if medium selected is water... display and plug into equations
         case 2:
            cout << fixed << setprecision(1) << "Water: " << distance << " ft" << endl;
            time = distance / 4900;
            cout << "Traveled for " << time << " seconds" << endl;
            break;

            // if medium selected is steel... display and plug into equations
         case 3:
            cout << fixed << setprecision(1) << "Steel: " << distance << " ft" << endl;
            time = distance / 16400;
            cout << "Traveled for " << time << " seconds" << endl;
            break;

            // display nothing if not in the accepted range of mediums
         }
      }
      break;

      // display if the medium is not in a valid range
   default:
      cout << "The menu value is invalid. Please run the program again." << endl;
      break;
   }

   return 0;
}