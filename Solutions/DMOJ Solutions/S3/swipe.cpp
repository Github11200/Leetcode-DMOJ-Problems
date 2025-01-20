#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc24s3
  Points: 15/15
  Inspiration: https://www.youtube.com/watch?v=2hNgXOlqxxU&t=48s
******************************************/

void swipe()
{
  int N;
  scanf("%d", &N);

  vector<int> A(N), BPrime, firstOccurences, lastOccurences;
  queue<int> order;
  for (int i = 0; i < N; ++i)
  {
    scanf("%d", &A[i]);
    if (order.empty() || order.front() != A[i])
      order.push(A[i]);
  }

  int j = -1;
  for (int i = 0; i < N; ++i)
  {
    int temp;
    scanf("%d", &temp);
    if (BPrime.size() == 0 || BPrime[j] != temp)
    {
      BPrime.push_back(temp);
      firstOccurences.push_back(i);
      lastOccurences.push_back(i);
      ++j;
    }
    else if (BPrime.size() != 0 && BPrime[j] == temp)
      lastOccurences[j] = i;
  }

  j = 0;
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
  vector<pair<int, int>> rightSwipes, leftSwipes;
  for (int i = 0; i < N && j < BPrime.size(); ++i)
  {
    if (A[i] == BPrime[j])
    {
      if (i < lastOccurences[j])
        rightSwipes.push_back(pair<int, int>(i, lastOccurences[j]));
      if (i > firstOccurences[j])
        leftSwipes.push_back(pair<int, int>(firstOccurences[j], i));
      ++j;
    }
  }

  sort(rightSwipes.rbegin(), rightSwipes.rend());
  sort(leftSwipes.begin(), leftSwipes.end());

  printf("%d\n", rightSwipes.size() + leftSwipes.size());
  for (int i = 0; i < rightSwipes.size(); ++i)
    printf("R %d %d\n", rightSwipes[i].first, rightSwipes[i].second);
  for (int i = 0; i < leftSwipes.size(); ++i)
    printf("L %d %d\n", leftSwipes[i].first, leftSwipes[i].second);
}

int main()
{
  swipe();
  return 0;
}