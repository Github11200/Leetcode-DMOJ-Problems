#include "helperFunctions.h"

using namespace std;

void gates()
{
  int numberOfGates;
  int numberOfPlanes;

  scanf("%d", &numberOfGates);
  scanf("%d", &numberOfPlanes);

  vector<int> planes(numberOfPlanes);
  set<int, greater<int>> gates;
  for (int i = 0; i < numberOfPlanes; ++i)
    scanf("%d", &planes[i]);
  for (int i = 1; i <= numberOfGates; ++i)
    gates.insert(i);

  int numberOfPlanesAbleToDock = 0;
  for (int i = 0; i < numberOfPlanes; ++i)
  {
    auto gate = gates.lower_bound(planes[i]);
    if (gate == gates.end())
      break;
    gates.erase(*gate);
    ++numberOfPlanesAbleToDock;
  }

  printf("%d\n", numberOfPlanesAbleToDock);
}

int subarraySumEqualsK(vector<int> &nums, int k)
{
  unordered_map<int, int> previousSums;
  previousSums[0] = 1;
  int prefixSum;
  int numberOfSubarrays = 0;

  for (int i = 0; i < nums.size(); ++i)
  {
    prefixSum += nums[i];
    int diff = prefixSum - k;

    if (previousSums.count(diff))
      numberOfSubarrays += previousSums[diff];
    if (previousSums.count(prefixSum))
      ++previousSums[prefixSum];
    else
      previousSums[prefixSum] = 1;
  }

  return numberOfSubarrays;
}

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

    if (i > 0 && numsPrime[i] - numsPrime[i - 1] > 1)
      value += numsPrime[i - 1];
    else if (i >= 2 && numsPrime[i] - numsPrime[i - 1] == 1)
      value += dp[i - 2];
    if (i > 0)
      dp[i] = max(dp[i - 1], value);
    else
      dp[i] = value;
  }

  return dp[dp.size() - 1];
}

int main()
{
  return 0;
}