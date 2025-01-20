#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://codeforces.com/problemset/problem/791/A
  Points: Accepted
******************************************/

void bearAndBigBrother()
{
  int limakWeight, bobWeight;
  scanf("%d %d", &limakWeight, &bobWeight);

  int year = 0;
  while (limakWeight < bobWeight)
  {
    limakWeight *= 3;
    bobWeight *= 2;
    ++year;
  }

  printf("%d", year);
}

int main()
{
  aBearAndBigBrother();
  return 0;
}