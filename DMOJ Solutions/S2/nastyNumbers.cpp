#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc97s2
  Points: 100/100
******************************************/

void nastyNumbers()
{
  int N;
  scanf("%d", &N);
  int input;
  for (int i = 0; i < N; ++i)
  {
    scanf("%d", &input);

    vector<pair<int, int>> factors;
    factors.push_back(pair<int, int>(input, 1));

    unordered_map<int, pair<int, int>> sums;

    int x = input;
    for (int j = 2; j * j <= input; ++j)
    {
      if (x % j == 0)
      {
        factors.push_back(pair<int, int>(j, x / j));
        sums[j + x / j] = pair<int, int>(j, x / j);
      }
    }

    bool nasty = false;
    for (auto factor : factors)
    {
      int difference = abs(factor.first - factor.second);
      if (sums.count(difference) && sums[difference] != factor)
      {
        nasty = true;
        break;
      }
    }

    if (nasty)
      printf("%d is nasty\n", input);
    else
      printf("%d is not nasty\n", input);
  }
}

int main()
{
  nastyNumbers();
  return 0;
}