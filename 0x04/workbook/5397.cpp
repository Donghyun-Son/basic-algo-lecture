#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  while (N--) {
    string keylog;
    cin >> keylog;

    list<char> L;
    auto cur = L.end();

    for (char c : keylog) {
      switch (c) {
        case '<':
          if (cur != L.begin()) --cur;
          break;
        case '>':
          if (cur != L.end()) ++cur;
          break;
        case '-':
          if (cur != L.begin()) cur = L.erase(prev(cur));
          break;
        default:
          L.insert(cur, c);
          break;
      }

    }
    for (char c : L) cout << c;
    cout << "\n";
    L.clear();
  }
}