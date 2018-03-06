// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          11/10/2017
// Assignment:    Lecture Homework 8 Exercise 2
// Compiler:      Visual C++ Community 2017

// Description: 
// This program calculates the average of a group of test scores 
// where the lowest score in the group is dropped by using multiple
// functions to read in values from the user, calculate the average
// and find the lowest valuse

#include <iostream>
#include <iomanip>

using namespace std;

// function prototypes
/*********************************************************************************
* Function:      void getScore
* Description:   This function asks the user for a test score, store it in a 
*                reference parameter variable and validate it. This function is 
*                called by main only once for each of the five scores to be entered
* Input:         
* Return:        void will not return a value
**********************************************************************************/
void getScore(int& grade);
/*********************************************************************************
* Function:      void calcAverage()
* Description:   This function calculates and display the average of the four 
*                highest scores. This fuction should be called just once to main
*                and should be passed the five scores
* Input:         int grade1, int grade2, int grade3, int grade4, int grade5
* Return:        void will not return a value
**********************************************************************************/
void calcAverage(int, int, int, int, int);
/*********************************************************************************
* Function:      int findLowest()
* Description:   This function finds and returns the lowest of the 5 scores passesd
*                to it. It is called and used by the function calcAverage.
* Input:         int grade1, int grade2, int grade3, int grade4, int grade5
* Return:        int lowestGrade
**********************************************************************************/
int findLowest(int, int, int, int, int);

int main()
{
   // declare variables
   int grade1 = 0;
   int grade2 = 0;
   int grade3 = 0;
   int grade4 = 0;
   int grade5 = 0;
   double average = 0;

   // function call 5 times for each of the grades
   getScore(grade1);
   getScore(grade2);
   getScore(grade3);
   getScore(grade4);
   getScore(grade5);

   // function call to calculate the average of the numbers
   calcAverage(grade1, grade2, grade3, grade4, grade5);

   cout << endl;
   system("pause");
   return 0;
} // end function main

// use function to prompt and read in scores using input validation and pass by references
void getScore (int& grade){
   // prompt the user to enter another test score
   cout << "Please enter a test score: ";
   cin >> grade;

   // input validation loop repeats until valid value is entered 
      while (grade < 0 || grade > 100) {
         cout << "Please enter a value between 0 and 100" << endl;
         cout << "Please enter a test score: ";
         cin >> grade;
      }
   } // end function getScore

void calcAverage(int grade1, int grade2, int grade3, int grade4, int grade5) {
   // declare variables for average and lowest grade
   double average = 0;
   int lowestGrade = 0;

   // function call to find lowest value and assign it to lowest grade
   lowestGrade = findLowest(grade1, grade2, grade3, grade4, grade5);
   
   // calculate the average using this formula
   average = (grade1 + grade2 + grade3 + grade4 + grade5 - lowestGrade) / 4.0;

   // display the average
   cout << endl;
   cout << fixed << setprecision(2);
   cout << average << " is the average of your four highest test scores" << endl;
} // end function calcAverage

int findLowest(int grade1, int grade2, int grade3, int grade4, int grade5) {
   // declare variable for lowest Grade
   int lowestGrade = 100;

   if (grade5 < grade4) {
      lowestGrade = grade5;
      grade4 = grade5;
   }

   if (grade4 < grade3) {
      lowestGrade = grade4;
      grade3 = grade4;
   }

   if (grade3 < grade2) {
      lowestGrade = grade3;
      grade2 = grade3;
   }

   if (grade2 < grade1) {
      lowestGrade = grade2;
      grade1 = grade2;
   }

   if (grade1 < lowestGrade) {
      lowestGrade = grade1;
   }

   return lowestGrade;
} // end function findLowest