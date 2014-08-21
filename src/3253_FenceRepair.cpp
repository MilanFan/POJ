/*
 * 3253_FenceRepair.cpp
 *
 * POJ 3253: Fence Repair
 *
 * Greedy Method: Huffman code
 * To be noted: use long long for the sum
 *
 *  Created on: Aug 20, 2014
 *      Author: Milan Fan
 */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 20000;

int main()
{
	int N;
	int l[MAX_N];
	long long ret = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> l[i];
	}

	int count = N;
	while (count > 2) {
		if (l[0] > l[1]) swap(l[0], l[1]);
		for (int i = 2; i < count; i++) {
			if (l[i] < l[1]) {
				swap(l[1], l[i]);
				if (l[0] > l[1]) swap(l[0], l[1]);
			}
		}
		l[1] += l[0];
		l[0] = l[--count];
		ret += l[1];
	}
	if (N < 2) ret = l[0];
	else ret += l[0] + l[1];
	cout << ret << endl;

	return 0;
}


