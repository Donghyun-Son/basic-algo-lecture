#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, num, i = 1;
  cin >> n;
  stack<int> S;
  string ans;

  while (n--) {
    cin >> num;
    while (i <= num) {
      S.push(i++);
      ans += "+\n";
    }
    if (S.top() != num) {
      cout << "NO";
      return 0;
    }
    S.pop();
    ans += "-\n";
  }
  cout << ans;
}
