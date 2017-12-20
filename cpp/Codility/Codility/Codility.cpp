#include "stdafx.h"

// you can use includes, for example:
#include <algorithm>
#include <map>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

/*-------------------------------------------------------------------------------------------------------------*/

int callDuration(int h, int m, int s)
{
	return s + 60 * m + 3600 * h;
}

int callCost(int duration)
{
	int m = duration / 60;
	int s = duration % 60;
	if (m < 5)
	{
		return duration * 3;
	}
	else
	{
		return s ? (m + 1) * 150 : m * 150;
	}
}

struct Number {
	int cost;
	int duration;
};

bool compare(const pair<int, struct Number>& n1, const pair<int, struct Number>& n2)
{
	if (n1.second.duration == n2.second.duration) return n1.second.cost > n2.second.cost;
	return n1.second.duration < n2.second.duration;
}

int solution1(string &S) {
	// write your code in C++14 (g++ 6.2.0)
	istringstream iss(S);
	int h, m, s, n1, n2, n3, n;
	char c;
	map<int, struct Number> numbers;

	while (iss.good())
	{
		iss >> h; iss >> c;
		iss >> m; iss >> c;
		iss >> s; iss >> c;
		iss >> n1; iss >> c;
		iss >> n2; iss >> c;
		iss >> n3; iss >> c;
		n = 1000000 * n1 + 1000 * n2 + n3;
		struct Number call;
		call.duration = callDuration(h, m, s);
		call.cost = callCost(call.duration);
		if (numbers.find(n) == numbers.end())
		{
			numbers[n] = call;
		}
		else
		{
			numbers[n].duration += call.duration;
			numbers[n].cost += call.cost;
		}
	}

	int bill = 0;

	map<int, struct Number>::iterator it;
	for (it = numbers.begin(); it != numbers.end(); it++)
	{
		bill += it->second.cost;
	}

	pair<int, struct Number> promotion = *max_element(numbers.begin(), numbers.end(), compare);
	bill -= promotion.second.cost;

	return bill;
}

/*-------------------------------------------------------------------------------------------------------------*/

void walk(vector< vector<int> > &A, vector< vector<int> > &walked, int i, int j, int M, int N, int countries) {
	if (i < N - 1)
	{
		if ((walked[i + 1][j] == 0) && (A[i][j] == A[i + 1][j]))
		{
			walked[i + 1][j] = countries;
			walk(A, walked, i + 1, j, M, N, countries);
		}
	}
	if (i > 0)
	{
		if ((walked[i - 1][j] == 0) && (A[i][j] == A[i - 1][j]))
		{
			walked[i - 1][j] = countries;
			walk(A, walked, i - 1, j, M, N, countries);
		}
	}
	if (j < M - 1)
	{
		if ((walked[i][j + 1] == 0) && (A[i][j] == A[i][j + 1]))
		{
			walked[i][j + 1] = countries;
			walk(A, walked, i, j + 1, M, N, countries);
		}
	}
	if (j > 0)
	{
		if ((walked[i][j - 1] == 0) && (A[i][j] == A[i][j - 1]))
		{
			walked[i][j - 1] = countries;
			walk(A, walked, i, j - 1, M, N, countries);
		}
	}
}

int solution2(vector< vector<int> > &A) {
	// write your code in C++14 (g++ 6.2.0)
	int N = A.size();
	int M = A[0].size();
	int countries = 0;

	vector<int> empty(M, 0);
	vector< vector<int> > walked(N, empty);

	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			if (walked[i][j] == 0) {
				walked[i][j] = ++countries;
				walk(A, walked, i, j, M, N, countries);
			}
		}
	}

	return countries;
}

/*-------------------------------------------------------------------------------------------------------------*/

struct Point2D {
	int x;
	int y;
};

int counterClockWise(Point2D p1, Point2D p2, Point2D p3)
{
	return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
}

int minYX(Point2D p1, Point2D p2)
{
	if (p1.y == p2.y) return p1.x<p2.x;
	return p1.y<p2.y;
}

int angle(Point2D p1, Point2D p2)
{
	return p1.y*p2.x < p2.y*p1.x;
}

int solution3(vector<Point2D> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int N = A.size();
	iter_swap(A.begin(), min_element(A.begin(), A.end(), minYX));
	sort(A.begin() + 1, A.end(), angle);
	A.push_back(A[0]);
	int M = 1;
	for (int i = 2; i<N + 1; i++)
	{
		while (counterClockWise(A[M - 1], A[M], A[i]) <= 0)
		{
			if (M > 1)
			{
				M -= 1;
				continue;
			}
			else if (i == N)
			{
				break;
			}
			else
			{
				i++;
			}
		}

		M++;
		iter_swap(A.begin() + M, A.begin() + i);
	}
	return M;
}

int main()
{
	string test1("00:01:07,400-234-090\n00:05:01,701-080-080\n00:05:00,400-234-090");
	cout << solution1(test1) << endl;

	vector<int> v1 = { 5, 4, 4 };
	vector<int> v2 = { 4, 3, 4 };
	vector<int> v3 = { 3, 2, 4 };
	vector<int> v4 = { 2, 2, 2 };
	vector<int> v5 = { 3, 3, 4 };
	vector<int> v6 = { 1, 4, 4 };
	vector<int> v7 = { 4, 1, 1 };
	vector< vector<int> > test2 = { v1, v2, v3, v4, v5, v6, v7 };
	cout << solution2(test2) << endl;

	Point2D A[6];
	A[0].x = 3;   A[0].y = 2;
	A[1].x = 6;   A[1].y = 3;
	A[2].x = 2;   A[2].y = 5;
	A[3].x = 5;   A[3].y = 2;
	A[4].x = 1;   A[4].y = 1;
	A[5].x = 4;   A[5].y = 4;
	vector<Point2D> test3;
	for (int i = 0; i < 6; i++)
		test3.push_back(A[i]);
	cout << solution3(test3) << endl;

	return 0;
}
