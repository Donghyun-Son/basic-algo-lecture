#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int A, B, C;
  int len = 10;
  int count[len] = {};
  cin >> A >> B >> C;
  
  int mul = A * B * C;
  string s = to_string(mul);
  
  for (char c : s) count[c - '0']++;

  for (int i = 0; i < len; i++) cout << count[i] << "\n";
}