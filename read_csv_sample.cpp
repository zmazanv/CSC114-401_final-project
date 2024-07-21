

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int STUDENTNUM = 2;
const int COURSENUM = 5;

int main()
{
	string fname;
	cout << "Enter the file name: ";
	cin >> fname;
	string line, word;
	int score[STUDENTNUM][COURSENUM];

	fstream file(fname, ios::in);
	if (file.is_open())
	{
		int rw = 0;
		while (getline(file, line))
		{

			//row.clear();
			int cl = 0;

			stringstream str(line);

			while (getline(str, word, ','))
			{
				score[rw][cl++] = stoi(word);

			}

			rw++;
		}
	}
	else
		cout << "Could not open the file\n";


	for (int i = 0; i < STUDENTNUM; i++)
	{
		for (int j = 0; j < COURSENUM; j++)
		{
			cout << score[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

