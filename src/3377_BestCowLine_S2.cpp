/*
 * 3377_BestCowLine_S2.cpp
 * Submit 2: Presentation Error
 *
 * POJ 3377: Best Cow Line
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

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cow[i];
	}

	int head = 0;
	int tail = N - 1;
	while (head <= tail) {
		bool flag = false;
		for (int i = 0; head + i <= tail; i++) {
			if (cow[head + i] < cow[tail - i]) {
				flag = true;
				break;
			} else if (cow[head + i] > cow[tail - i]) {
				flag = false;
				break;
			}
		}
		if (flag) cout << cow[head++];
		else cout << cow[tail--];
	}
	cout << endl;

	return 0;
}


