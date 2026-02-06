#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://codeforces.com/problemset/problem/489/C
  Points: Accepted
******************************************/

// true -> Max, false - Min
string find(int m, int s, string curr, bool minOrMax) {
  static bool isFirstCall = true;
  if (m == 1)
    return curr + to_string(s);

  if (minOrMax) {
    for (int i = 9; i >= 0; --i)
      if (s - i >= 0)
        return find(m - 1, s - i, curr + to_string(i), true);
  } else {
    for (int i = isFirstCall ? 1 : 0; i <= 9; ++i) {
      isFirstCall = false;
      bool divides = (s - i) % 9 == 0;
      int remainder = divides ? (s - i) / 9 : ((s - i) / 9) + 1;
      if (remainder < m)
        return find(m - 1, s - i, curr + to_string(i), false);
    }
  }
}

int main() {
  long long int m, s;
  cin >> m >> s;

  if (s == 0) {
    if (m > 1)
      cout << "-1 -1" << endl;
    else
      cout << "0 0" << endl;

    return 0;
  }

  if (s > m * 9) {
    cout << "-1 -1" << endl;
    return 0;
  }

  string max = find(m, s, "", true);
  string min = find(m, s, "", false);

  cout << min << " " << max << endl;

  return 0;
}
