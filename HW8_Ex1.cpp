// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          11/10/2017
// Assignment:    Lecture Homework 8 Exercise 1
// Compiler:      Visual C++ Community 2017

// Description: 
// This program reads numbers from a file, and uses functions 
// to determine the amount of prime numbers beginning at 0 up
// to the value that was read

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// function prototypes
bool isPrime(int number);

int main()
{
   // declare variables
   int number;
   int count = 1;
   int currNum = 2;

   // file stream objects
   ifstream inFS;
   ofstream outFS;

   // open file (if able)
   outFS.open("PrimeOut.txt");

   // if file cannot be opened or does not exist
   if (!outFS.is_open())
      cout << "File \"PrimeOut.txt\" could not be opened" << endl;

   // prompt the user to enter a valid integer between 1 and 100
   cout << "Please enter an integer between 1 and 100: ";
   cin >> number;
   cout << endl;

   // use a while loop for input validation
   while (number < 1 || number > 100) {
      cout << endl;
      cout << "The number should be in between 1 and 100." << endl;
      cout << "Please enter an integer between 1 and 100: ";
      cin >> number;
   }

   // displays the beginning of the output
   cout << "The first " << number << " primes:" << endl << endl;
   outFS << "The first " << number << " primes:" << endl << endl;

   // this loop continues until the number of prime numbers displayed reaches the prime numbers asked for by the user
   while (count <= number)
   {
      // if the current number is prime the it should be displayed on the file and the screen
      if (isPrime(currNum)) {
         cout << setw(5) << currNum;
         outFS << setw(5) << currNum;
         // this if statement uses the mod operator so that the numbers are displayed in rows of 10
         if (count % 10 == 0 && count != 1) {
            cout << endl;
            outFS << endl;
         }
         // this increment increases the count for the number of prime numbers each time the outer if statement runs
         count++;
      }
      // this increment increases the current number so that all numbers up to the limited number of prime numbers are tested
      currNum++;
   }

   // close the file
   outFS.close();

   // display space between end of prime list and system pause
   cout << endl;
   system("pause");
   return 0;
} // end function main

/*********************************************************************************
* Function:      isPrime (int currNum)
* Description:   This function takes the integer currNum as input, then calculates
*                and returns if it is a prime number or not by using bool.
*                It works by testing if it divisible by any number up to the 
*                inputted number divided by 2. If it is divisible then the number  
*                must be composite, and therefore not prime (false).
* Input:         int CurrNum
* Return:        True or False depending if the number was found to be divisible
**********************************************************************************/
bool isPrime(int currNum)
{
   // declare and intialize the return bool as true
   bool prime = true;
   // test if integers up tp the number divided by 2 are completely divisible
   for (int i = 2; i <= (currNum / 2); ++i)
   {
      if (currNum % i == 0)
      {
         // if the number is divisible then it is not prime and breaks out of the loop
         prime = false;
         break;
      }
   }
   // return the prime bool which is true or false depending if it fully divisible or not
   return prime;
}