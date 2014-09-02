/*
 * 3253_FenceRepair_Heap.cpp
 *
 * POJ 3253: Fence Repair
 *
 * use heap
 * To be noted: use long long for the sum
 *
 *  Created on: Sept 2, 2014
 *      Author: Milan Fan
 */

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int N;
	long long ret = 0;
	priority_queue<int, vector<int>, greater<int> > q;	// declare min heap

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}

	while (q.size() > 2) {
		int l1 = q.top();
		q.pop();
		int l2 = q.top();
		q.pop();
		q.push(l1 + l2);
		ret += l1 + l2;
	}
	if (N < 2) ret = q.top();
	else {
		int l1 = q.top();
		q.pop();
		int l2 = q.top();
		ret += l1 + l2;
	}
	cout << ret << endl;

	return 0;
}


