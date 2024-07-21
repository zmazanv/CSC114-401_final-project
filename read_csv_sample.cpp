

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const int STUDENTNUM = 2;
const int COURSENUM = 5;

int main()
{
	std::string fname;
	std::cout << "Enter the file name: ";
	std::cin >> fname;
	std::string line, word;
	int score[STUDENTNUM][COURSENUM];

	std::fstream file(fname, std::ios::in);
	if (file.is_open()) {
		int rw = 0;
		while (getline(file, line)) {
			//row.clear();
			int cl = 0;

			std::stringstream str(line);

			while (getline(str, word, ',')) {
				score[rw][cl++] = stoi(word);
			}

			rw++;
		}
	} else
		std::cout << "Could not open the file\n";

	for (int i = 0; i < STUDENTNUM; i++) {
		for (int j = 0; j < COURSENUM; j++) {
			std::cout << score[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}
