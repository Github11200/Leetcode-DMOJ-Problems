#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/joi05fp1
  Points: 20/20
******************************************/

bool customSort(pair<int, int> a, pair<int, int> b)
{
  if (a.first == b.first)
    return a.second > b.second;
  return a.first < b.first;
}

void questionnaire()
{
  int n, m;
  scanf("%d %d", &n, &m);

  vector<pair<int, int>> excursionScores(m);
  for (int i = 0; i < excursionScores.size(); ++i)
    excursionScores[i] = pair<int, int>(0, i + 1);
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      int temp;
      scanf("%d", &temp);
      if (temp == 1)
        ++excursionScores[j].first;
    }
  }

  sort(excursionScores.rbegin(), excursionScores.rend(), customSort);
  for (int i = 0; i < excursionScores.size(); ++i)
  {
    printf("%d", excursionScores[i].second);
    if (i < excursionScores.size() - 1)
      printf(" ");
  }
  printf("\n");
}

int main()
{
  questionnaire();
  return 0;
}