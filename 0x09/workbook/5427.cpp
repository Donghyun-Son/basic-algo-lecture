#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  
  while (T--) {
    int w, h;
    cin >> w >> h;
    vector<string> building(h);
    vector<vector<int>> fire(h, vector<int>(w, INT_MAX));
    vector<vector<int>> visited(h, vector<int>(w, INT_MAX));
    queue<tuple<int, int, int, bool>> Q;

    for (int i = 0; i < h; i++) cin >> building[i];

    int sx, sy;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (building[i][j] == '*') {
          Q.push({i, j, 0, false});
          fire[i][j] = 0;
        }
        else if (building[i][j] == '@') {
          sx = i, sy = j;
        }
      }
    }

    Q.push({sx, sy, 0, true});
    visited[sx][sy] = 0;

    int ans = -1;
    bool done = false;
    while (!Q.empty() && !done) {
      int cx = get<0>(Q.front());
      int cy = get<1>(Q.front());
      int time = get<2>(Q.front());
      bool human = get<3>(Q.front());
      Q.pop();

      for (int d = 0; d < 4 && !done; d++) {
        int nx = cx + dx[d];
        int ny = cy + dy[d];

        if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
          if (human) { ans = time + 1; done = true; break; }
          continue;
        }
        if (building[nx][ny] == '#') continue;
        if (human) {
          if (visited[nx][ny] <= time || fire[nx][ny] <= time + 1) continue;
          visited[nx][ny] = time + 1;
          Q.push({nx, ny, time + 1, true});
        }
        else {
          if (fire[nx][ny] <= time) continue;
          fire[nx][ny] = time + 1;
          Q.push({nx, ny, time + 1, false});
        }
      }
    }
    cout << (ans == -1 ? "IMPOSSIBLE" : to_string(ans)) << "\n";
  }
}