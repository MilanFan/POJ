/*
 * 2386_LakeCounting.cpp
 *
 * POJ 2386: Lake Counting
 *
 *  Created on: Aug 18, 2014
 *      Author: Milan Fan
 */
#include <iostream>

using namespace std;

int N, M;
const int MAX_N = 100;
const int MAX_M = 100;
char field[MAX_N][MAX_M];

// deep first search
void dfs(int x, int y)
{
	field[x][y] = '.';
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			int nx = x + dx;
			int ny = y + dy;
			if (nx >= 0 && nx < N
					&& ny >= 0 && ny < M
					&& field[nx][ny] == 'W')
				dfs(nx, ny);
		}
	}
}

// solve the problem
void solver()
{
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == 'W') {
				dfs(i, j);
				ret++;
			}
		}
	}
	cout << ret << endl;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> field[i][j];
		}
	}
	solver();
	return 0;
}
