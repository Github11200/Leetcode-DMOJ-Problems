#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/delete-and-earn/description/
  Runtime: 67.76%
  Memory: 61.45%
******************************************/

int deleteAndEarn(vector<int> &nums)
{
  unordered_map<int, int> counts;
  vector<int> numsPrime;

  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); ++i)
  {
    if (i == 0 || nums[i] != nums[i - 1])
      numsPrime.push_back(nums[i]);
    ++counts[nums[i]];
  }

  vector<int> dp(numsPrime.size(), 0);
  dp[0] = numsPrime[0] * counts[numsPrime[0]];
  for (int i = 1; i < numsPrime.size(); ++i)
  {
    int value = 0;
    value += numsPrime[i] * counts[numsPrime[i]];
    if (numsPrime[i] - numsPrime[i - 1] > 1)
      dp[i] = value + dp[i - 1];
    else
      dp[i] = max(value + (i >= 2 ? dp[i - 2] : 0), dp[i - 1]);
  }

  return dp[dp.size() - 1];
}

int main()
{
  vector<int> nums({2, 3, 4});
  cout << deleteAndEarn(nums) << endl;
  return 0;
}