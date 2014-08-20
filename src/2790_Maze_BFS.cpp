/*
 * 2790_Maze_BFS.cpp
 *
 * OpenJudge 2790: Maze
 * Breadth First Search: Memory Limit Exceeded
 *
 *  Created on: Aug 18, 2014
 *      Author: Milan Fan
 */

#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> MazeNode;

const int MAX_N = 100;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

bool bfs() {
	char grid[MAX_N][MAX_N];
	queue<MazeNode> q;
	int N;
	int ha, la, hb, lb;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}
	cin >> ha >> la >> hb >> lb;
	if (grid[ha][la] == '#' || grid[hb][lb] == '#') return false;

	q.push(MazeNode(ha, la));
	while (q.size()) {
		MazeNode p = q.front();
		q.pop();
		if (p.first == hb && p.second == lb) return true;
		grid[p.first][p.second] = '#';
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if (nx >= 0 && nx < N
					&& ny >= 0 && ny < N
					&& grid[nx][ny] != '#')
				q.push(MazeNode(nx, ny));
		}
	}

	return false;
}

int main()
{
	int count;
	cin >> count;
	for (int i = 0; i < count; i++) {
		if (bfs()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}


