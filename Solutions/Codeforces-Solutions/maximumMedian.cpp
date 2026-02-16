#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://codeforces.com/problemset/problem/1201/C
  Points: Accepted
******************************************/

#define ll long long

int main() {
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (auto &item : a)
    cin >> item;

  if (n == 1) {
    cout << (a[0] + k) << endl;
    return 0;
  }

  sort(a.begin(), a.end());

  ll median = n / 2;
  while (k > 0) {
    ll curr = a[median];
    ll next = a[median + 1];
    if (curr + 1 > next) {
      for (ll i = n - 1; i > median; --i) {
        if (a[i] == curr + 1)
          continue;
        if (k == 0)
          break;
        ++a[i];
        --k;
      }
    } else {
      ++a[median];
      --k;
    }
  }

  cout << a[median] << endl;
  return 0;
}
