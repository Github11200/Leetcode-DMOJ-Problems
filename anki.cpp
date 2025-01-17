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

int containerWithMostWater(vector<int> height)
{
  int maxArea = -1;
  int i = 0;
  int j = height.size() - 1;
  int area = 0;
  while (i < j)
  {
    area = (j - i) * min(height[i], height[j]);
    maxArea = max(maxArea, area);
    if (height[i] < height[j])
      ++i;
    else if (height[j] < height[i])
      --j;
    else
    {
      ++i;
      --j;
    }
  }

  return maxArea;
}

int jumpGame2(vector<int> nums)
{
  int l = 0;
  int r = 0;
  int res = 0;
  while (r < nums.size() - 1)
  {
    int farthest = 0;
    for (int i = 0; i <= r; ++i)
      farthest = max(farthest, nums[i] + i);
    l = r + 1;
    r = farthest;
    ++res;
  }
  printf("%d", res);
  return res;
}

void symmetricMountains()
{
  int N;
  scanf("%d", &N);
  vector<int> heights(N);
  for (int i = 0; i < heights.size(); ++i)
    scanf("%d", &heights[i]);

  vector<int> result(N, INT_MAX);
  for (int i = 0; i < N; ++i)
  {
    int j = i;
    int k = i;
    int asymmetricValue = 0;
    while (j >= 0 && k < N)
    {
      asymmetricValue += abs(heights[j] - heights[k]);
      result[k - j] = min(result[k - j], asymmetricValue);
      --j;
      ++k;
    }
  }

  for (int i = 0; i < N - 1; ++i)
  {
    int j = i;
    int k = i + 1;
    int asymmetricValue = 0;
    while (j >= 0 && k < N)
    {
      asymmetricValue += abs(heights[j] - heights[k]);
      result[k - j] = min(result[k - j], asymmetricValue);
      --j;
      ++k;
    }
  }

  for (int i = 0; i < N; ++i)
    printf("%d ", result[i]);
}

void nailedIt()
{
  int N;
  scanf("%d", &N);

  vector<int> lengths(2001, 0);
  for (int i = 0; i < N; ++i)
  {
    int temp;
    scanf("%d", &temp);
    ++lengths[temp];
  }

  vector<int> combinations(4001);
  for (int i = 1; i < lengths.size(); ++i)
  {
    if (lengths[i] == 0)
      continue;
    if (lengths[i] > 1)
      combinations[i * 2] += lengths[i] / 2;
    for (int j = i + 1; j < lengths.size(); ++j)
      combinations[i + j] += min(lengths[i], lengths[j]);
  }

  int maxLength = 1;
  int heights = 0;
  for (int i = 1; i < combinations.size(); ++i)
  {
    if (combinations[i] > maxLength)
    {
      maxLength = combinations[i];
      heights = 1;
    }
    else if (combinations[i] == maxLength)
      ++heights;
  }

  printf("%d %d", maxLength, heights);
}

int main()
{
  nailedIt();
  return 0;
}