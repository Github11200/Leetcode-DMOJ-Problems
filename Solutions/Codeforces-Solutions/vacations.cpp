#include <bits/stdc++.h>
#include <initializer_list>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> days(n);
  for (auto &day : days)
    cin >> day;

  vector<vector<int>> dp(n, vector<int>(3));
  if (days[0] == 1 || days[0] == 3)
    dp[0][1] = 1;
  if (days[0] == 2 || days[0] == 3)
    dp[0][2] = 1;
  if (days[0] == 0)
    dp[0][days[0]] = 0;

  for (int i = 1; i < n; ++i) {
    dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
    if (days[i] == 1 || days[i] == 3)
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
    if (days[i] == 2 || days[i] == 3)
      dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
  }

  cout << (n - max({dp.back()[0], dp.back()[1], dp.back()[2]})) << endl;
  return 0;
}
