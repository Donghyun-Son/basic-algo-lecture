#include <bits/stdc++.h>
using namespace std;

void parse(string& arr, deque<int>& DQ) {
  int cur = 0;
  for (int i = 1; i + 1 < arr.size(); i++) {
    if (arr[i] == ',') {
      DQ.push_back(cur);
      cur = 0;
    }
    else cur = 10 * cur + (arr[i] - '0');
  }
  if (arr.size() > 2) DQ.push_back(cur);
}

void print(deque<int>& DQ, bool rev) {
  cout << '[';
  for (int i = 0; i < DQ.size(); i++) {
    if (i) cout << ',';
    cout << (rev ? DQ[DQ.size() - 1 - i] : DQ[i]);
  }
  cout << "]\n";
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  while (T--) {
    string func, arr;
    int n;
    deque<int> DQ;
    cin >> func >> n >> arr;

    parse(arr, DQ);

    bool rev = false, error = false;
    for (char c : func) {
      if (c == 'R') rev = !rev;
      else if (c == 'D') {
        if (DQ.empty()) { 
          error = true;
          break;
        }
        if (rev) DQ.pop_back();
        else DQ.pop_front();
      }
    }

    if (error) cout << "error\n";
    else print(DQ, rev);
  }
}
