#include <bits/stdc++.h>

using namespace std;

/*******************************************************************************************
  Link:
  Points:
  Original solution:
*******************************************************************************************/

void optimalSplitPoint()
{
  int N;
  scanf("%d", &N);

  vector<int> a(N);
  int leftSum = 0;
  int rightSum = 0;
  for (int i = 0; i < N; ++i)
  {
    int temp;
    scanf("%d", &temp);
    a[i] = temp;

    if (i == 0)
      leftSum += temp;
    if (i >= 1)
      rightSum += temp;
  }

  int bestSplit = INT_MAX;
  int bestSplitIndex = 0;
  int bestSwapIndex = -1;

  // sort(rightCounts.begin(), rightCounts.end());
  for (int i = 1; i < N - 1; ++i)
  {
    rightSum -= a[i];
    int diff = abs(leftSum - rightSum);
    if (diff < bestSplit)
    {
      bestSplit = diff;
      bestSplitIndex = i + 1;
    }

    if (leftSum == rightSum)
    {
      printf("%d %d\n", i + 1, bestSwapIndex);
      return;
    }
    // We want to shift element from right array to left array
    else if (leftSum < rightSum)
    {
      diff = abs((leftSum + a[i + 1]) - (rightSum - a[i + 1]));
      if (diff < bestSplit)
      {
        bestSplit = diff;
        bestSplitIndex = i + 1;
        bestSwapIndex = i + 2;
      }
    }
    else
    {
      diff = abs((leftSum + a[i - 1]) - (rightSum - a[i - 1]));
      if (diff < bestSplit)
      {
        bestSplit = diff;
        bestSplitIndex = i + 1;
        bestSwapIndex = i - 2;
      }
    }

    leftSum += a[i];
  }

  printf("%d %d\n", bestSplitIndex, bestSwapIndex);
}

int main()
{
  optimalSplitPoint();
  return 0;
}