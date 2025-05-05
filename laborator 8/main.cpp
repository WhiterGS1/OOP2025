#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;

class Compare {
public:
	bool operator() (pair<string, int> p1, pair<string, int> p2) {
		if (p1.second < p2.second)
			return true;
		if (p1.second > p2.second)
			return false;
		if (p1.first < p2.first)
			return false;
		return true;
	}
};


int main()
{
	string str;
	string::iterator strit;
	string word;
	string::iterator wordit;
	map<string, int> m;
	getline(cin, str);
	int i,j=0;
	for (strit=str.begin(); strit!= str.end(); strit++)
	{
		if (*strit == '!' || *strit == ' ' || *strit == ',' || *strit == '?')
		{
			if (!word.empty())
			{
				if (m.count(word) != 0)
					m[word]++;
				else
					m[word] = 1;
			}
			word.clear();
			wordit = word.begin();
		}
		else
		{
		if (*strit >= 'A' && *strit <= 'Z')
			word += *strit + 32;
		else
			word += *strit;
		}
	}
	if (!word.empty())
	{
		if (m.count(word) != 0)
			m[word]++;
		else
			m[word] = 1;
	}
	word.clear();
	wordit = word.begin();

	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> queue;

	for (auto mapit = m.begin(); mapit != m.end(); mapit++)
	{
		queue.push(pair<string, int>(mapit->first, mapit->second));
	}
	while (!queue.empty())
	{
		printf("%s | %d\n", queue.top().first.c_str(), queue.top().second);
		queue.pop();
	}
}