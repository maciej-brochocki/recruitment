// Sample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

bool comp (const pair <string, int>&l, const pair <string, int>&r)
{
	return l.second < r.second;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream file;
	string line, word;
	map <string, int> words;
	map <string, int>::iterator it;

	file.open((argc >= 2 ? argv[1] : "test.txt"), ifstream::in);

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			istringstream iss (line, istringstream::in);

			while (iss.good())
			{
				getline(iss, word, ' ');
				words[word]++;
			}
		}

		file.close();
	}
	else
	{
		cout << "Error opening file" << endl;
	}

	while (words.size())
	{
		it = max_element(words.begin(), words.end(), comp);
		cout << (*it).first << " => " << (*it).second << endl;
		words.erase(it);
	}

	getch();
	return 0;
}
