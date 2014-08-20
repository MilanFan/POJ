/*
 * 3069_SarumansArmy.cpp
 *
 * POJ 3069: Saruman's Army
 *
 * Greedy Method
 *
 *  Created on: Aug 20, 2014
 *      Author: Milan Fan
 */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_R = 1000;
const int MAX_N = 1000;
const int MAX_X = 1000;
int R, N;
int x[MAX_N];

int solver()
{
	sort(x, x + N);
	int ret = 0;
	int pos = 0;
	while (pos < N){
		int nxt = pos;
		while(x[nxt] - x[pos] <= R && nxt < N) nxt++;
		ret++;
		pos = nxt - 1;
		while(x[nxt] - x[pos] <= R && nxt < N) nxt++;
		pos = nxt;
	}

	return ret;
}

int main()
{
	while (true) {
		cin >> R >> N;
		if (R < 0 || N < 0) break;
		for (int i = 0; i < N; i++)
			cin >> x[i];
		cout << solver() << endl;
	}

	return 0;
}


