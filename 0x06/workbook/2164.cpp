#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  queue<int> cards;

  cin >> N;

  for (int i = 1; i <= N; i++) cards.push(i);

  while (cards.size() > 1) {
    cards.pop();
    cards.push(cards.front());
    cards.pop();
  }

  cout << cards.front();
}