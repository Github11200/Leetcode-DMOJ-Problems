#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://codeforces.com/problemset/problem/1350/B
  Points: Accepted
******************************************/

#define ll long long

vector<ll> getFactors(ll n)
{
  vector<ll> factors({1});
  for (ll i = 2; i <= sqrt(n); ++i)
    if (n % i == 0)
    {
      factors.push_back(i);
      factors.push_back(n / i);
    }
  return factors;
}

int main()
{
  ll t;
  cin >> t;

  for (ll i = 0; i < t; ++i)
  {
    ll n;
    cin >> n;

    if (n == 1)
    {
      int x;
      cin >> x;
      cout << "1" << endl;
      continue;
    }

    vector<ll> a(n);
    for (auto &item : a)
      cin >> item;

    vector<ll> dp(n);
    dp[0] = 1;
    ll maxItem = LONG_LONG_MIN;
    for (ll j = 1; j < n; ++j)
    {
      vector<ll> factors = getFactors(j + 1);

      ll maxModels = LONG_LONG_MIN;
      for (const auto &factor : factors)
        if (a[factor - 1] < a[j])
          maxModels = max(maxModels, dp[factor - 1] + 1);
      dp[j] = maxModels == LONG_LONG_MIN ? 1 : maxModels;

      maxItem = max(maxItem, dp[j]);
    }

    cout << maxItem << endl;
  }

  return 0;
}
