/*
 * 3617_BestCowLine.cpp
 *
 * POJ 3617: Best Cow Line (OpenJudge 3377)
 * To be noted: max # of chars per line to output is 80
 *
 *  Created on: Aug 19, 2014
 *      Author: Milan Fan
 */

#include <iostream>

using namespace std;

const int MAX_N = 2000;

int main()
{
	int N;
	char cow[MAX_N];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cow[i];
	}

	int head = 0;
	int tail = N - 1;
	for (int count = 1; count <= N; count++) {
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
		if (flag <= 0) cout << cow[head++];
		else cout << cow[tail--];
		if (count % 80 == 0) cout << endl;
	}
	cout << endl;

	return 0;
}


