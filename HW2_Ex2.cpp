// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          9/12/2017
// Assignment:    Lecture Homework #2 Exercise #1
// Compiler:      Visual C++ Community 2017

// Description:
// This program uses its algebraic capabilities
// to convert temperatures in Kelvin, Celsius,  
// and Fahrenheit interchangeably. 

#include <iostream>
#include <iomanip>

using namespace std;

int main()

{
   // declare variables
   double tempCelsius;
   double tempFar;
   double tempKelvin;

   // ask for number in Celsius
   cout << "Please enter a number in degrees Celsius:      ";

   // read in user input for temperature in Celsius
   cin >> tempCelsius;

   // type equations for Celsius to Fahrenheit and Kelvin
   tempFar = 9 * tempCelsius / 5 + 32;
   tempKelvin = tempCelsius + 273.15;

   // display conversions to Fahrenheit and Kelvin
   cout << fixed << setprecision(2);
   cout << endl << "The equivalent Fahrenheit temperature is:      " << tempFar << " degrees." << endl;
   cout << "The equivalent Kelvin temperature is:          " << tempKelvin << " K." << endl << endl;

   // ask for number in Fahrenheit
   cout << "Please enter a number in degrees Fahrenheit:   ";

   // read in user input for temperature in Fahrenheit
   cin >> tempFar;

   // type equations for Fahrenheit to Celsius and Kelvin
   tempCelsius = 5 * (tempFar - 32) / 9;
   tempKelvin = tempCelsius + 273.15;

   // display conversions to Celsius and Kelvin
   cout << endl << "The equivalent Celsius temperature is:         " << tempCelsius << " degrees." << endl;
   cout << "The equivalent Kelvin temperature is:          " << tempKelvin << " K." << endl << endl;

   // ask for number in Kelvin
   cout << "Please enter a number in Kelvin:               ";

   // read in user input for temperature in Kelvin
   cin >> tempKelvin;

   // type equations for Kelvin to Celsius and Fahrenheit
   tempCelsius = tempKelvin - 273.15;
   tempFar = 9 * tempCelsius / 5 + 32;

   // display conversions to Celsius and Fahrenheit
   cout << endl << "The equivalent Celsius temperature is:         " << tempCelsius << " degrees." << endl;
   cout << "The equivalent Fahrenheit temperature is:      " << tempFar << " degrees." << endl << endl;

   system("pause");

   return 0;
} // end function main ()