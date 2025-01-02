#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc03s3
  Points: 100/100
******************************************/

void floorPlan()
{
  int amountOfFlooring, r, c;
  scanf("%d", &amountOfFlooring);
  scanf("%d", &r);
  scanf("%d", &c);

  vector<vector<char>> grid(r, vector<char>(c));
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      cin >> grid[i][j];

  vector<int> roomSizes;
  for (int i = 0; i < r; ++i)
  {
    for (int j = 0; j < c; ++j)
    {
      if (grid[i][j] != '.')
        continue;
      queue<pair<int, int>> nextNodes;
      set<pair<int, int>> visited;

      nextNodes.push(pair<int, int>(i, j));
      int roomSize = 0;
      while (!nextNodes.empty())
      {
        pair<int, int> currentNode = nextNodes.front();
        nextNodes.pop();
        if (visited.count(currentNode) > 0)
          continue;
        visited.insert(currentNode);
        grid[currentNode.first][currentNode.second] = 'I';
        ++roomSize;

        if (currentNode.first - 1 >= 0 && grid[currentNode.first - 1][currentNode.second] != 'I')
          nextNodes.push(pair<int, int>(currentNode.first - 1, currentNode.second));
        if (currentNode.second - 1 >= 0 && grid[currentNode.first][currentNode.second - 1] != 'I')
          nextNodes.push(pair<int, int>(currentNode.first, currentNode.second - 1));
        if (currentNode.first + 1 < r && grid[currentNode.first + 1][currentNode.second] != 'I')
          nextNodes.push(pair<int, int>(currentNode.first + 1, currentNode.second));
        if (currentNode.second + 1 < c && grid[currentNode.first][currentNode.second + 1] != 'I')
          nextNodes.push(pair<int, int>(currentNode.first, currentNode.second + 1));
      }
      roomSizes.push_back(roomSize);
    }
  }

  sort(roomSizes.rbegin(), roomSizes.rend());

  int i = 0;
  for (; i < roomSizes.size(); ++i)
  {
    if (amountOfFlooring - roomSizes[i] >= 0)
      amountOfFlooring -= roomSizes[i];
    else
      break;
  }

  if (i == 1)
    printf("%d room, %d square metre(s) left over\n", i, amountOfFlooring);
  else
    printf("%d rooms, %d square metre(s) left over\n", i, amountOfFlooring);
}

int main()
{
  floorPlan();
  return 0;
}