#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link:
  Points:
******************************************/

void togetherForever()
{
  int N;
  scanf("%d", &N);

  vector<int> a(N), b(N);
  for (int i = 0; i < N; ++i)
    scanf("%d", &a[i]);
  for (int i = 0; i < N; ++i)
    scanf("%d", &b[i]);

  vector<pair<int, int>> swaps;
  for (int i = 0; i < N; ++i)
  {
    if (a[i] != b[i])
    {
      int firstIndex = 0;
      for (int j = i + 1; j < N; ++j)
      {
        if (a[j] == b[i])
        {
          firstIndex = j;
          break;
        }
      }
      swaps.push_back(pair<int, int>(i + 1, firstIndex + 1));
      swap(a[i], a[firstIndex]);
    }
  }

  printf("%d\n", swaps.size());
  for (int i = 0; i < swaps.size(); ++i)
    printf("%d %d\n", swaps[i].first, swaps[i].second);
}

int main()
{
  togetherForever();
  return 0;
}