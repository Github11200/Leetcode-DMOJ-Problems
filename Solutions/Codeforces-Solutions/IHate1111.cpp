#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://codeforces.com/problemset/problem/1526/B
  Points: Accepted
******************************************/

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    bool isGood = false;
    for (int j = 0; j < 20; ++j) {
      if (n % 11 == 0) {
        isGood = true;
        break;
      }
      n -= 111;
      if (n < 0)
        break;
    }

    if (isGood)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
