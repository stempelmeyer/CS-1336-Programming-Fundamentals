// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          10/26/2017
// Assignment:    Zybooks Lesson 8 Part 2
// Compiler:      Visual C++ Community 2017

// Description: 
// Use 5 functions to read in, determine, and display a present value in a savings 
// account once the user inputs a future value, annual interest rate, and number of 
// years the money will sit in the account unchanged

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// use this function to read in a valid future value and return it to main
double futValue() 
{
   // declare variable
   double future;
   // prompt the user to enter future value and read in
   cout << "Enter future value" << endl;
   cin >> future;
   // input validation if the future value is not valid
   while (future <= 0) {
      cout << "The future value must be greater than zero" << endl;
      cout << "Enter future value" << endl;
      cin >> future;
   }
   return future;
}

// use this function to read in a valid annual interest rate and return it to main
double annualInterestRate() 
{
   // declare variable
   double annualInterest;
   // prompt the user to enter a valid annual interest rate and read in
   cout << "Enter annual interest rate" << endl;
   cin >> annualInterest;
   // input validation if the annual interest rate is not valid
   while (annualInterest <= 0) {
      cout << "The annual interest rate must be greater than zero" << endl;
      cout << "Enter annual interest rate" << endl;
      cin >> annualInterest;
   }
   return annualInterest;
}

// use this function to read in a valid number of years and return it to main
int numberOfYears() 
{
   // declare variable
   int numberYears;
   // prompt the user to enter a valid number of years and read in
   cout << "Enter number of years" << endl;
   cin >> numberYears;
   // input validation if the number of years is not valid
   while (numberYears <= 0) {
      cout << "The number of years must be greater than zero" << endl;
      cout << "Enter number of years" << endl;
      cin >> numberYears;
   }
   return numberYears;
}

// use this function to calculate the present value using future value, interest rate, and number of years
double calculatePresentValue(double futureValue, double interestRate, int numberYears) 
{
   // declare variable
   double present;
   double denominator;
   // use equation to calculate present value
   denominator = pow((1 + interestRate), numberYears);
   present = futureValue / denominator;
   return present;
}

// this function displays the results
void displayResults(double presentValue, double futureValue, double interestRate, int numberYears)
{
   // fixed point and set precision causes there to exist a specific number of digits after the decimal
   cout << fixed << setprecision(2);
   cout << "Present value: $" << presentValue << endl;
   cout << "Future value: $" << futureValue << endl;
   cout << setprecision(1);
   cout << "Annual interest rate: " << interestRate << "%" << endl;
   cout << "Years: " << numberYears << endl;
}

int main()
{
   // declare variables
   double futureValue;
   double interestRate;
   int numberYears;
   double present;

   // function call and assign return values to these variables
   futureValue = futValue();
   interestRate = annualInterestRate();
   numberYears = numberOfYears();

   // put interest rate from percentage into decimal
   interestRate /= 100;

   present = calculatePresentValue(futureValue, interestRate, numberYears);

   // put interest rate from decimal into percentage
   interestRate *= 100;

   // call this function (void) which will display the results
   displayResults(present, futureValue, interestRate, numberYears);

   return 0;
} // end function main