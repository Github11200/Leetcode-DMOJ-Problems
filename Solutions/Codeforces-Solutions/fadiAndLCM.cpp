#include <bits/stdc++.h>
#include <climits>
#include <cmath>

using namespace std;

/******************************************
  Link: https://codeforces.com/problemset/problem/1285/C
  Points: Accepted
******************************************/

#define ll long long

ll lcm(ll a, ll b) {
  ll i = 1;
  while ((b * i) % a != 0)
    ++i;
  return b * i;
}

int main() {
  ll x;
  cin >> x;

  if (x == 1) {
    cout << "1 1" << endl;
    return 0;
  }

  ll minMax = LLONG_MAX;
  ll numOne = 0, numTwo = 0;
  for (ll i = 1; i <= sqrt(x); ++i) {
    if (x % i != 0)
      continue;
    if (lcm(i, x / i) != x)
      continue;

    minMax = max(i, x / i);
    numOne = i;
    numTwo = x / i;
  }

  cout << numOne << " " << numTwo << endl;

  return 0;
}
