#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int K, num;
  int ans = 0;
  cin >> K;

  stack<int> S;

  while (K--) {
    cin >> num;
    if (num != 0) S.push(num);
    else S.pop();
  }

  while (!S.empty()) {
    ans += S.top();
    S.pop();
  }

  cout << ans;
}