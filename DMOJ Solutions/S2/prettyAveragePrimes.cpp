#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc19s2
  Points: 15/15
******************************************/

bool isPrime(int x)
{
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0)
      return false;
  return true;
}

void prettyAveragePrimes()
{
  int T;
  scanf("%d", &T);

  int num, j;
  bool leftPrime, rightPrime;
  for (int i = 0; i < T; ++i)
  {
    scanf("%d", &num);
    num *= 2;

    j = 2;
    while (j <= num / 2)
    {
      leftPrime = isPrime(j);
      rightPrime = isPrime(num - j);

      if (leftPrime && rightPrime)
      {
        printf("%d %d\n", j, num - j);
        break;
      }
      ++j;
    }
  }
}

int main()
{
  prettyAveragePrimes();
  return 0;
}