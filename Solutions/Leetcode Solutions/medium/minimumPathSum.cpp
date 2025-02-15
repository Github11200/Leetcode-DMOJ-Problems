#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/minimum-path-sum/description/
  Runtime: 100.00%
  Memory: 75.54%
******************************************/

int minimumPathSum(vector<vector<int>> &grid)
{
  vector<int> current(grid[0].size(), 0);
  current[grid[0].size() - 1] = grid[grid.size() - 1][grid[0].size() - 1];
  for (int i = grid[0].size() - 2; i >= 0; --i)
    current[i] = grid[grid.size() - 1][i] + current[i + 1];

  int right = 0;
  int initialRight = 0;
  for (int i = grid.size() - 2; i >= 0; --i)
  {
    initialRight = current[grid[0].size() - 1] + grid[i][grid[0].size() - 1];
    right = current[grid[0].size() - 1] + grid[i][grid[0].size() - 1];
    for (int j = grid[0].size() - 2; j >= 0; --j)
    {
      current[j] = min(grid[i][j] + current[j], grid[i][j] + right);
      right = current[j];
    }
    current[grid[0].size() - 1] = initialRight;
  }

  return current[0];
}

int main()
{
  vector<vector<int>> grid({{1, 2}, {5, 6}, {1, 1}});
  cout << minimumPathSum(grid) << endl;
  return 0;
}