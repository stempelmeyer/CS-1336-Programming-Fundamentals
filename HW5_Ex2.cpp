// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          10/5/2017
// Assignment:    Lecture Homework #5 Exercise #2 BONUS
// Compiler:      Visual C++ Community 2017

// Description: 
// This program demonstrates how we can use algebraic
// properties and switch and if statements to calculate
// the total cost given the package and minutes entered 
// by the user and calculate and display the cheapest
// cost and package.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   // declare and initizalize constants and variables
   char choice;
   double package = 0;
   double minutes = 0;
   double addMinutes = 0;
   double totalCostA = 0;
   double totalCostB = 0;
   double totalCostC = 0;
   double addMinutesCost = 0;
   double notPackage1 = 0;
   double notPackage2 = 0;
   const double PACKAGE_A = 39.99;
   const double PACKAGE_B = 59.99;
   const double PACKAGE_C = 69.99;
   const double ADD_MINUTES_A = 0.45;
   const double ADD_MINUTES_B = 0.40;

   // prompt and read in the user input for minutes
   cout << "Please enter how many minutes were used:        ";
   cin >> minutes;

   // evaluate and calculate these equations if the minutes (450) are maximized or exceeded
   if (minutes >= 450)
   {
      addMinutes = minutes - 450;
      addMinutesCost = addMinutes * ADD_MINUTES_A;
      totalCostA = addMinutesCost + PACKAGE_A;
   }
   // evaluate and calculate these equations if the minutes are under the limits
   else
      totalCostA = PACKAGE_A;

   // evaluate and calculate these equations if the minutes (900) are maximized or exceeded
   if (minutes >= 900)
   {
      addMinutes = minutes - 900;
      addMinutesCost = addMinutes * ADD_MINUTES_B;
      totalCostB = addMinutesCost + PACKAGE_B;
   }
   // evaluate and calculate these equations if the minutes are under the limits
   else
      totalCostB = PACKAGE_B;

   // calculate this equation regardless of the minute inputted
   totalCostC = PACKAGE_C;

   // prompt and read in the user input for package
   cout << "Please select a package (A, B, or C):           ";
   cin >> choice;

   // use a switch statement to calculate and assign these costs to the variables depending on the packages
   // (uppercase or lowercase) that the user chooses
   switch (choice)
   {
   case 'A':
   case 'a':
      // assign chosen cost to the package chosen and unchosen costs to the notpackages
      package = totalCostA;
      notPackage1 = totalCostB;
      notPackage2 = totalCostC;
      break;

   case 'B':
   case 'b':
      // assign chosen cost to the package chosen and unchosen costs to the notpackages
      package = totalCostB;
      notPackage1 = totalCostA;
      notPackage2 = totalCostC;
      break;

   case 'C':
   case 'c':
      // assign chosen cost to the package chosen and unchosen costs to the notpackages
      package = totalCostC;
      notPackage1 = totalCostA;
      notPackage2 = totalCostB;
      break;

   // this should be displayed if the user doesn't choose a valid package (A,a,B,b,C,c)
   default:
      cout << "Please select a valid package (A, B, C)" << endl;
      break;
   }

   // this if statement is used so that an unvalid package will not display and calculate these
   if (choice == 'A' || choice == 'a' || choice == 'B' || choice == 'b' || choice == 'C' || choice == 'c')
   {
      // display total monthly bill if the user chooses the package with the best monthly rate
      if (package < notPackage1 && package < notPackage2)
      {
         cout << "Your total monthly bill is:                     $" << package << endl;
         cout << "Congratulations on making the right choice!" << endl;
      }

      // display total monthly bill and the cheapest package and it's price if the 
      // cheapest package is not selected
      else
      {
         cout << "Your total monthly bill is:                     $" << package << endl;
         cout << "But don't you fret, there is a better option available!" << endl;

         // these if statements are used to determine the cheapest package by comparing
         // the packages not selected by the user
         if (notPackage1 < notPackage2)
         {
            if (choice == 'A' || choice == 'a')
               cout << "Your best package is B priced at $" << notPackage1 << endl;
            if (choice == 'B' || choice == 'b')
               cout << "Your best package is A priced at $" << notPackage1 << endl;
            if (choice == 'C' || choice == 'c')
               cout << "Your best package is A priced at $" << notPackage1 << endl;
         }

         // these if statements are used to determine the cheapest package by comparing
         // the packages not selected by the user
         if (notPackage2 < notPackage1)
         {
            if (choice == 'A' || choice == 'a')
               cout << "Your best package is C priced at $" << notPackage2 << endl;
            if (choice == 'B' || choice == 'b')
               cout << "Your best package is C priced at $" << notPackage2 << endl;
            if (choice == 'C' || choice == 'c')
               cout << "Your best package is B priced at $" << notPackage2 << endl;
         }
      }
   }

   system("pause");
   return 0;
} // end function main