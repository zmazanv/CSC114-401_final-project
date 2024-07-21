/*
 * Sebastián Zavala Villagómez
 * Delaware Technical Community College
 * CSC114-401 Computer Science I
 * Exam 4 / Final Project for CSC114
 * 2024-07-21
 */

#include <fstream>
#include <iostream>
#include <sstream>

const int g_STUDENT_COUNT = 10;
const int g_COURSE_COUNT = 5;

void parse_student_names(const std::string &FILENAME,
			 std::string students[g_STUDENT_COUNT])
{
	int c = 0;
	std::string line;
	std::ifstream file(FILENAME);

	if (!file.is_open()) {
		std::cerr << "File '" << FILENAME
			  << "' could not be opened. Exiting..." << std::endl;

		std::exit(-1);
	}

	while (std::getline(file, line) && c < g_STUDENT_COUNT)
		students[c++] = line;

	file.close();
}

void parse_exam_scores(const std::string &FILENAME,
		       int exam_scores[g_STUDENT_COUNT][g_COURSE_COUNT])
{
	int c = 0;
	std::string line;
	std::string word;
	std::ifstream file(FILENAME);

	if (!file.is_open()) {
		std::cerr << "File '" << FILENAME
			  << "' could not be opened. Exiting..." << std::endl;

		std::exit(-1);
	}

	while (std::getline(file, line) && c < g_STUDENT_COUNT) {
		int cc = 0;
		std::stringstream str(line);

		while (std::getline(str, word, ',') && cc < g_COURSE_COUNT)
			exam_scores[c][cc++] = stoi(word);

		++c;
	}

	file.close();
}

char calculate_grade(const int INDEX,
		     int exam_scores[g_STUDENT_COUNT][g_COURSE_COUNT])
{
	if (INDEX < 0 || INDEX >= g_STUDENT_COUNT) {
		std::cerr << "Passed index '" << INDEX
			  << "' is out of bounds for student count. Exiting..."
			  << std::endl;

		std::exit(-1);
	}

	char grade;
	int sum = 0;
	double average = 0.0;

	for (int i = 0; i < g_COURSE_COUNT; ++i) {
		sum += exam_scores[INDEX][i];
	}

	average = static_cast<double>(sum) / g_COURSE_COUNT;

	if (average >= 90)
		return 'A';
	else if (average >= 80)
		return 'B';
	else if (average >= 70)
		return 'C';

	return 'F';
}

void write_results(const std::string &FILENAME, const std::string &STUDENT_NAME,
		   const char GRADE)
{
	std::ofstream file(FILENAME, std::ios::app);

	if (!file.is_open()) {
		std::cerr << "File '" << FILENAME
			  << "' could not be opened. Exiting..." << std::endl;

		std::exit(-1);
	}

	file << STUDENT_NAME << ": " << GRADE << std::endl;

	file.close();
}

int main()
{
	std::string students[g_STUDENT_COUNT];
	int exam_scores[g_STUDENT_COUNT][g_COURSE_COUNT];

	parse_student_names("studentNames.txt", students);
	parse_exam_scores("scores.txt", exam_scores);

	for (int i = 0; i < g_STUDENT_COUNT; ++i) {
		write_results("grades.txt", students[i],
			      calculate_grade(i, exam_scores));
	}

	return 0;
}
