#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://mirror.codeforces.com/problemset/problem/1324/D
  Points: Accepted
******************************************/

#define ll long long

int main() {
  ll n;
  cin >> n;

  vector<ll> a(n), c(n);
  for (auto &item : a)
    cin >> item;
  for (ll i = 0; i < n; ++i) {
    ll b;
    cin >> b;
    c[i] = a[i] - b;
  }

  sort(c.begin(), c.end());

  ll goodPairs = 0;
  for (ll i = 0; i < n - 1; ++i) {
    ll difference = -c[i] + 1;
    vector<ll>::iterator lower =
        lower_bound(c.begin() + i + 1, c.end(), difference);

    goodPairs += c.end() - lower;
  }

  cout << goodPairs << endl;

  return 0;
}
