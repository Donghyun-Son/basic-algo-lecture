#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;

  int len = 'z' - 'a';
  int a[len];
  fill(a, a + len, 0);

  for (char c : s) a[c - 'a']++;
  for (int i = 0; i < len; i++) {
    cout << a[i];
    if (i < len - 1) cout << ' ';
  }
}