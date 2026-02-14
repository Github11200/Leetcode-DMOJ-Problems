#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://mirror.codeforces.com/problemset/problem/479/C
  Points: Accepted
******************************************/

#define Pair pair<int, int>

int main() {
  int n;
  cin >> n;

  vector<Pair> c(n);
  for (auto &item : c) {
    int a, b;
    cin >> a >> b;
    item = Pair(a, b);
  }

  if (n == 1) {
    cout << c[0].second << endl;
    return 0;
  }

  sort(c.begin(), c.end());

  int currentDay = c[0].second;
  for (int i = 1; i < n; ++i) {
    if (c[i].second >= currentDay)
      currentDay = c[i].second;
    else
      currentDay = c[i].first;
  }

  cout << currentDay << endl;

  return 0;
}
