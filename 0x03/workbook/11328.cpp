#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    vector<int> cnt('z' - 'a' + 1);
    
    string first;
    cin >> first;
    for (char c : first) cnt[c - 'a']++;
    
    string second;
    cin >> second;
    for (char c : second) cnt[c - 'a']--;

    bool pos = true;
    for (int n : cnt) {
      if (n != 0) {
        pos = false;
        break;
      }
    }

    if (pos) cout << "Possible";
    else cout << "Impossible";
    cout << "\n";
  }
}