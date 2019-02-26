//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;
/*
	1. The robot is always dropped on an empty cell. 
		It has in its memory a map of the whole field but it does not know where it is on that map.
	2. However, it can scan the surroundings and try to map the view to a spot on the map.
	3. The robot has the goal to reach a given cell, which is always empty. 
	It needs to compute the length of the shortest path in terms of cells 
		(including the start and final ones) from its start cell to the final cell.
	4. It is possible that there are more than one cells on the map, which have the same surrounding as what the robot sees. 
		In such a case it should return the most pessimistic answer it can find.
	5. It is also possible that no cell on the map corresponds to what the robot sees. 
		In such cases it should return the number -1.
	6. If the robot matches one or more possible starting locations on the 
		map but from at least one of them there is no path to the final cell it must return -2.
	7. The surroundings that the robot sees will be presented as a smaller rectangle with empty and occupied cells.
	8. The field can be at most 1000 by 1000 cells big. 
		The surroundings rectangle's size will be at most 16 by 16 cells and it will never be bigger than the map.
	9. The input will be read from the standard input and will contain 4 numbers on the first line: N, M, P, Q, where:
N - number of rows in the map
M - number of columns in the map
P - number of rows in the surroundings
Q - number of columns in the surroundings
	10. The second line will contain two integers: X and Y, the row and column of the destination cell.
	11. Rows and columns are numbered starting from 1 at the top and at the left correspondingly.
SAMPLE INPUT

6 10 2 3
4 9
0100000000
1000000000
0000000000
0010000000
0000000000
0000000000
010
102
SAMPLE OUTPUT

8
*/

struct Pos {
  int x, y;
  int d;
  bool operator==(const Pos &that) const {
    return x == that.x && y == that.y;
  }
};
int n, m, p, q;
Pos s, f;

int bfs(const vector<string> &g, int x, int y)
{
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  queue<Pos> q;
  q.push(Pos{x, y, 0});
  while (!q.empty()) {
    Pos p = q.front();
    q.pop();
    if (p == f) return p.d;
    if (visited[p.x][p.y]) continue;
    visited[p.x][p.y] = true;
    int offset[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < 4; i++) {
      int x = p.x + offset[i][0];
      int y = p.y + offset[i][1];
      if (x < 0 || y < 0 || x >= n || y >= m || visited[x][y] || g[x][y] == '1') continue;
      q.push(Pos{x, y, p.d + 1});
    }
  }
  return -1;
}

int solve(const vector<string> &g, const vector<string> &pos)
{
  int maxlen = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bool ok = true;
      for (int k = 0; ok && k < p; k++) {
        for (int l = 0; ok && l < q; l++) {
          if (i+k >= n || j+l >= m || g[i+k][j+l] != pos[k][l]) ok = false;
        }
      }
      if (!ok) continue;
      int len = bfs(g, s.x + i, s.y + j);
      // cerr << s.x+i << "," << s.y+j << "=" << len << endl;
      if (len < 0) return -2;
      maxlen = max(maxlen, len);
    }
  }
  return maxlen;
}

int main()
{
    cin >> n >> m >> p >> q >> f.x >> f.y;
    f.x--; f.y--;
    vector<string> g(n);
    vector<string> pos(p);
    for (int i = 0; i < n; i++) {
      cin >> g[i];
    }
    for (int i = 0; i < p; i++) {
      cin >> pos[i];
      for (int j = 0; j < q; j++) {
        if (pos[i][j] == '2') {
          s.x = i;
          s.y = j;
          pos[i][j] = '0';
        }
      }
    }
    cout << solve(g, pos) << endl;
    return 0;
}



