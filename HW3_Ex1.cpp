// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          9/29/2017
// Assignment:    Lecture Homework #3 Exercise #1
// Compiler:      Visual C++ Community 2017

// Description: 
// This program demonstrates how we can use algebraic
// properties to calculate the average rainfall in a 
// given time period. 

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
   
   // declare variables
   string firstMonth;
   string secondMonth;
   string thirdMonth;
   double firstMonthRain;
   double secondMonthRain;
   double thirdMonthRain;
   double totalRain;
   double avgRain;


   // read in the first month and the amount of rain that fell
   cout << "Please enter the name of the first month: ";
   cin >> firstMonth;

   cout << "Please enter the the amount of rain that fell in the first month: ";
   cin >> firstMonthRain;

   // read in the second month and the amount of rain that fell
   cout << endl << "Please enter the name of the second month: ";
   cin >> secondMonth;

   cout << "Please enter the the amount of rain that fell in the second month: ";
   cin >> secondMonthRain;

   // read in the third month and the amount of rain that fell
   cout << endl << "Please enter the name of the third month: ";
   cin >> thirdMonth;

   cout << "Please enter the the amount of rain that fell in the third month: ";
   cin >> thirdMonthRain;

   // type in equations to calculate the average rainfall over the course of 3 months
   totalRain = firstMonthRain + secondMonthRain + thirdMonthRain;
   avgRain = totalRain / 3;

   // read out the average rainfall
   cout << fixed << setprecision(2);
   cout << endl << "The average rainfall for " << firstMonth << ", " << secondMonth << ", and ";
   cout << thirdMonth << " was " << avgRain << " inches." << endl << endl;

   system("pause");

   return 0;
}