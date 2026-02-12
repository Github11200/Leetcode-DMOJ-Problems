#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://codeforces.com/problemset/problem/1195/C
  Points: Accepted
******************************************/

#define ll long long

int main() {
  int n;
  cin >> n;

  vector<int> h1(n), h2(n);
  for (auto &h : h1)
    cin >> h;
  for (auto &h : h2)
    cin >> h;

  ll dp1[100001];
  ll dp2[100001];
  ll dp3[100001];

  dp1[0] = h1[0];
  dp2[0] = h2[0];
  dp3[0] = 0;

  int i = 1;
  for (; i < n; ++i) {
    dp1[i] = max(dp2[i - 1] + h1[i], dp3[i - 1] + h1[i]);
    dp2[i] = max(dp1[i - 1] + h2[i], dp3[i - 1] + h2[i]);
    dp3[i] = max(dp1[i - 1], dp2[i - 1]);
  }

  cout << max({dp1[i - 1], dp2[i - 1], dp3[i - 1]});
  return 0;
}
