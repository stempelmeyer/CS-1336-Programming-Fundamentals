// Author:        Sarah Tempelmeyer
// Course:        CS1336.003
// Date:          11/30/2017
// Assignment:    Lecture Homework 9 Exercise 2
// Compiler:      Visual C++ Community 2017

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

// fuction prototypes
/*********************************************************************************
* Function:      int readIn
* Description:   This function uses the arguments containing a character array and 
*                the string for the file name to open a file, and read in the 
*                values into an array.
* Input:         the student or answers array and the corresponding file name
* Return:        returns an int for how many elements are in the arrays
**********************************************************************************/
int readIn(char arrays[], string studentFileName);
/*********************************************************************************
* Function:      void display
* Description:   This function compares the files with each other and displays how
*                many students there were, questions they missed, percentage they 
*                ansered correctly, if they passed or failed, and which student 
*                had the highest and lowest grades.
* Input:         student array, answers array, and the number of students
* Return:        void data type has no return value
**********************************************************************************/
void display(char student[], char answers[], int numStudents);

int main()
{
   // declare/ initialize variables, size declarator constants, and arrays
   string studentFileName = "StudentAnswers.txt";
   string answersFileName = "CorrectAnswers.txt";
   const int STUD_ELEMENTS = 300;
   const int ANS_ELEMENTS = 20;
   char student[STUD_ELEMENTS];
   char answers[ANS_ELEMENTS];
   int numElems = 0;
   int numStudents = 0;

   // function call to read in values from files into the arrays
   readIn(answers, answersFileName);
   numElems = readIn(student, studentFileName);
   // if the function returns -1, the file could not be read so end the program
   if (numElems == -1)
      return 0;

   // the number of students will equal the number of elements read in divided by the number of questions in each test (20)
   numStudents = numElems / 20;

   // function call to compare the arrays and display the student(s) results
   display(student, answers, numStudents);

   cout << endl;
   system("pause");
   return 0;
} // end function main

// this function will attempt to open and read in the file and the file's input into an array
int readIn(char arrays[], string FileName)
{
   // declare input file and initizlize the counter for the array elements to 0
   ifstream inFS;
   int count = 0;

   // open file (if able)
   inFS.open(FileName);

   // if input file cannot be opened or does not exist, display error message and assign false to the result
   if (!inFS) {
      cout << "File \"" << FileName << "\" could not be opened" << endl;
      return -1;
   }

   // if input file can be opened, read in the values into a char array using a while loop
   else {
      while (count < 300 && inFS >> arrays[count])
         count++;
      }
      // close file
      inFS.close();

   // return the amount of elements in the array
   return count;
} // end function readIn

  // this function will display which and how many answers are incorrect by comparing arrays
void display(char student[], char answers[], int numStudents)
{
   // declare output file
   ofstream outFS;

   // open output file
   outFS.open("ExamAnalysis.txt");

   // declare and initialize variables to 0
   int k = 0;
   int m = 0;
   int j = 0;
   int missed = 0;
   double percentage = 0;
   int studentLowest = 1;
   int studentHighest = 1;
   int highestGrade = 0;
   int lowestGrade = 100;

   // this for loop will compare the correct answer array with each of the student's answers in the student array
   for (j = 0; j < numStudents; j++)
   {
      missed = 0;
      cout << endl;
      cout << "Report for Student " << (j + 1) << ":" << endl;
      cout << "---------------------" << endl;
      outFS << endl;
      outFS << "Report for Student " << (j + 1) << ":" << endl;
      outFS << "---------------------" << endl;
      // this loop will run through to determine how many questions the student missed
      for (int i = 0; i < 20; i++, k++) {
         // if the arrays have unequal values, the counter for missed questions will increment
         if (student[k] != answers[i])
            missed++;
      }

   // the percentage 
   percentage = (20 - missed) * 5;
      cout << "Missed " << missed << " out of 20 questions for " << percentage << "% correct." << endl;
      cout << "Questions missed:" << endl << "\t";
      outFS << "Missed " << missed << " out of 20 questions for " << percentage << "% correct." << endl;
      outFS << "Questions missed:" << endl << "\t";
      missed = 0;
      // this for loop will compare the arrays with each other for 20 times
      for (int i = 0; i < 20; i++, m++) {
         // if the arrays have unequal values, the program will display the question and the incorrect and correct answer
         if (student[m] != answers[i]) {
            if (missed != 0)
            {
               cout << ", ";
               outFS << ", ";
            }
            cout << (i + 1) << "(" << student[m] << "/" << answers[i] << ")";
            outFS << (i + 1) << "(" << student[m] << "/" << answers[i] << ")";
            missed++;
         }
      }
      cout << endl;
      outFS << endl;
      // these if statements will output if the student passed or failed
      if (percentage < 70)
      {
         cout << "This student failed the exam" << endl;
         outFS << "This student failed the exam" << endl;
      }
      if (percentage >= 70)
      {
         cout << "This student passed the exam!" << endl;
         outFS << "This student passed the exam!" << endl;
      }

      // these if statements will determine what the lowest grade is and which student it is and assign them to variables
      if (percentage < lowestGrade) {
         lowestGrade = percentage;
         studentLowest = (j + 1);
      }
      if (percentage > highestGrade) {
         highestGrade = percentage;
         studentHighest = (j + 1);
      }
   }

   // display the lowest and highest grades of each student
   cout << endl;
   cout << "Student " << studentHighest << " had the best grade with " << highestGrade << "%." << endl;
   cout << "Student " << studentLowest << " had the worst grade with " << lowestGrade << "%." << endl;
   outFS << endl;
   outFS << "Student " << studentHighest << " had the best grade with " << highestGrade << "%." << endl;
   outFS << "Student " << studentLowest << " had the worst grade with " << lowestGrade << "%." << endl;

   // close output file
   outFS.close();

} // end function display