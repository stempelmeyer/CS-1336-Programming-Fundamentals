// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          10/16/2017
// Assignment:    Zybooks Lesson 6 Part 1
// Compiler:      Visual C++ Community 2017

// Description: 
// Use algebraic components to display the 
// days, hours, minutes, and remaining seconds.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   // declare variables
   int lower = 0;
   int upper = 0;

   //prompt the user to enter lower and upper values
   cout << "Enter lower and upper values" << endl;
   cin >> lower >> upper;

   // display this if the user's values are invalid or not in the correct order
   if (lower < 32 || lower > 126 || upper < 32 || upper > 126 || lower > upper) {
      while (lower < 32 || lower > 126 || upper < 32 || upper > 126 || lower > upper) {
         if (lower < 32 || lower > 126 || upper < 32 || upper > 126 || lower > upper)
         // prompt the user to enter valid values and assign them to the variables
         cout << "Values must be in range 32 to 126 inclusive" << endl;
         cout << "Enter lower and upper values" << endl;

         cin >> lower >> upper;
      }
   }
   
   // display this on the screen regardless of the (valid) values inputted
   cout << "Characters for ASCII values between " << lower << " and " << upper << endl;
   cout << "----+----+----+-" << endl;
   
   // use a for loop to change the values between the lower and upper to chars
   for (int i = 0; lower <= upper; ++i)
   {
      // use if statement to begin a new line after 16 characters
      if (i % 16 == 0 && i!=0)
         cout << endl;
      // use static cast to change the lower int to a char
      cout << static_cast<char>(lower);
      lower++;
   }

   // again, display this on the screen regardless of the (valid) values inputted
   cout << endl << "----+----+----+-" << endl;

   return 0;
} // end function main