#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  cin >> N >> K;
  
  list<int> L(N);
  iota(L.begin(), L.end(), 1);
  auto cur = L.begin();

  cout << '<';
  while (!L.empty()) {
    for (int i = 1; i < K; i++) {
      ++cur;
      if (cur == L.end()) cur = L.begin();
    }
    cout << *cur;
    cur = L.erase(cur);
    if (cur == L.end()) cur = L.begin();
    if (!L.empty()) cout << ", ";
  }
  cout << '>';
}