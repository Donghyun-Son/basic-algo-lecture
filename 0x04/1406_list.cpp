#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string init_data;
  int M;
  char cmd, c;

  cin >> init_data;
  cin >> M;

  list<char> L(init_data.begin(), init_data.end());
  auto cursor = L.end(); // cursor starts after last character

  while (M--) {
    cin >> cmd;
    switch (cmd) {
      case 'L':
        if (cursor != L.begin()) --cursor;
        break;
      case 'D':
        if (cursor != L.end()) ++cursor;
        break;
      case 'B':
        if (cursor != L.begin()) cursor = L.erase(prev(cursor));
        break;
      case 'P':
        cin >> c;
        L.insert(cursor, c);
        break;
    }
  }

  for (char ch : L) cout << ch;
}
