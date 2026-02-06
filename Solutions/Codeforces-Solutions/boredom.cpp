#include <bits/stdc++.h>

using namespace std;

#define ll long long

int counts[100001];

int main() {
  ll int n;
  cin >> n;

  vector<ll int> nums(n);
  for (auto &num : nums) {
    cin >> num;
    ++counts[num];
  }

  ll int dp[100001];
  dp[0] = 0;
  dp[1] = counts[1];

  for (ll int i = 2; i <= 100000; ++i) {
    dp[i] = max(counts[i] * i + dp[i - 2], dp[i - 1]);
  }

  cout << dp[100000] << endl;

  return 0;
}
