#include <bits/stdc++.h>
#include <strings.h>
#include <vector>

using namespace std;

/******************************************
  Link: https://codeforces.com/problemset/problem/276/C
  Points: Accepted
******************************************/

#define ll long long int

int main()
{
  ll n, q;
  cin >> n >> q;

  vector<ll> arr(n + 1);
  for (ll i = 1; i < n + 1; ++i)
    cin >> arr[i];

  vector<ll> counts(n + 1);
  for (ll i = 0; i < q; ++i)
  {
    ll first, second;
    cin >> first >> second;
    ++counts[first - 1];
    --counts[second];
  }

  for (ll i = 1; i < n + 1; ++i)
    counts[i] += counts[i - 1];

  sort(arr.begin(), arr.end());
  sort(counts.begin(), counts.end());

  ll sum = 0;
  for (ll i = 1; i < n + 1; ++i)
    sum += counts[i] * arr[i];

  cout << sum << endl;

  return 0;
}
