#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M, cnt = 0;
  cin >> N >> M;

  deque<int> DQ;
  for (int i = 1; i <= N; i++) DQ.push_back(i);

  while (M--) {
    int target;
    cin >> target;

    int idx = find(DQ.begin(), DQ.end(), target) - DQ.begin();
    bool left = idx <= (int)DQ.size() / 2;

    while (DQ.front() != target) {
      if (left) {
        DQ.push_back(DQ.front());
        DQ.pop_front();
      }
      else {
        DQ.push_front(DQ.back());
        DQ.pop_back();
      }
      cnt++;
    }
    DQ.pop_front();
  }

  cout << cnt;
}