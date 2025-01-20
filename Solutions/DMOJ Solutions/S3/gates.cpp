#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc15s3
  Points: 30/30
******************************************/

void gates()
{
  int numberOfGates, numberOfPlanes;
  scanf("%d", &numberOfGates);
  scanf("%d", &numberOfPlanes);

  vector<int> gatesToDock(numberOfPlanes);
  for (int i = 0; i < numberOfPlanes; ++i)
    scanf("%d", &gatesToDock[i]);

  vector<bool> gates(numberOfGates, false);
  set<int, greater<int>> freeGates;
  for (int i = 1; i <= numberOfGates; ++i)
    freeGates.insert(i);

  int numberOfPlanesDocked = 0;
  for (int i = 0; i < gatesToDock.size(); ++i)
  {
    auto result = freeGates.lower_bound(gatesToDock[i]);
    if (result == freeGates.end())
      break;
    ++numberOfPlanesDocked;
    freeGates.erase(*result);
  }

  printf("%d", numberOfPlanesDocked);
}

int main()
{
  gates();
  return 0;
}