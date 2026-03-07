#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  while (T--) {
    int l, cur_x, cur_y, tar_x, tar_y;
    cin >> l >> cur_x >> cur_y >> tar_x >> tar_y;

    vector<vector<bool>> visited(l, vector<bool>(l, false));
    queue<tuple<int, int, int>> Q;

    Q.push({cur_x, cur_y, 0});
    visited[cur_x][cur_y] = true;

    while (!Q.empty()) {
      int a = get<0>(Q.front());
      int b = get<1>(Q.front());
      int cnt = get<2>(Q.front());
      Q.pop();

      if (a == tar_x && b == tar_y) {
        cout << cnt << "\n";
        break;
      }

      for (int d = 0; d < 8; d++) {
        int x = a + dx[d];
        int y = b + dy[d];

        if (x < 0 || x >= l || y < 0 || y >= l) continue;
        if (visited[x][y]) continue;
        Q.push({x, y, cnt + 1});
        visited[x][y] = true;
      }
    }
  }
}