/*
 * 1182_FoodChain.cpp
 *
 * POJ 1182: Food Chain
 * Find and Union
 * use iostream would TLE
 *
 *  Created on: Sep 2, 2014
 *      Author: Milan Fan
 */

#include <iostream>
//#include <cstdio>

using namespace std;

const int MAX_N = 50000 + 1;
int p[MAX_N];	// parent
int r[MAX_N];	// relationship with parent
				// 0 - same group
				// 1 - eat by parent
				// 2 - eat parent

int find(int x)
{
	if (x == p[x]) return x;
	int t = p[x];
	p[x] = find(p[x]);
	r[x] = (r[x] + r[t]) % 3;	// update the relationship with the new parent
	return p[x];
}

void unite(int d, int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	p[fy] = fx;
	r[fy] = (3 - r[y] + d - 1 + r[x]) % 3;
}

int main()
{
	int N, K;
	int ret = 0;
	int d, x, y;

//	scanf("%d%d", &N, &K);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		p[i] = i;
		r[i] = 0;
	}

	while (K--) {
		cin >> d >> x >> y;
//		scanf("%d%d%d", &d, &x, &y);
		if (x > N || y > N || (x == y && d == 2)) ret++;
		else if (find(x) == find(y)) {
			if (d == 1 && r[x] != r[y]) ret++;
			if (d == 2 && (r[x] + 1) % 3 != r[y]) ret++;

		}
		else unite(d, x, y);
	}
//	printf("%d\n", ret);
	cout << ret << endl;

	return 0;
}
