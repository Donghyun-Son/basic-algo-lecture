#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char blind(char c, bool blindness) {
  return (blindness && c == 'G') ? 'R' : c;
}

int bfs(int N, vector<string>& area, bool blindness) {
  int num = 0;
  bool visited[N][N] = {};
  queue<pair<int, int>> Q;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (visited[i][j]) continue;
      char find = blind(area[i][j], blindness);
      Q.push({i, j});
      visited[i][j] = true;
      num++;

      while (!Q.empty()) {
        int a = Q.front().first;
        int b = Q.front().second;
        Q.pop();
        for (int d = 0; d < 4; d++) {
          int x = a + dx[d];
          int y = b + dy[d];
          if (x < 0 || x >= N || y < 0 || y >= N) continue;
          if (blind(area[x][y], blindness) == find && !visited[x][y]) {
            Q.push({x, y});
            visited[x][y] = true;
          }
        }
      }
    }
  }
  return num;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  vector<string> area;

  int n = N;
  while (n--) {
    string line;
    cin >> line;
    area.push_back(line);
  }

  cout << bfs(N, area, false) << " ";
  cout << bfs(N, area, true);
}