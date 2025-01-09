#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc08s2
  Points: 100/100
******************************************/

void penniesInTheRing()
{
  int radius = -1;

  while (radius != 0)
  {
    scanf("%d", &radius);
    if (radius == 0)
      break;

    int numberOfPennies = 0;

    for (int i = 0; i < radius; ++i)
    {
      numberOfPennies += sqrt(pow(radius, 2) - pow(i, 2));
    }

    printf("%d\n", numberOfPennies * 4 + 1);
  }
}

int main()
{
  penniesInTheRing();
  return 0;
}