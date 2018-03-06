// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          10/28/2017
// Assignment:    Lecture Homework 6 Exercise 2
// Compiler:      Visual C++ Community 2017

// Description: 
// Using file inputs and loops display a sales bar chart
// where each X equals 1,000 dollars

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   // declare variables for the sales from each store that the user will input
   long long int store1Sales = 0;
   long long int store2Sales = 0;
   long long int store3Sales = 0;
   long long int store4Sales = 0;
   long long int store5Sales = 0;

   // prompt the user to enter the sales value for the store
   cout << "Enter today's sales for store 1: ";
   cin >> store1Sales;

   // this while loop is an input validation loop, prompting the user to enter a non-negative value
   while (store1Sales < 0)
   {
      cout << "Please enter a value greater than zero" << endl;
      cout << "Enter today's sales for store 1: ";
      cin >> store1Sales;
   }

   // prompt the user to enter the sales value for the store
   cout << "Enter today's sales for store 2: ";
   cin >> store2Sales;

   // this while loop is an input validation loop, prompting the user to enter a non-negative value
   while (store2Sales < 0)
   {
      cout << "Please enter a value greater than zero" << endl;
      cout << "Enter today's sales for store 2: ";
      cin >> store2Sales;
   }

   // prompt the user to enter the sales value for the store
   cout << "Enter today's sales for store 3: ";
   cin >> store3Sales;

   // this while loop is an input validation loop, prompting the user to enter a non-negative value
   while (store3Sales < 0)
   {
      cout << "Please enter a value greater than zero" << endl;
      cout << "Enter today's sales for store 3: ";
      cin >> store3Sales;
   }

   // prompt the user to enter the sales value for the store
   cout << "Enter today's sales for store 4: ";
   cin >> store4Sales;

   // this while loop is an input validation loop, prompting the user to enter a non-negative value
   while (store4Sales < 0)
   {
      cout << "Please enter a value greater than zero" << endl;
      cout << "Enter today's sales for store 4: ";
      cin >> store4Sales;
   }

   // prompt the user to enter the sales value for the store
   cout << "Enter today's sales for store 5: ";
   cin >> store5Sales;

   // this while loop is an input validation loop, prompting the user to enter a non-negative value
   while (store5Sales < 0)
   {
      cout << "Please enter a value greater than zero" << endl;
      cout << "Enter today's sales for store 5: ";
      cin >> store5Sales;
   }

      // display the title and key for the sales bar chart
      cout << endl;
      cout << "SALES BAR CHART" << endl;
      cout << "(Each * equals $100)" << endl;

      // use for loops to display the amount of *'s necessary for the given store's sales
      cout << "Store 1: ";
      // the for loop will repeat until reaching the truncated value of the sales divided by 100
      for (int i = 0; i < store1Sales / 100; ++i)
         cout << "*";

      // the for loop will repeat until reaching the truncated value of the sales divided by 100
      cout << endl << "Store 2: ";
      for (int i = 0; i < store2Sales / 100; ++i)
         cout << "*";

      // the for loop will repeat until reaching the truncated value of the sales divided by 100
      cout << endl << "Store 3: ";
      for (int i = 0; i < store3Sales / 100; ++i)
         cout << "*";

      // the for loop will repeat until reaching the truncated value of the sales divided by 100
      cout << endl << "Store 4: ";
      for (int i = 0; i < store4Sales / 100; ++i)
         cout << "*";

      // the for loop will repeat until reaching the truncated value of the sales divided by 100
      cout << endl << "Store 5: ";
      for (int i = 0; i < store5Sales / 100; ++i)
         cout << "*";
      cout << endl;

   system("pause");
   return 0;
} // end function main