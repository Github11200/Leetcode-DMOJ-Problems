#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/utso24p1
  Points: 50/100
******************************************/

void wateringThePlants()
{
  unsigned long long numberOfFlowers, maximumCapacity;
  scanf("%llu", &numberOfFlowers);
  scanf("%llu", &maximumCapacity);

  unsigned long long position = 0;
  unsigned long long amountWatered = 0;
  unsigned long long numberOfSteps = 0;
  unsigned long long waterLeft = maximumCapacity;
  while (amountWatered < numberOfFlowers)
  {
    // refill
    if (waterLeft == 0)
    {
      numberOfSteps += 2 * position;
      waterLeft = maximumCapacity;
    }

    // Just move
    ++position;
    --waterLeft;
    ++amountWatered;
    ++numberOfSteps;
  }

  printf("%llu", numberOfSteps + numberOfFlowers);
}

int main()
{
  wateringThePlants();
  return 0;
}