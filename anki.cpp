#include "helperFunctions.h"

using namespace std;

int deleteAndEarn(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
  vector<int> numsPrime;

  unordered_map<int, int> counts;

  for (int i = 0; i < nums.size(); ++i)
  {
    if (i == 0 || nums[i] != nums[i - 1])
      numsPrime.push_back(nums[i]);
    ++counts[nums[i]];
  }

  vector<int> dp(numsPrime.size(), 0);
  for (int i = 0; i < numsPrime.size(); ++i)
  {
    int value = numsPrime[i] * counts[numsPrime[i]];
    if (i > 0 && numsPrime[i] - numsPrime[i - 1] == 1)
      dp[i] = max(dp[i - 1], value + (i >= 2 ? dp[i - 2] : 0));
    else if (i > 0)
      dp[i] = value + dp[i - 1];
    else
      dp[i] = value;
  }

  return dp[dp.size() - 1];
}

int subarraySumEqualsK(vector<int> &nums, int k)
{
  unordered_map<int, int> prefixSumsCount;
  prefixSumsCount[0] = 1;

  int prefixSum = 0;
  int diff = 0;
  int numberOfSubarrays = 0;

  for (int i = 0; i < nums.size(); ++i)
  {
    prefixSum += nums[i];
    diff = prefixSum - k;

    if (prefixSumsCount.count(diff))
      numberOfSubarrays += prefixSumsCount[diff];
    if (prefixSumsCount.count(prefixSum))
      ++prefixSumsCount[prefixSum];
    else
      prefixSumsCount[prefixSum] = 1;
  }

  return numberOfSubarrays;
}

int main()
{
  vector<int> nums({2, 2, 3, 3, 3, 4});
  cout << deleteAndEarn(nums) << endl;
  return 0;
}