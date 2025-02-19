#include "helperFunctions.h"

using namespace std;

int subarraySumEqualsK(vector<int> &nums, int k)
{
  unordered_map<int, int> previousSums;
  previousSums[0] = 1;
  int prefixSum = 0;
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

bool wordBreak(string s, vector<string> wordDict)
{
  vector<bool> dp(s.size() + 1, false);
  dp[dp.size() - 1] = true;

  for (int i = s.size() - 1; i >= 0; --i)
  {
    for (int j = 0; j < wordDict.size(); ++j)
    {
      if (i + wordDict[j].size() <= s.size() && dp[i + wordDict[j].size()])
      {
        string curr = s.substr(i, wordDict[j].size());
        if (curr == wordDict[j])
          dp[i] = true;
      }
    }
  }

  return dp[0];
}

int deleteAndEarn(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
  vector<int> numsPrime;
  unordered_map<int, int> counts;

  for (int i = 0; i < nums.size(); ++i)
  {
    if (i == 0 || nums[i] != nums[i - 1])
    {
      numsPrime.push_back(nums[i]);
      counts[nums[i]] = 1;
    }
    else if (i > 0 && nums[i] == nums[i - 1])
      ++counts[nums[i]];
  }

  vector<int> dp(numsPrime.size(), 0);
  dp[0] = numsPrime[0] * counts[numsPrime[0]];
  for (int i = 1; i < numsPrime.size(); ++i)
  {
    int value = numsPrime[i] * counts[numsPrime[i]];
    if (numsPrime[i] - numsPrime[i - 1] > 1)
      value += numsPrime[i - 1];
    else
      value = max(value + (i >= 2 ? numsPrime[i - 2] : 0), numsPrime[i - 1]);
    dp[i] = value;
  }

  return dp[dp.size() - 1];
}

void iterativePreOrderTraversal(TreeNode *root)
{
  stack<TreeNode *> nextNodes;
  nextNodes.push(root);
  while (!nextNodes.empty())
  {
    TreeNode *curr = nextNodes.top();
    nextNodes.pop();
    printf("%d ", curr->val);

    if (curr->right != nullptr)
      nextNodes.push(curr->right);
    if (curr->left != nullptr)
      nextNodes.push(curr->left);
  }
}

int main()
{
  iterativePreOrderTraversal(createDefaultTree());
  return 0;
}