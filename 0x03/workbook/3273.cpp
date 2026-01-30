#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int len, x;
  cin >> len;
  int seq[len];
  int ans = 0;
  unordered_map <int, int> cnt;

  for (int i = 0; i < len; i++) cin >> seq[i];
  cin >> x;

  for (int val : seq) cnt[val]++;
  for (int val : seq) {
    if (cnt[x - val] < 1 || cnt[val] < 1) continue;
    if (x == val * 2 && cnt[val] < 2) continue;
    ans += 1;
    cnt[val]--;
    cnt[x - val]--;
  }

  cout << ans;
}