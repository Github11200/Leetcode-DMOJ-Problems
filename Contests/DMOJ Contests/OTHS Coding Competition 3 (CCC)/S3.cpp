#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link:
  Points:
******************************************/

void domainExpansion()
{
  int N, K;
  scanf("%d %d", &N, &K);

  // .first = sorcerer index
  // .second = strength
  vector<pair<int, int>> regions(K, pair<int, int>({-1, -1}));
  for (int i = 0; i < N; ++i)
  {
    int l, r, s;
    scanf("%d %d %d", &l, &r, &s);
    for (int j = l - 1; j < r; ++j)
      // the current strength is greater
      if (s > regions[j].second)
        regions[j] = pair<int, int>({i, s});
  }

  vector<int> expansions(N, 0);
  for (int i = 0; i < regions.size(); ++i)
    if (regions[i].first != -1)
      ++expansions[regions[i].first];

  for (int i = 0; i < expansions.size(); ++i)
    printf("%d ", expansions[i]);
  printf("\n");
}

int main()
{
  domainExpansion();
  return 0;
}