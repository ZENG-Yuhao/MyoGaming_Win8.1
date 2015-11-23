#pragma once
#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <vector>
using namespace std;

class Score
{
private:
	string first_name;                                // first name
	string last_name;                                 // last name
	int score;                                        // score
	time_t t;                                         // timestamp for start time

public:
	/* constructors */
	Score();
	Score(string first_name, string last_name,
		int score, time_t t);

	/* getters */
	string get_first_name() { return first_name; }
	string get_last_name() { return last_name; }
	int get_score() { return score; }
	time_t get_t() { return t; }

	/* setters */
	void set_first_name(string first_name)
	{
		this->first_name = first_name;
	}
	void set_last_name(string last_name)
	{
		this->last_name = last_name;
	}
	void set_score(int score) { this->score = score; }
	void set_t(time_t t) { this->t = t; }
	Platform::String^ toString();

	static void test();

	/* Other methods */
	Score static parse(string line);                  // parse a line getting from a CSV file
	string static del_gmt(string&);                   // delete guillemet
	friend ostream& operator <<(ostream&, Score);     // operator reload: console output stream
	friend fstream& operator <<(fstream&, Score);     // operator reload: file stream
	friend ofstream& operator <<(ofstream&, Score);   // operator reload: file output stream

};
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);