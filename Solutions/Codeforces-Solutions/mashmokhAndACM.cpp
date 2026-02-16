#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://codeforces.com/contest/414/problem/B
  Points: Accepted
******************************************/

#define ll unsigned long long

int main() {
  ll n, k;
  cin >> n >> k;

  if (k == 1) {
    cout << n << endl;
    return 0;
  }

  vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, 0));

  for (auto &item : dp[1])
    item = 1;

  for (ll i = 2; i <= k; ++i)
    for (ll j = 1; j <= n; ++j)
      for (ll l = j; l <= n; l += j)
        dp[i][j] += (dp[i - 1][l] % (ll)(1e9 + 7));

  ll sum = 0;
  for (const auto &item : dp.back())
    sum += item;

  cout << (sum % (ll)(1e9 + 7)) << endl;

  return 0;
}
