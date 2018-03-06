// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          10/30/2017
// Assignment:    Zybooks Lesson 9 Part 2
// Compiler:      Visual C++ Community 2017

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// declare input and output files
ifstream inFS;
ofstream outFS;

// function that reads in present value, interest rate, and number of months
unsigned int readIn(double& presentValue, double& interestRate, int& months) {

   // read in values from the input file
   inFS >> interestRate;
   inFS >> months;
   // convert interest rate from a percentage to a decimal
   interestRate = interestRate / 100.0;

   // return value 1 if values were read properly
   if (presentValue > 0 || interestRate > 0 || months > 0)
      return 1;

      // return value of 2 indicates input data was invalid
   if (presentValue <= 0 || interestRate <= 0 || months <= 0) {
         // read out values in cout to 2 places after the decimal, and display an error message
         cout << fixed << setprecision(2);
         cout << presentValue << " " << interestRate << " " << months << endl;
         cout << "One or more of the above values are not greater than zero" << endl;
      }
      return 2;

   // return value of 0 indicates that we have reached the end of the file
   if (months == -1)
         return 0;
}

// function calculates the future value and returns it to main
double calculateFutureValue(double presentValue, double& interestRate, int months) {
   double futureValue;

   futureValue = presentValue * pow((1 + interestRate), months);
   // convert interest rate from decimal back to percentage
   interestRate *= 100;

   return futureValue;
}
// this function writes values to output file
void writeToOutputFile(double futureValue, double presentValue, double interestRate, int months) {

   // display values with 2 places after the decimal
   outFS << fixed << setprecision(2);
   outFS << futureValue << "\t" << presentValue << "\t" << interestRate << "\t" << months << endl;
}

   int main()
   {
      // declare variables for input and output file streams and data values from the file
      string fileName;
      double presentValue;
      double interestRate;
      int months = -1;
      double futureValue;
      int answer;

      // read in file name
      cin >> fileName;

      // open file (if able)
      inFS.open(fileName);

      // if input file cannot be opened or does not exist, display error message and stop processing
      if (!inFS.is_open()) {
         cout << "File \"" << fileName << "\" could not be opened" << endl;
         return 0;
      }

      // open output file
      outFS.open("output.xls");

      // if output file cannot be opened or does not exist, close input file, display error message and stop processing
      if (!outFS.is_open()) {
         inFS.close();
         cout << "File \"" << fileName << "\" could not be opened" << endl;
         return 0;
      }

      // write the headings to the output file
      outFS << "Future Value\tPresent Value\tMonthly Interest\tMonths" << endl;

      // function call
      while (inFS >> presentValue) {
         answer = readIn(presentValue, interestRate, months);
         if (answer == 0)
            return 0;
         futureValue = calculateFutureValue(presentValue, interestRate, months);
         writeToOutputFile(futureValue, presentValue, interestRate, months);
      }

      // close both files
      inFS.close();
      outFS.close();

      return 0;
   } // end function main