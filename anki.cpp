#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <numeric>
#include <math.h>
#include <set>
#include <bits/stdc++.h>

using namespace std;

int calculateBitwiseOr(vector<int> bitCounts)
{
  int sum = 0;
  for (int i = 0; i < 32; ++i)
    if (bitCounts[i])
      sum += 1 << i;
  return sum;
}

void updateBits(vector<int> bitCounts, int x, int sign)
{
  for (int i = 0; i < 32; ++i)
    if (x & (1 << i))
      bitCounts[i] += sign;
}

int shortestSubarrayWithOrAtLeastK2(vector<int> nums, int k)
{
  int shortestSubarray = INT_MAX;
  int bitsOrValue = 0;
  int j = 0;

  vector<int> bitCounts(32, 0);
  for (int i = 0; i < nums.size(); ++i)
  {
    updateBits(bitCounts, nums[i], 1);
    bitsOrValue = calculateBitwiseOr(bitCounts);
    while (j <= i && bitsOrValue >= k)
    {
      shortestSubarray = min(shortestSubarray, i - j + 1);
      updateBits(bitCounts, nums[j], -1);
      bitsOrValue = calculateBitwiseOr(bitCounts);
      ++j;
    }
  }

  return shortestSubarray == INT_MAX ? -1 : shortestSubarray;
}

void gates()
{
  int numberOfGates, numberOfPlanes;
  scanf("%d", &numberOfGates);
  scanf("%d", &numberOfPlanes);

  set<int, greater<int>> gates;
  for (int i = 1; i <= numberOfGates; ++i)
    gates.insert(i);
  int plane = 0;
  for (int i = 0; i < numberOfPlanes; ++i)
  {
    scanf("%d", &plane);

    auto val = gates.lower_bound(plane);
    if (val == gates.end())
    {
      printf("%d\n", i);
      return;
    }
    else
      gates.erase(*val);
  }

  printf("%d\n", numberOfPlanes);
}

int numberOfGoodPairs(vector<int> nums)
{
  unordered_map<int, int> counts;
  int numberOfGoodPairs = 0;
  for (int i = 0; i < nums.size(); ++i)
  {
    if (counts.count(nums[i]) == 0)
      counts[nums[i]] = 1;
    else
    {
      numberOfGoodPairs += counts[nums[i]];
      ++counts[nums[i]];
    }
  }

  return numberOfGoodPairs;
}

void nailedIt()
{
  int N;
  scanf("%d", &N);

  vector<int> lengths(2001);
  int temp;
  for (int i = 0; i < N; ++i)
  {
    scanf("%d", &temp);
    ++lengths[temp];
  }

  vector<int> combinations(4001);
  for (int i = 0; i < lengths.size(); ++i)
  {
    if (lengths[i] == 0)
      continue;
    if (lengths[i] > 1)
      combinations[i * 2] += lengths[i] / 2;
    for (int j = i + 1; j < lengths.size(); ++j)
    {
      if (lengths[j] == 0)
        continue;
      combinations[i + j] = min(lengths[i], lengths[j]);
    }
  }

  int maxLength = 1;
  int heights = 0;
  for (int i = 0; i < combinations.size(); ++i)
  {
    if (combinations[i] != 0 && combinations[i] > maxLength)
    {
      maxLength = combinations[i];
      heights = 1;
    }
    else if (combinations[i] == maxLength)
      ++heights;
  }

  printf("%d %d\n", maxLength, heights);
}

int jumpGame2(vector<int> nums)
{
  int left = 0;
  int right = 0;

  int numberOfJumps = 0;
  while (right < nums.size())
  {
    int farthestJump = 0;
    for (int i = left; i <= right; ++i)
      farthestJump = max(farthestJump, i + nums[i]);

    left = right + 1;
    right = farthestJump;
    ++numberOfJumps;
  }

  return numberOfJumps;
}

int main()
{
  nailedIt();

  return 0;
}