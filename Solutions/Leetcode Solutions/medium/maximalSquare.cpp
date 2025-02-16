#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/maximal-square/description/
  Runtime: 53.92%
  Memory: 33.98%
******************************************/

int maximalSquare(vector<vector<char>> &matrix)
{
  int width = matrix[0].size();
  int height = matrix.size();
  int maxLength = INT_MIN;

  vector<vector<int>> dp(height, vector<int>(width, 0));
  for (int i = 0; i < height; ++i)
  {
    for (int j = 0; j < width; ++j)
    {
      if (matrix[i][j] == '1')
      {
        dp[i][j] = 1;
        if (i > 0 && j > 0)
          dp[i][j] += min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        maxLength = max(maxLength, dp[i][j]);
      }
    }
  }

  return maxLength * maxLength;
}

int main()
{
  vector<vector<char>> matrix({{'1', '1', '1', '1', '0'},
                               {'1', '1', '1', '1', '0'},
                               {'1', '1', '1', '1', '1'},
                               {'1', '1', '1', '1', '1'},
                               {'0', '0', '1', '1', '1'}});

  cout << maximalSquare(matrix) << endl;
  return 0;
}