#include <bits/stdc++.h>
#include <climits>

using namespace std;

/******************************************
  Link: https://codeforces.com/problemset/problem/363/B
  Points: Accepted
******************************************/

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> heights(n);
  for (int i = 0; i < n; ++i)
    cin >> heights[i];

  int sum = 0;
  for (int i = 0; i < k; ++i)
    sum += heights[i];

  int minimumSum = INT_MAX;
  int minimumSumIndex = 0;
  int i = 0;
  for (; i < n - k; ++i) {
    if (sum < minimumSum) {
      minimumSum = sum;
      minimumSumIndex = i;
    }
    sum += heights[i + k];
    sum -= heights[i];
  }

  if (sum < minimumSum) {
    minimumSum = sum;
    minimumSumIndex = i;
  }

  cout << (minimumSumIndex + 1) << endl;
  return 0;
}
