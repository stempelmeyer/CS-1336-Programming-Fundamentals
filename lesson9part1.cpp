// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          10/27/2017
// Assignment:    Zybooks Lesson 8 Part 2
// Compiler:      Visual C++ Community 2017

// Description: 
// Use 3 functions to read in, calculate, and display the status of an order for spools 
// from the Acme Wholesale Copper Wire Company. This program will read out the number of
// spools that are ready to ship from the current stock, the number of spools on back-order, 
// the subtotal of the spools ready to ship, the total shipping and handling charges for 
// the spools ready to ship, and the total of the order ready to ship.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// function prototypes
void readIn(double& spoolsOrdered, double& spoolsStocked, double& shCharge);
void displayPrompt(double spoolsOrdered, double spoolsStocked, double shCharge);

int main()
{
   // declare variables
   double spoolsOrdered = 0;
   double spoolsStocked = 0;
   double shCharge = 0;

   // fuction call the read in and display functions
   readIn(spoolsOrdered, spoolsStocked, shCharge);
   displayPrompt(spoolsOrdered, spoolsStocked, shCharge);

   return 0;
}
// use pass-by reference to update the values that the user enters into the function
void readIn(double& spoolsOrdered, double& spoolsStocked, double& shCharge) {
   // declare variables and initialize shipping and handling to default cost
   char specialOrNot;
   shCharge = 11.88;

   // dsplay prompt and read in value entered by user
   cout << "Spools to be ordered" << endl;
   cin >> spoolsOrdered;
   // input validation until the user iputs a valid value
   while (spoolsOrdered <= 0) {
      cout << "Spools order must be 1 or more" << endl;
      cout << "Spools to be ordered" << endl;
      cin >> spoolsOrdered;
   }

   // dsplay prompt and read in value entered by user
   cout << "Spools in stock" << endl;
   cin >> spoolsStocked;
   // input validation until the user iputs a valid value
   while (spoolsStocked < 0) {
      cout << "Spools in stock must be 0 or more" << endl;
      cout << "Spools in stock" << endl;
      cin >> spoolsStocked;
   }

   // dsplay prompt and read in value entered by user
   cout << "Special shipping and handling (y or n)" << endl;
   cin >> specialOrNot;
   if (specialOrNot == 'y') {
      cout << "Shipping and handling amount" << endl;
      cin >> shCharge;
      // input validation until the user iputs a valid value
      while (shCharge < 0) {
         cout << "The spool shipping and handling charge must be 0.0 or more" << endl;
         cout << "Shipping and handling amount" << endl;
         cin >> shCharge;
      }
      // return back to main with the default shipping and handling cost
      return;
   }
   return; // return back to main
}

// this function is void and will not return a value but will display the results
void displayPrompt(double spoolsOrdered, double spoolsStocked, double shCharge) {
   // declare variables
   double spoolsBackOrder;
   double subtotalSpolsShipped;
   double totalSHCharges;
   double totalOrder;

   // this if statement will be used if spools stocked is not greater than spools ordered
   if (spoolsOrdered >= spoolsStocked) {
      // use these equations to make calculations that will be displayed
      spoolsBackOrder = spoolsOrdered - spoolsStocked;
      subtotalSpolsShipped = spoolsStocked * 100;
      totalSHCharges = spoolsStocked * shCharge;
      totalOrder = subtotalSpolsShipped + totalSHCharges;

      // display the calculations and user-inputed values with a fixed notation for prices
      cout << "Spools ready to ship: " << spoolsStocked << endl;
      cout << "Spools on back-order: " << spoolsBackOrder << endl;
      cout << fixed << setprecision(2);
      cout << "Subtotal ready to ship: $" << setw(10) << subtotalSpolsShipped << endl;
      cout << "Shipping and handling:  $" << setw(10) << totalSHCharges << endl;
      cout << "Total shipping charges: $" << setw(10) << totalOrder << endl;
   }
   // this if statement will be used if spools stocked is less than spools ordered.. the spools on back-order and total SH charges are 0
   else
   {
      // use these equations to make calculations that will be displayed
      subtotalSpolsShipped = spoolsOrdered * 100;
      totalSHCharges = 0;
      totalOrder = subtotalSpolsShipped + totalSHCharges;

      // display the calculations and user-inputed values with a fixed notation for prices
      cout << "Spools ready to ship: " << spoolsOrdered << endl;
      cout << "Spools on back-order: 0" << endl;
      cout << fixed << setprecision(2);
      cout << "Subtotal ready to ship: $" << setw(10) << subtotalSpolsShipped << endl;
      cout << "Shipping and handling:  $" << setw(10) << totalSHCharges << endl;
      cout << "Total shipping charges: $" << setw(10) << totalOrder << endl;
   }
   return; // return back to main
}