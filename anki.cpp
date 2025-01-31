#include "helperFunctions.h"

using namespace std;

void swipe()
{
  int N;
  scanf("%d", &N);

  vector<int> A(N), B(N), BPrime, firstOccurences, lastOccurences;
  for (int i = 0; i < N; ++i)
    scanf("%d", &A[i]);

  for (int i = 0; i < N; ++i)
  {
    scanf("%d", &B[i]);
    if (i == 0 || B[i] != B[i - 1])
    {
      BPrime.push_back(B[i]);
      firstOccurences.push_back(i);
      lastOccurences.push_back(i);
    }
    else if (i > 0 && B[i] == B[i - 1])
      ++lastOccurences[lastOccurences.size() - 1];
  }

  int j = 0;
  for (int i = 0; i < A.size(); ++i)
    if (A[i] == BPrime[j])
      ++j;

  if (j == BPrime.size())
    printf("YES\n");
  else
  {
    printf("NO\n");
    return;
  }

  j = 0;
  vector<pair<int, int>> leftSwipes, rightSwipes;
  for (int i = 0; i < A.size(); ++i)
  {
    if (A[i] == BPrime[j])
    {
      if (firstOccurences[j] < i)
        leftSwipes.push_back(pair<int, int>(firstOccurences[j], i));
      if (lastOccurences[j] > i)
        rightSwipes.push_back(pair<int, int>(i, lastOccurences[j]));
      ++j;
    }
  }

  sort(rightSwipes.rbegin(), rightSwipes.rend());
  sort(leftSwipes.begin(), leftSwipes.end());

  printf("%d\n", leftSwipes.size() + rightSwipes.size());
  for (int i = 0; i < rightSwipes.size(); ++i)
    printf("R %d %d\n", rightSwipes[i].first, rightSwipes[i].second);

  for (int i = 0; i < leftSwipes.size(); ++i)
    printf("L %d %d\n", leftSwipes[i].first, leftSwipes[i].second);
}

void goodSamples()
{
  long long N, M, K;
  scanf("%lld %lld %lld", &N, &M, &K);

  vector<long long> res;
  for (long long i = 0; i < N; ++i)
  {
    long long remainingAfterCurrent = N - i - 1;
    long long maximumPairsAtCurrent = min(M, K - remainingAfterCurrent);

    if (maximumPairsAtCurrent <= 0)
      break;

    long long value = 0;
    if (maximumPairsAtCurrent > i)
    {
      value = min(M, i + 1);
      maximumPairsAtCurrent = value;
    }
    else
      value = res[i - maximumPairsAtCurrent];
    res.push_back(value);
    K -= maximumPairsAtCurrent;
  }

  if (res.size() == N && K == 0)
  {
    for (long long i = 0; i < res.size(); ++i)
      printf("%lld ", res[i]);
    printf("\n");
  }
  else
    printf("-1\n");
}

int jumpGame2(vector<int> &nums)
{
  int left = 0;
  int right = 0;
  int res = 0;
  while (right < nums.size() - 1)
  {
    int farthest = 0;
    for (int i = left; i <= right; ++i)
      farthest = max(farthest, nums[i] + i);

    left = right + 1;
    right = farthest;
    ++res;
  }
  return res;
}

vector<int> nextGreaterElement1(vector<int> &nums1, vector<int> &nums2)
{
  unordered_map<int, int> nums1Hash;
  for (int i = 0; i < nums1.size(); ++i)
    nums1Hash[nums1[i]] = i;

  vector<int> res(nums1.size(), -1);
  stack<int> descendingElements;
  for (int i = 0; i < nums2.size(); ++i)
  {
    while (!descendingElements.empty() && nums2[i] > descendingElements.top())
    {
      res[nums1Hash[descendingElements.top()]] = nums2[i];
      descendingElements.pop();
    }
    if (nums1Hash.count(nums2[i]))
      descendingElements.push(nums2[i]);
  }

  return res;
}

int main()
{
  vector<int> nums1({4, 1, 2});
  vector<int> nums2({1, 3, 4, 2});
  displayVector(nextGreaterElement1(nums1, nums2));
  return 0;
}