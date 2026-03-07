#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  while (T--) {
    int M, N, K;
    cin >> M >> N >> K;
    queue<pair<int, int>> Q;
    bool ground[M][N] = {};
    bool visited[M][N] = {};
    int result = 0;

    while (K--) {
      int x, y;
      cin >> x >> y;
  
      ground[x][y] = true;
    }

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (!ground[i][j] || visited[i][j]) continue;
        Q.push({i, j});
        visited[i][j] = true;
        ++result;
        
        while (!Q.empty()) {
          int a = Q.front().first;
          int b = Q.front().second;

          for (int d = 0; d < 4; d++) {
            int x = a + dx[d];
            int y = b + dy[d];
            if (x < 0 || x >= M || y < 0 || y >= N) continue;
            if (ground[x][y] && !visited[x][y]) {
              Q.push({x, y});
              visited[x][y] = true;
            }
          }
          Q.pop();
        }
      }
    }
    cout << result << "\n";
  }
}