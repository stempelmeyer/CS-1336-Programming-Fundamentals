// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          10/24/2017
// Assignment:    Zybooks Lesson 8 Part 1
// Compiler:      Visual C++ Community 2017

// Description: 
// This program reads numbers from a file, counts, and calculates
// an average of the valid numbers between 0 and 110 inclusive.
// Invalid numbers are counted and written to an ouput file.

#include <iostream>
#include <iomanip>

using namespace std;

// use this function to read in and return seconds if valid
double readSeconds()
{
   // declare local variables
   double seconds = 1;

   // use this while loop for input validation
   while (seconds != 0)
   {
      // use this if statement to prompt the user to enter a positive number
      if (seconds < 0)
      {
         cout << "The time must be zero or more" << endl;
      }
      // if the user enters 0 seconds, return back to the main function
      if (seconds == 0)
         break;

      // display prompt and read in seconds
      cout << "Enter the time (in seconds)" << endl;
      cin >> seconds;
      if (seconds > 0)
      break;
   }
   return seconds;
}

// use this function to calculate and retunr distance back to the main function
double calculateDistance(double seconds)
{
   // declare local variables
   double distance;
   double timeSeconds = seconds;
   const double ACCELERATION = 9.8;

   distance = (1.0 / 2) * (ACCELERATION)* timeSeconds * timeSeconds;

   return distance;
}

// use this function to read out the distance traveled in the given amount of time
void displayResults(double seconds, double distance)
{
   cout << fixed << setprecision(2);
   cout << "The object traveled " << distance << " meters in " << setprecision(1) << seconds << " seconds" << endl;
}

int main()
{
   // declare variables
   double timeSeconds = 1;
   double distance;

   // use this while loop when the seconds inputted are not equal to zero
   while (timeSeconds != 0) 
   {
         // these are function calls whos returns are assigned to the variables for the next function call
         timeSeconds = readSeconds();
         // if seconds are equal to zero, end the program
         if (timeSeconds == 0)
            break;
         distance = calculateDistance(timeSeconds);
         displayResults(timeSeconds, distance);
   }
   return 0; // end function main
}