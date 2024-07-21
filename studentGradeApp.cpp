/*
 * Sebastián Zavala Villagómez
 * CSC114-401 Computer Science I
 * Final Project
 * 2024-07-21

 * Exam 4 / Final Project for CSC114
 * Delaware Technical Community College
 * Starter Code
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int STUDENTNUM = 10;
const int COURSENUM = 5;

/*
The data for the students and grades will be stored in parallel arrays.
The studentNames array holds each student's name
The scores 2 dimensional array holds each student's scores.
- The first dimension corresponds to each student, so it matches up with the studentNames array based on index
- The second dimension is for each individual score.
The grades array will hold the final calculated letter grade for each student based on the average of the scores on the scores array.
*/

// Function prototypes
/*
This function should fill the scores integer 2d array with student scores
*/
void readScoreData(string, int[STUDENTNUM][COURSENUM]);

/*
This function should fill the studentNames string array with student names
*/
void readStudentNames(string, string[STUDENTNUM]);

/*
This function will calculate the average for each student and fill the grades char array with the corresponding letter grade.
90-100: A
80-99: B
70-79: C
0-69: F
*/
void calcualteGrade(char[STUDENTNUM], int[STUDENTNUM][COURSENUM]);

/*
This function will save each student name and letter grade to a file.
*/
void saveGrade(string, string[STUDENTNUM], char[STUDENTNUM]);

int main()
{
	string studentNames[STUDENTNUM];
	int scores[STUDENTNUM][COURSENUM];
	char grades[STUDENTNUM];

	readStudentNames("studentNames.txt", studentNames);
	readScoreData("scores.txt", scores);
	calcualteGrade(grades, scores);
	saveGrade("grades.txt", studentNames, grades);
	return 0;
}

void readScoreData(string filename, int Scores[STUDENTNUM][COURSENUM])
{
}
void readStudentNames(string filename, string names[STUDENTNUM])
{
}
void calcualteGrade(char Grade[STUDENTNUM], int Scores[STUDENTNUM][COURSENUM])
{
}

void saveGrade(string filename, string names[STUDENTNUM],
	       char Grades[STUDENTNUM])
{
}
