#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/unique-paths-ii/description/
  Runtime: 100.00%
  Memory: 89.22%
******************************************/

int uniquePaths2(vector<vector<int>> &obstacleGrid)
{
  int width = obstacleGrid[0].size();
  int height = obstacleGrid.size();

  if (obstacleGrid[height - 1][width - 1] == 1 || obstacleGrid[0][0] == 1)
    return 0;

  vector<int> previousRow(width, 1);
  for (int i = width - 2; i >= 0; --i)
  {
    previousRow[i] = previousRow[i + 1];
    if (obstacleGrid[height - 1][i] == 1)
      previousRow[i] = 0;
  }

  int right = 0;
  for (int i = height - 2; i >= 0; --i)
  {
    if (obstacleGrid[i][width - 1] == 1)
      right = 0;
    else
      right = previousRow[width - 1];
    previousRow[width - 1] = right;
    for (int j = width - 2; j >= 0; --j)
    {
      if (obstacleGrid[i][j] == 1)
        previousRow[j] = 0;
      else
        previousRow[j] += right;
      right = previousRow[j];
    }
  }

  return previousRow[0];
}

int main()
{
  vector<vector<int>> obstacles({{0, 0}, {1, 1}, {0, 0}});
  cout << uniquePaths2(obstacles) << endl;
  return 0;
}