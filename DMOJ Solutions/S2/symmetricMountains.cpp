#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc23s2
  Points: 15/15
******************************************/

void symmetricMountains()
{
  int N;
  scanf("%d", &N);

  int *heights = new int[N];
  for (int i = 0; i < N; ++i)
    scanf("%d", &heights[i]);

  vector<int> results(N, INT_MAX);
  for (int i = 0; i < N; ++i)
  {
    int l = i;
    int r = l;
    int j = 0;

    int asymmetricValue = 0;
    while (l >= 0 && r < N)
    {
      asymmetricValue += abs(heights[l] - heights[r]);
      results[j] = min(results[j], asymmetricValue);

      --l;
      ++r;
      j += 2;
    }

    l = i;
    r = l + 1;
    j = 1;
    asymmetricValue = 0;
    while (l >= 0 && r < N)
    {
      asymmetricValue += abs(heights[l] - heights[r]);
      results[j] = min(results[j], asymmetricValue);

      --l;
      ++r;
      j += 2;
    }
  }

  for (int i = 0; i < N; ++i)
    printf("%d ", results[i]);
}

int main()
{
  symmetricMountains();
  return 0;
}