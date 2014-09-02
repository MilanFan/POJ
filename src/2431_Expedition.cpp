/*
 * 2431_Expedition.cpp
 *
 * POJ 2431: Expedition
 * Hint: use heap, sort input, pay attention to boundary conditions
 *
 *  Created on: Sep 1, 2014
 *      Author: Milan Fan
 */

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 10000;

struct Stop {
	long dist;	// distance to START
	long fuel;	// fuel in tank
};

bool cmp(const Stop &s1, const Stop &s2)
{
	return s1.dist < s2.dist;	// ascending
}

int main()
{
	int N;
	long L, P;
	Stop s[MAX_N + 1];
	priority_queue<int> q;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s[i].dist >> s[i].fuel;
	}
	cin >> L >> P;
	for (int i = 0; i < N; i++) s[i].dist = L - s[i].dist;
	sort(s, s + N, cmp);
	s[N].dist = L;
	s[N].fuel = 0;

	long pos = 0;
	long tank = P;
	int ret = 0;
	for (int i = 0; i <= N; i++) {
		tank -= s[i].dist - pos;
		while (tank < 0) {
			if (q.empty()) {
				cout << -1 << endl;
				return 0;
			}
			tank += q.top();
			q.pop();
			ret++;
		}
		pos = s[i].dist;
		q.push(s[i].fuel);
	}
	cout << ret << endl;

	return 0;
}
