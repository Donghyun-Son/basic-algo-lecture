#include <bits/stdc++.h>
using namespace std;

int M, N, H;
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> M >> N >> H;

  vector<vector<vector<int>>> tomatoes(M, vector<vector<int>>(N, vector<int>(H, 0)));
  queue<tuple<int, int, int, int>> Q;

  for (int k = 0; k < H; k++) {
    for (int j = 0; j < N; j++) {
      for (int i = 0; i < M; i++) {
        int tomato;
        cin >> tomato;
        tomatoes[i][j][k] = tomato;
        if (tomato == 1) Q.push({i, j, k, 0});
      }
    }
  }

  int max_day = 0;
  while (!Q.empty()) {
    int a = get<0>(Q.front());
    int b = get<1>(Q.front());
    int c = get<2>(Q.front());
    int day = get<3>(Q.front());
    Q.pop();

    for (int d = 0; d < 6; d++) {
      int x = a + dx[d];
      int y = b + dy[d];
      int z = c + dz[d];
      if (x < 0 || x >= M || y < 0 || y >= N || z < 0 || z >= H) continue;
      if (tomatoes[x][y][z] != 0) continue;
      tomatoes[x][y][z] = 1;
      Q.push({x, y, z, day + 1});
      max_day = day + 1;
    }
  }

  for (int k = 0; k < H; k++)
    for (int j = 0; j < N; j++)
      for (int i = 0; i < M; i++)
        if (tomatoes[i][j][k] == 0) { cout << -1; return 0; }

  cout << max_day;
}