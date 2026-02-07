#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  string cmd;
  stack<int> S;

  while (N--) {
    cin >> cmd;
    if (cmd == "push") {
      int x;
      cin >> x;
      S.push(x);
    }
    else if (cmd == "pop" || cmd == "top") {
      if (S.empty()) cout << -1;
      else {
        cout << S.top();
        if (cmd == "pop") S.pop();
      }
    }
    else if (cmd == "size") cout << S.size();
    else if (cmd == "empty") cout << int(S.empty());
    
    if (cmd != "push") cout << "\n";
  }
}