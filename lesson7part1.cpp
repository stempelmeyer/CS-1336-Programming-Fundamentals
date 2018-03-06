// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          10/19/2017
// Assignment:    Zybooks Lesson 7 Part 1
// Compiler:      Visual C++ Community 2017

// Description: 
// Using file inputs and loops display a sales bar chart
// where each X equals 1,000 dollars

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
   // declare variables for input and output file streams and data values from the file
   ifstream salesFile;
   ofstream salesChart;
   string fileName;
   long long int store1Sales = 0;
   long long int store2Sales = 0;
   long long int store3Sales = 0;
   long long int store4Sales = 0;
   long long int store5Sales = 0;

   // read in file name
   cin >> fileName;

   // open file (if able)
   salesFile.open(fileName);

   // read in the data values from the file
   salesFile >> store1Sales >> store2Sales >> store3Sales >> store4Sales >> store5Sales;

   // if file cannot be opened or does not exist
   if (!salesFile.is_open())
      cout << "File \"" << fileName << "\" could not be opened" << endl;

   // use if statement if any of the values are negative
   else if (store1Sales < 0 || store2Sales < 0 || store3Sales < 0 || store4Sales < 0 || store5Sales < 0)
      cout << "One or more of the sales values are negative" << endl;

   // use if statement if any of the variables are not in the file
   else if (store1Sales == 0 || store2Sales == 0 || store3Sales == 0 || store4Sales == 0 || store5Sales == 0)
      cout << "Your input file must contain the sales values for five stores" << endl;

   else {
      // open output file
      salesChart.open("saleschart.txt");

      // write to file of the sales bar chart
      salesChart << "SALES BAR CHART" << endl;
      salesChart << "(Each X equals 1,000 dollars)" << endl;

      // use for loops to write to file the amount of X's necessary for the given store's sales
      salesChart << "Store 1: ";
      // the for loop will repeat until reaching the truncated value of the sales divided by 1000
      for (int i = 0; i < store1Sales / 1000; ++i)
         salesChart << "X";

      // the for loop will repeat until reaching the truncated value of the sales divided by 1000
      salesChart << endl << "Store 2: ";
      for (int i = 0; i < store2Sales / 1000; ++i)
         salesChart << "X";

      // the for loop will repeat until reaching the truncated value of the sales divided by 1000
      salesChart << endl << "Store 3: ";
      for (int i = 0; i < store3Sales / 1000; ++i)
         salesChart << "X";

      // the for loop will repeat until reaching the truncated value of the sales divided by 1000
      salesChart << endl << "Store 4: ";
      for (int i = 0; i < store4Sales / 1000; ++i)
         salesChart << "X";

      // the for loop will repeat until reaching the truncated value of the sales divided by 1000
      salesChart << endl << "Store 5: ";
      for (int i = 0; i < store5Sales / 1000; ++i)
         salesChart << "X";
      salesChart << endl;
   }

      // close both files
      salesFile.close();
      salesChart.close();
   

   return 0;
} // end function main