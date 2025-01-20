#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc08s3
  Points: 15/15
******************************************/

void maze()
{
  int numberOfTests, r, c;

  scanf("%d", &numberOfTests);

  vector<int> results(numberOfTests, -1);
  for (int i = 0; i < numberOfTests; ++i)
  {
    scanf("%d", &r);
    scanf("%d", &c);

    vector<vector<char>> grid(r, vector<char>(c));
    for (int j = 0; j < r; ++j)
      for (int k = 0; k < c; ++k)
        cin >> grid[j][k];

    queue<pair<pair<int, int>, int>> nextCoords;
    set<pair<int, int>> visited;
    nextCoords.push(pair<pair<int, int>, int>(pair<int, int>(0, 0), 1));

    while (!nextCoords.empty())
    {
      pair<int, int> currentCoords = nextCoords.front().first;
      int distance = nextCoords.front().second;
      char currentChar = grid[currentCoords.first][currentCoords.second];
      nextCoords.pop();

      if (visited.count(currentCoords) || currentChar == '*')
        continue;
      visited.insert(currentCoords);

      if (currentCoords.first == r - 1 && currentCoords.second == c - 1)
      {
        results[i] = distance;
        break;
      }

      if (currentChar == '+')
      {
        if (currentCoords.first - 1 >= 0)
          nextCoords.push(pair<pair<int, int>, int>(pair<int, int>(currentCoords.first - 1, currentCoords.second), distance + 1));
        if (currentCoords.first + 1 < r)
          nextCoords.push(pair<pair<int, int>, int>(pair<int, int>(currentCoords.first + 1, currentCoords.second), distance + 1));
        if (currentCoords.second - 1 >= 0)
          nextCoords.push(pair<pair<int, int>, int>(pair<int, int>(currentCoords.first, currentCoords.second - 1), distance + 1));
        if (currentCoords.second + 1 < c)
          nextCoords.push(pair<pair<int, int>, int>(pair<int, int>(currentCoords.first, currentCoords.second + 1), distance + 1));
      }
      else if (currentChar == '-')
      {
        if (currentCoords.second - 1 >= 0)
          nextCoords.push(pair<pair<int, int>, int>(pair<int, int>(currentCoords.first, currentCoords.second - 1), distance + 1));
        if (currentCoords.second + 1 < c)
          nextCoords.push(pair<pair<int, int>, int>(pair<int, int>(currentCoords.first, currentCoords.second + 1), distance + 1));
      }
      else
      {
        if (currentCoords.first - 1 >= 0)
          nextCoords.push(pair<pair<int, int>, int>(pair<int, int>(currentCoords.first - 1, currentCoords.second), distance + 1));
        if (currentCoords.first + 1 < r)
          nextCoords.push(pair<pair<int, int>, int>(pair<int, int>(currentCoords.first + 1, currentCoords.second), distance + 1));
      }
    }
  }

  for (int i = 0; i < numberOfTests; ++i)
    printf("%d\n", results[i]);
}

int main()
{
  maze();
  return 0;
}