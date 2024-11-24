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

int minimumPositiveSumSubarray(vector<int> &nums, int l, int r)
{
  vector<int> prefixSum(nums.size());
  prefixSum[0] = nums[0];
  for (int i = 1; i < nums.size(); ++i)
    prefixSum[i] = prefixSum[i - 1] + nums[i];

  int minSum = -1;
  for (int i = l; i < r; ++i)
  {
    for (int j = i - 1; j < nums.size(); ++j)
    {
      int sum = j - i + 1 == 0 ? prefixSum[j] : prefixSum[j] - prefixSum[j - i];
      if (sum > 0 && (sum < minSum || minSum == -1))
        minSum = sum;
    }
  }
  return minSum;
}

bool rearrangeKSubstringsToFormTargetString(string s, string t, int k)
{
  unordered_map<string, int> strings;
  k = t.size() / k;
  for (int i = k; i <= t.size(); i += k)
    ++strings[t.substr(i - k, k)];

  for (int i = k; i <= s.size(); i += k)
  {
    string subString = s.substr(i - k, k);
    if (strings.count(subString) == 0)
      return false;
    else if (strings[subString] == 1)
      strings.erase(subString);
    else
      --strings[subString];
  }

  return true;
}

int minimumArraySum(vector<int> &nums, int k, int op1, int op2)
{
  sort(nums.begin(), nums.end(), greater<>());

  int sum = 0;
  for (int i = 0; i < nums.size(); ++i)
  {
    bool canDoOp1 = op1 > 0 ? true : false;
    bool canDoOp2 = op2 > 0 && nums[i] >= k ? true : false;
    int op1Result = ceil(nums[i] / (double)2);
    int op2Result = nums[i] - k;

    if (canDoOp1 && (op1Result < op2Result || !canDoOp2))
    {
      nums[i] = op1Result;
      --op1;
    }
    else if (canDoOp2)
    {
      nums[i] = op2Result;
      --op2;
    }
    sum += nums[i];
  }

  return sum;
}

int main()
{
  vector<int> nums({2, 4, 3});
  cout << minimumArraySum(nums, 3, 2, 1) << endl;

  return 0;
}
