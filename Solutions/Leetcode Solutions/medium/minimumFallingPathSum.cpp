#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/minimum-falling-path-sum/description/
  Runtime: 100.00%
  Memory: 91.04%
******************************************/

int minimumFallingPathSum(vector<vector<int>> &matrix)
{
  int width = matrix[0].size();
  int height = matrix.size();

  vector<int> row = matrix[height - 1];

  for (int i = height - 2; i >= 0; --i)
  {
    for (int j = 0; j < width; ++j)
    {
      int minSum = INT_MAX;
      for (int k = (j > 0 ? j - 1 : 0); k <= (j < width - 1 ? j + 1 : j); ++k)
        minSum = min(minSum, row[k] + matrix[i][j]);
      matrix[i][j] = minSum;
    }
    row = matrix[i];
  }

  int minElement = INT_MAX;
  for (int i = 0; i < row.size(); ++i)
    minElement = min(minElement, row[i]);
  return minElement;
}

int main()
{
  vector<vector<int>> matrix({{100, -42, -46, -41}, {31, 97, 10, -10}, {-58, -51, 82, 89}, {51, 81, 69, -51}});
  cout << minimumFallingPathSum(matrix) << endl;
  return 0;
}