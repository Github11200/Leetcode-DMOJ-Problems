#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link:
  Points:
******************************************/

void tinCanTelephone()
{
  pair<int, int> romyLocation, juleLocation;
  set<pair<int, int>> lineCoordinates;
  int numberOfBuildings = 0;

  scanf("%d %d %d %d", &romyLocation.first, &romyLocation.second, &juleLocation.first, &juleLocation.second);
  scanf("%d", &numberOfBuildings);

  double slope = (double)(juleLocation.second - romyLocation.second) / (juleLocation.first - romyLocation.first);
  for (int x = romyLocation.first; juleLocation.first < romyLocation.first ? x > juleLocation.first : x < juleLocation.first; juleLocation.first < romyLocation.first ? --x : ++x)
  {
    double y = slope * x;
    if (y == floor(y))
      lineCoordinates.insert(pair<int, int>(x, (int)y));
  }

  int numberOfBuildingBlockingSight = 0;
  for (int i = 0; i < numberOfBuildings; ++i)
  {
    int minX = INT_MAX;
    int minY = INT_MAX;
    int maxX = INT_MIN;
    int maxY = INT_MIN;
    int numberOfCorners;
    scanf("%d", &numberOfCorners);
    pair<int, int> currentCoordinates;
    for (int j = 0; j < numberOfCorners; ++j)
    {
      scanf("%d %d", &currentCoordinates.first, &currentCoordinates.second);
      minX = min(minX, currentCoordinates.first);
      minY = min(minY, currentCoordinates.second);
      maxX = max(maxX, currentCoordinates.first);
      maxY = max(maxY, currentCoordinates.second);
    }

    for (int x = minX; x <= maxX; ++x)
    {
      bool isBlocking = false;
      for (int y = maxY; y >= minY; --y)
      {
        if (lineCoordinates.count(pair<int, int>(x, y)) > 0)
        {
          ++numberOfBuildingBlockingSight;
          isBlocking = true;
          break;
        }
      }
      if (isBlocking)
        break;
    }
  }

  printf("%d\n", numberOfBuildingBlockingSight);
}

int main()
{
  tinCanTelephone();
  return 0;
}
