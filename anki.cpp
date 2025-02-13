#include "helperFunctions.h"

using namespace std;

void iterativePostOrderTraversal(TreeNode *root)
{
  stack<TreeNode *> nextNodes;
  while (!nextNodes.empty() || root != nullptr)
  {
    if (root != nullptr)
    {
      nextNodes.push(root);
      root = root->left;
    }
    else
    {
      TreeNode *temp = nextNodes.top()->right;
      if (temp == nullptr)
      {
        temp = nextNodes.top();
        nextNodes.pop();
        printf("%d ", temp->val);
        while (!nextNodes.empty() && nextNodes.top()->right == temp)
        {
          temp = nextNodes.top();
          nextNodes.pop();
          printf("%d ", temp->val);
        }
      }
      else
        root = temp;
    }
  }
}

int decodeWays(string s)
{
  vector<int> dp(s.size() + 1, 1);
  for (int i = s.size() - 1; i >= 0; --i)
  {
    int val = 0;
    if (s[i] == '0')
    {
      dp[i] = 0;
      continue;
    }
    val += dp[i + 1];
    if (i + 2 <= s.size() && (s[i] == '1' || (s[i] == '2' && int(s[i + 1]) <= 54)))
      val += dp[i + 2];
    dp[i] = val;
  }
  return dp[0];
}

void goodSamples()
{
  long long N, M, K;
  scanf("%lld %lld %lld", &N, &M, &K);

  vector<long long> result;
  for (long long i = 0; i < N; ++i)
  {
    long long notesRemainingAfterCurrent = N - i - 1;
    long long maximumNotesAtCurrent = min(M, K - notesRemainingAfterCurrent);

    if (maximumNotesAtCurrent <= 0)
      break;

    long long value = 0;
    if (maximumNotesAtCurrent > i)
    {
      value = min(M, i + 1);
      maximumNotesAtCurrent = value;
    }
    else
      value = result[i - maximumNotesAtCurrent];
    result.push_back(value);
    K -= maximumNotesAtCurrent;
  }

  if (K == 0 && result.size() == N)
  {
    for (long long i = 0; i < result.size(); ++i)
      printf("%lld ", result[i]);
    printf("\n");
    return;
  }
  printf("-1\n");
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
  unordered_map<int, int> nums1Hash;
  for (int i = 0; i < nums1.size(); ++i)
    nums1Hash[nums1[i]] = i;

  stack<int> descendingElements;
  vector<int> res(nums1.size(), -1);
  for (int i = 0; i < nums2.size(); ++i)
  {
    while (!descendingElements.empty() && nums2[i] > descendingElements.top())
    {
      int value = nums2[i];
      res[nums1Hash[descendingElements.top()]] = value;
      descendingElements.pop();
    }
    if (nums1Hash.count(nums2[i]) > 0)
      descendingElements.push(nums2[i]);
  }

  return res;
}

int kokoEatingBananas(vector<int> &piles, int h)
{
  sort(piles.begin(), piles.end());
  int low = 1;
  int high = piles[piles.size() - 1];
  int mid;

  int minimumSpeed = high;
  int previousMid = -1;
  while (low < high)
  {
    mid = (low + high) / 2;
    if (mid == previousMid)
      break;
    int numberOfHoursTaken = 0;
    for (int i = 0; i < piles.size(); ++i)
    {
      numberOfHoursTaken += piles[i] / mid;
      piles[i] % mid == 0 ? numberOfHoursTaken += 0 : ++numberOfHoursTaken;
    }
    if (numberOfHoursTaken > h)
      low = mid;
    else if (numberOfHoursTaken <= h)
    {
      high = mid;
      minimumSpeed = mid;
    }
    previousMid = mid;
  }
  return minimumSpeed;
}

void nailedIt()
{
  int N;
  scanf("%d", &N);
  vector<int> heightCounts(2001);
  for (int i = 0; i < N; ++i)
  {
    int temp;
    scanf("%d", &temp);
    ++heightCounts[temp];
  }

  vector<int> combinations(4001);
  for (int i = 0; i < heightCounts.size(); ++i)
  {
    if (heightCounts[i] == 0)
      continue;
    if (heightCounts[i] > 1)
      combinations[i * 2] += heightCounts[i] / 2;
    for (int j = i + 1; j < heightCounts.size(); ++j)
    {
      if (j == 0)
        continue;
      combinations[i + j] += min(heightCounts[i], heightCounts[j]);
    }
  }

  int longestFence = 1;
  int numberOfHeights = 0;
  for (int i = 0; i < combinations.size(); ++i)
  {
    if (combinations[i] > longestFence)
    {
      longestFence = combinations[i];
      numberOfHeights = 1;
    }
    else if (combinations[i] == longestFence)
      ++numberOfHeights;
  }
  printf("%d %d\n", longestFence, numberOfHeights);
}

int uniqueLength3PalindromicSubsequences(string s)
{
  unordered_map<char, int> startIndexes;
  unordered_map<char, int> endIndexes;
  for (int i = 0; i < s.size(); ++i)
  {
    if (startIndexes.count(s[i]) == 0)
    {
      startIndexes[s[i]] = i;
      endIndexes[s[i]] = i;
    }
    else
      endIndexes[s[i]] = i;
  }

  int numberOfSubsequences = 0;
  set<string> subsequences;
  for (auto el : startIndexes)
  {
    for (int j = el.second + 1; j < endIndexes[el.first]; ++j)
    {
      string temp;
      temp += el.first;
      temp += s[j];
      temp += s[endIndexes[el.first]];

      if (subsequences.count(temp) > 0)
        continue;
      ++numberOfSubsequences;
      subsequences.insert(temp);
    }
    subsequences.clear();
  }
  return numberOfSubsequences;
}

int main()
{
  cout << uniqueLength3PalindromicSubsequences("bbcbaba") << endl;
  return 0;
}