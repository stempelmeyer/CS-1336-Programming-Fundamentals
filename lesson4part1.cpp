// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          9/21/2017
// Assignment:    Zybooks Lesson 4 Part 1
// Compiler:      Visual C++ Community 2017

// Description: 
// Use algebraic components to convert an objects mass 
// to the weight on earth, mars, and the moon. 

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
// declare variables
   double objectMass;
   double earthWeight;
   double marsWeight;
   double moonWeight;

// read in object mass
   cin >> objectMass;

   cout << fixed << setprecision(3);
   cout << "The mass is " << objectMass << " kg" << endl;

   if (objectMass <= 0) {
      cout << "The mass must be greater than zero" << endl;
   }
   else {

      // type equations
      earthWeight = objectMass * 9.81;
      moonWeight = objectMass * 1.62;
      marsWeight = objectMass * 3.77;

      // read out mass conversions

      cout << setw(8) << left << "Location" << setw(12) << right << "Weight (N)" << endl;
      cout << setw(8) << left << "Earth" << setw(12) << right << earthWeight << endl;
      cout << setw(8) << left << "Mars" << setw(12) << right << marsWeight << endl;
      cout << setw(8) << left << "Moon" << setw(12) << right << moonWeight << endl;

      if (earthWeight >= 1000) {
         cout << "The object is heavy" << endl;
      }
      else if (earthWeight < 10) {
         cout << "The object is light" << endl;
      }
   }

   return 0;
}