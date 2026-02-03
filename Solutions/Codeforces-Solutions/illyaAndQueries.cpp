#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://codeforces.com/problemset/problem/313/B
  Points: Accepted
******************************************/

int main() {
  string str;
  int m;

  cin >> str >> m;

  vector<int> memoizedSums(str.size());
  for (int i = 1; i < str.size(); ++i) {
    int isEqual = str[i] == str[i - 1];
    memoizedSums[i] = memoizedSums[i - 1] + isEqual;
  }

  for (int i = 0; i < m; ++i) {
    int lower, higher;
    cin >> lower >> higher;
    --lower, --higher;

    cout << (memoizedSums[higher] - memoizedSums[lower]) << endl;
  }

  return 0;
}
