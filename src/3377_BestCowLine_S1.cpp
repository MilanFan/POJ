/*
 * 3377_BestCowLine_S1.cpp
 *
 * POJ 3377: Best Cow Line
 * Submit 1: Wrong Answer ...
 *
 *  Created on: Aug 19, 2014
 *      Author: Milan Fan
 */

#include <iostream>

using namespace std;

const int MAX_N = 30000;

int main()
{
	int N;
	char cow[MAX_N];
	char ans[MAX_N];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cow[i];
	}

	int head = 0;
	int tail = N - 1;
	for (int pos = 0; pos < N; pos++) {
		int flag = 0;
		int h = head;
		int t = tail;
		while (h < t) {
			if (cow[h] != cow[t]) {
				flag = cow[h] < cow[t] ? -1 : 1;
				break;
			}
			h++;
			t--;
		}
		if (flag <= 0) ans[pos] = cow[head++];
		else ans[pos] = cow[tail--];
	}

	cout << ans << endl;

	return 0;
}


