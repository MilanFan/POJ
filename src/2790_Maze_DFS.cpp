/*
 * 2790_Maze_DFS.cpp
 *
 * OpenJudge 2790: Maze
 * Depth First Search: Accepted
 *
 *  Created on: Aug 18, 2014
 *      Author: Milan Fan
 */

#include <iostream>

using namespace std;

const int MAX_N = 100;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
char grid[MAX_N][MAX_N];
int N;
int ha, la, hb, lb;

bool dfs(int x, int y) {
	if (x == hb && y == lb) return true;
	grid[x][y] = '#';
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N
				&& ny >= 0 && ny < N
				&& grid[nx][ny] != '#') {
			if (dfs(nx, ny)) return true;
		}
	}
	return false;
}

bool solver()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}
	cin >> ha >> la >> hb >> lb;
	if (grid[ha][la] == '#' || grid[hb][lb] == '#') return false;
	if (dfs(ha, la)) return true;
	return false;
}

int main()
{
	int count;
	cin >> count;
	for (int i = 0; i < count; i++) {
		if (solver()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}


