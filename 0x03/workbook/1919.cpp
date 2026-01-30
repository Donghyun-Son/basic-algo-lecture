#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  int ans = 0;
  cin >> a >> b;

  int len = 'z' - 'a' + 1;
  vector<int> cnt(len);
  
  for (char c : a) cnt[c - 'a']++;
  for (char c : b) cnt[c - 'a']--;
  for (int i = 0; i < len; i++) ans += abs(cnt[i]);

  cout << ans;
}