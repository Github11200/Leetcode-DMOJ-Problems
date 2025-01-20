#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/yac9p2
  Points: 100/100
******************************************/

void divideAndDelete()
{
  int T, N;
  scanf("%d", &T);

  vector<string> result(T);
  for (int i = 0; i < T; ++i)
  {
    scanf("%d", &N);
    vector<int> piles(N);
    bool allPilesEqual = true;
    int numberOfOnes = 0;
    for (int j = 0; j < N; ++j)
    {
      scanf("%d", &piles[j]);
      if (piles[j] == 1)
        ++numberOfOnes;
      if (j > 0 && piles[j] != piles[j - 1])
        allPilesEqual = false;
    }

    if (N == 1)
    {
      if (piles[0] > 1)
        result[i] = "Mike";
      else if (piles[0] == 1)
        result[i] = "Josh";
    }
    else if (N > 1)
    {
      // All elements are a 1, meets subtask 1
      if (numberOfOnes == N)
      {
        if (N % 2 == 0)
          result[i] = "Mike";
        else
          result[i] = "Josh";
      } // All the piles are the same number, meets subtask 2
      else if (allPilesEqual)
        result[i] = "Mike";
      // Subtask 3
      else
      {
        if (numberOfOnes % 2 == 0)
          result[i] = "Mike";
        else
          result[i] = "Josh";
      }
    }
  }

  for (int i = 0; i < result.size(); ++i)
    printf("%s\n", result[i].c_str());
}

int main()
{
  divideAndDelete();
  return 0;
}