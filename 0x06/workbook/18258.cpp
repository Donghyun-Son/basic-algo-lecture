#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  queue<int> Q;

  while (N--) {
    string cmd;
    cin >> cmd;

    if (cmd == "push") {
      int value;
      cin >> value;
      Q.push(value);
    }
    else if (cmd == "size") cout << Q.size() << "\n";
    else if (cmd == "empty") cout << int(Q.empty()) << "\n";
    else if (cmd == "front") cout << (Q.empty() ? -1 : Q.front()) << "\n";
    else if (cmd == "back") cout << (Q.empty() ? -1 : Q.back()) << "\n";
    else if (cmd == "pop") {
      cout << (Q.empty() ? -1 : Q.front()) << "\n";
      if (!Q.empty()) Q.pop();
    }
  }
}