#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  stack<pair<int, int>> S;

  for (int i = 1; i <= N; i++) {
    int height;
    cin >> height;

    while (!S.empty() && S.top().first < height) S.pop();

    if (S.empty()) cout << 0;
    else cout << S.top().second;

    if (i < N) cout << " ";

    S.push({height, i});
  }
}
