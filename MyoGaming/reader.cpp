#include "pch.h"
#include "score.h"
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>


int _tmain(int argc)
{

	/* define variables */

	const string filename("scores.csv");                          // file name
	fstream file(filename, ios::app | ios::in);                   // file stream, mode append+input
	Score scores[3];                                              // scores
	scores[0] = Score("Mincong", "Huang", rand() % 101, time(0)); // score 1
	scores[1] = Score("Yuhao", "Zeng", rand() % 101, time(0));    // score 2
	scores[2] = Score("Yuan", "Ji", rand() % 101, time(0));       // score 3


																  /* write content to file */

	cout << "Writing to users.txt ..." << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << scores[i];                                        // out to console

		file << scores[i];                                      // out to file
	}


	/* read content from file */

	string line;
	if (file.is_open())
	{
		cout << "Getting file data ..." << endl;
		while (getline(file, line))
		{
			cout << Score::parse(line);
		}
		file.close();                                             // close
	}
	else
	{
		cout << "Unable to open the file." << endl;
	}


	/* parse test */

	// cout << "parse test" << endl;
	// Score score = Score::parse("\"Mincong\",\"Huang\",\"41\",\"1446470691\";");
	// cout << score;


	/* finished */

	cout << "Finished." << endl;
	cin.ignore();
	return 0;
}

