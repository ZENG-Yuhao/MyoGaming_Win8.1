#include "pch.h"
#include "score.h"
#include "gamepage_var.h"
using namespace std;

Score::Score()
{
	this->first_name = "";
	this->last_name = "";
	this->score = 0;
	this->t = time(0);
}
Score::Score(string first_name, string last_name, int score, time_t t)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->score = score;
	this->t = t;
}

Platform::String^ Score::toString()
{
	return "hi";
}
Score Score::parse(string line)
{
	string::size_type sz;                               // alias of size_t
	vector<string> items = split(line, ',');

	// print content of each item
	// for (auto i = items.begin(); i != items.end(); ++i)
	//	cout << *i << endl;

	// delete guillmet
	string first_name = Score::del_gmt(items.at(0));    // first name
	string last_name = Score::del_gmt(items.at(1));     // last name
	string score_str = Score::del_gmt(items.at(2));     // score
	int score = stoi(score_str, &sz);
	string t_str = Score::del_gmt(items.at(3));         // timestamp
	long t_long = stol(t_str, &sz);
	time_t t = (time_t)t_long;

	// construct than return
	return Score(first_name, last_name, score, t);
}
string Score::del_gmt(string &raw)
{
	vector<string> items = split(raw, '\"');
	return items[1];
}
ostream& operator <<(ostream& out, Score s)
{
	struct tm t;                                         // time info
	localtime_s(&t, &s.t);                               // convert timestamp to time info
	out << "The score of " << s.first_name << " "
		<< s.last_name << " is " << s.score
		<< ", played at " << (t.tm_year + 1900) << "-"
		<< (t.tm_mon + 1) << "-" << t.tm_mday << "."
		<< endl;
	return out;
}
ofstream& operator <<(ofstream& out, Score s)
{
	/* CSV file style */
	out << "\"" << s.first_name << "\","
		<< "\"" << s.last_name << "\","
		<< "\"" << s.score << "\","
		<< "\"" << s.t << "\";\n";
	return out;
}
fstream& operator <<(fstream& out, Score s)
{
	/* CSV file style */
	out << "\"" << s.first_name << "\","
		<< "\"" << s.last_name << "\","
		<< "\"" << s.score << "\","
		<< "\"" << s.t << "\";\n";
	return out;
}
// StackOverflow: Split a string in C++?
// http://stackoverflow.com/a/236803
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems)
{
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim))
	{
		elems.push_back(item);
	}
	return elems;
}
std::vector<std::string> split(const std::string &s, char delim)
{
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}


