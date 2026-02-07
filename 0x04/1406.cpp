#include <bits/stdc++.h>
using namespace std;

const int MX = 600002;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;
int cursor = 0;

void insert(char c){
  dat[unused] = c;
  pre[unused] = cursor;
  nxt[unused] = nxt[cursor];
  if (nxt[cursor] != -1) pre[nxt[cursor]] = unused;
  nxt[cursor] = unused;
  cursor = unused;
  unused++;
}

void erase(){
  int tmp = pre[cursor];
  nxt[tmp] = nxt[cursor];
  if (nxt[cursor] != -1) pre[nxt[cursor]] = tmp;
  cursor = tmp;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);

  string init_data;
  int M;
  char cmd, c;

  cin >> init_data;
  cin >> M;

  for (char ch : init_data) insert(ch);

  for (int i = 0; i < M; i++) {
    cin >> cmd;
    switch (cmd) {
      case 'L':
        if (cursor != 0) cursor = pre[cursor];
        break;
      case 'D':
        if (nxt[cursor] != -1) cursor = nxt[cursor];
        break;
      case 'B':
        if (cursor != 0) erase();
        break;
      case 'P':
        cin >> c;
        insert(c);
        break;
    }
  }

  int cur = nxt[0];
  while (cur != -1) {
    cout << dat[cur];
    cur = nxt[cur];
  }
}