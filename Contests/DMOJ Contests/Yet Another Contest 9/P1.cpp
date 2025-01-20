#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/yac9p1
  Points: 100/100
******************************************/

void nim()
{
  int N;
  scanf("%d", &N);

  vector<int> currentNumbers(N), finalNumbers(N);
  unordered_map<int, int> currentNumbersIndexes;
  for (int i = 0; i < N; ++i)
  {
    scanf("%d", &currentNumbers[i]);
    currentNumbersIndexes[currentNumbers[i]] = i;
  }
  for (int i = 0; i < N; ++i)
    scanf("%d", &finalNumbers[i]);

  int numberOfSubsequences = 0;
  for (int i = 0; i < finalNumbers.size(); ++i)
  {
    ++numberOfSubsequences;
    int j = currentNumbersIndexes[finalNumbers[i]];
    for (; j < N; ++j)
    {
      if (currentNumbers[j] != finalNumbers[i])
        break;
      ++i;
    }
    --i;
  }

  printf("%d", numberOfSubsequences);
}

int main()
{
  nim();
  return 0;
}