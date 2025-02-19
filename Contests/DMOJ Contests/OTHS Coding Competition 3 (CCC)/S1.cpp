#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link:
  Points:
******************************************/

struct Point
{
  int x;
  int y;
  int z;
};

void the5thLaboratory()
{
  Point labCoordinates;
  scanf("%d %d %d", &labCoordinates.x, &labCoordinates.y, &labCoordinates.z);

  int N;
  scanf("%d", &N);

  Point hidingSpotCoordinates;
  double minimumTime = -1;
  double time = 0;
  double distance = 0;
  for (int i = 0; i < N; ++i)
  {
    scanf("%d %d %d", &hidingSpotCoordinates.x, &hidingSpotCoordinates.y, &hidingSpotCoordinates.z);

    if (hidingSpotCoordinates.z == labCoordinates.z)
    {
      // Just calculate the triangle distance
      distance = hypot(abs(hidingSpotCoordinates.x - labCoordinates.x), abs(hidingSpotCoordinates.y - labCoordinates.y));
      time = distance / 2;
    }
    else if (hidingSpotCoordinates.z < labCoordinates.z)
    {
      // Straight line distance
      distance = hypot(abs(hidingSpotCoordinates.x - labCoordinates.x), abs(hidingSpotCoordinates.y - labCoordinates.y));
      time += distance / 2;

      // Now we climb up
      distance = abs(labCoordinates.z - hidingSpotCoordinates.z);
      time += distance;
    }
    else
    {
      // Get the triangle distance
      double distanceToPoint = hypot(abs(hidingSpotCoordinates.x - labCoordinates.x), abs(hidingSpotCoordinates.y - labCoordinates.y));

      // Go all the way down
      distance = abs(hidingSpotCoordinates.z - labCoordinates.z);
      time += distance / 4;

      double distanceCovered = time * 3;
      if (distanceToPoint - distanceCovered > 0)
      {
        time += (distanceToPoint - distanceCovered) / 2;
      }
    }

    if (minimumTime == -1)
      minimumTime = time;
    else
      minimumTime = min(minimumTime, time);
    time = 0;
  }

  printf("%f\n", minimumTime);
}

int main()
{
  the5thLaboratory();
  return 0;
}