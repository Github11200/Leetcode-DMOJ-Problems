#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link:
  Points:
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
  int T, N;
  scanf("%d", &T);

  vector<int> primes;
  for (int i = 0; i < T; ++i)
  {
    scanf("%d", &N);
    N *= 2;
    for (int j = 2; j <= N / 2; ++j)
    {
      bool leftPrime = isPrime(j);
      bool rightPrime = isPrime(N - j);

      if (leftPrime && rightPrime)
      {
        printf("%d %d\n", j, N - j);
        break;
      }
    }
  }
}

int main()
{
  prettyAveragePrimes();
  return 0;
}