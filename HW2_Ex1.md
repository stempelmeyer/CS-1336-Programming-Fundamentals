# CS-1336-Programming-Fundamentals
I took this class with Charles Shields at the University of Texas at Dallas

// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          9/12/2017
// Assignment:    Lecture Homework #2 Exercise #1
// Compiler:      Visual C++ Community 2017

// Description:
// This program uses its algebraic capabilities
// to determine the gallons required for a given 
// mpg and travel distance. 

#include <iostream>
#include <iomanip>

using namespace std;

int main()

{
   // declare variables
   double inTownMiles;
   double highwayMiles;
   const double MPG_IN_TOWN = 23.5;
   const double MPG_HIGHWAY = 28.9;
   double inTownGallons;
   double highwayGallons;
   double totalGallons;

   // ask user how far he/she must go under in-town condition 
   cout << "Please enter the number of in-town driving miles:   ";

   // read in user input for in-town miles
   cin >> inTownMiles;

   // ask user how far he/she must go under highway condition
   cout << "Please enter the number of highway miles:           ";

   // read in user input for highway miles
   cin >> highwayMiles;

   // type equations
   inTownGallons = (inTownMiles / MPG_IN_TOWN);
   highwayGallons = (highwayMiles / MPG_HIGHWAY);
   totalGallons = inTownGallons + highwayGallons;

   cout << fixed << setprecision(1);
   // read out the total number of gallons required
   cout << endl << "The total number of gallons required is:             " << totalGallons << " gal." << endl;

   system("pause");

   return 0;
} // end function main ()
