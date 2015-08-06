/*
 * 3781_NthLargestValue.cpp
 * 
 * POJ 2386: Nth Largest Value
 *
 *  Created on: Jul 28, 2015
 *      Author: Milan Fan
 */

#include <iostream>
using namespace std;

#define MAX_P 1000
#define MAX_N 10
#define N 10
#define K 3

void swap(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int sort(int a[], int size, int pivot)
{
	int c = 0;

	for (int i = 0; i < size; i++) {
		if (a[i] >= pivot) {
			if (i != c) {
				swap(a[c], a[i]);
			}
			c++;
		}
	}
	return c;
}

int findKthLargest(int a[], int size)
{
	int count = 0;
	int pivot = a[0];

	while (count < K) {
		int c = sort(a + count, size, pivot);
		if (c + count < K) {
			count += c;
			size -= c;
			pivot = a[count];
		} else if (c + count > K) {
			size = c;
			pivot = a[count + 1];
		} else {
			break;
		}
	}
	return pivot;
}

int main()
{
	int P;
	int a[MAX_N];
	int idx;

	cin >> P;
	if (P < 1 || P > MAX_P) return 0;

	for (int i = 0; i < P; i++) {
		cin >> idx;
		for (int j = 0; j < N; j++)
			cin >> a[j];
		cout << idx << " " << findKthLargest(a, N) << endl;
	}

	return 0;
}



