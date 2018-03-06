// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          9/29/2017
// Assignment:    Lecture Homework #3 Exercise #2
// Compiler:      Visual C++ Community 2017

// Description: 
// This program demonstrates how we can use algebraic
// properties to calculate the mortgage given values 
// for the loan amount, annual interest rate, and 
// number of payments. 

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main ()
{
   // declare variables
   double loanAmount;
   double annualInterestRate;
   double monthlyInterestRate;
   int monthlyInterestRatePercent;
   int numberPayments;
   double monthlyPayment;
   double numberNumerator;
   double numberDenominator;
   double amountPaidBack;
   double interestPaid;

   /* read out prompts to the user in order to obtain values for the loan 
   amount, annual interest rate, and the number of payments */
   cout << "Please enter the loan amount:                         $";
   cin >> loanAmount;

   cout << "Please enter the annual interest rate (in percent):   ";
   cin >> annualInterestRate;

   cout << "Please enter the number of payments:                  ";
   cin >> numberPayments;

   // calculate the information we wish to display by using these equations
   monthlyInterestRate = annualInterestRate / 12 / 100 ;
   monthlyInterestRatePercent = annualInterestRate / 12;

   numberNumerator = (loanAmount * monthlyInterestRate) * (double) pow (1 + monthlyInterestRate, numberPayments);
   numberDenominator = ((double)pow(1 + monthlyInterestRate, numberPayments)) - 1;

   monthlyPayment = numberNumerator / numberDenominator;
   amountPaidBack = monthlyPayment * 36;
   interestPaid = amountPaidBack - loanAmount;

   // read out the desired output
   cout << fixed << setprecision (2) << endl;
   cout << "Loan amount:            $" << setw(10) << loanAmount << endl;
   cout << "Monthly Interest Rate:   " << setw(9) << monthlyInterestRatePercent << "%" << endl;
   cout << "Number of Payments:      " << setw(10) << numberPayments << endl;
   cout << "Monthly Payment:        $" << setw(10) << monthlyPayment << endl;
   cout << "Amount Paid Back:       $" << setw(10) << amountPaidBack << endl;
   cout << "Interest Paid:          $" << setw(10) << interestPaid << endl << endl;

   system("pause");

   return 0;
}