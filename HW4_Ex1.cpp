// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          9/27/2017
// Assignment:    Lecture Homework #4 Exercise #1
// Compiler:      Visual C++ Community 2017

// Description: 
// This program demonstrates how we can use algebraic
// properties to calculate the amount in savings given 
// values for the principal, interest rate, and 
// number of times compounded. 

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
   // declare variables
   double principal;
   double interestRate;
   double interestRatePercent;
   int numberTimesCompounded;
   double interest;
   double amountInSavings;

   /* read out prompts to the user in order to obtain values for the principal, interest
   rate and the number of times the interest is compounded */
   cout << "Please enter the principal:                                            $";
   cin >> principal;

   cout << "Please enter the interest rate (in percent):                            ";
   cin >> interestRatePercent;

   cout << "Please enter the number of times the interest is compounded per year:   ";
   cin >> numberTimesCompounded;

   // calculate the information we wish to display by using these equations
   interestRate = interestRatePercent / 100;

   amountInSavings = principal * pow(1 + interestRate / numberTimesCompounded, numberTimesCompounded);
   
   interest = amountInSavings - principal;

   // read out the desired output
   cout << fixed << setprecision(2) << endl;
   cout << "Interest Rate:            " << setw(9) << interestRatePercent << "%" << endl;
   cout << "Times Compounded:         " << setw(10) << numberTimesCompounded << endl;
   cout << "Principal:               $" << setw(10) << principal << endl;
   cout << "Interest:                $" << setw(10) << interest << endl;
   cout << "Amount in Savings:       $" << setw(10) << amountInSavings << endl;

   system("pause");

   return 0;
}