#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string num;
  int max_val;
  int cnt[10] = {};
  cin >> num;

  for (char c : num) cnt[c - '0']++;

  cnt[6] = (cnt[6] + cnt[9] + 1) / 2;
  cnt[9] = 0;
  max_val = *max_element(cnt, cnt + 10);
  cout << max_val;
}