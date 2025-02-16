#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/triangle/description/
  Runtime: 100.00%
  Memory: 82.28%
******************************************/

int Triangle(vector<vector<int>> &triangle)
{
  vector<int> sums(triangle[triangle.size() - 1].size(), 0);
  for (int i = 0; i < sums.size(); ++i)
    sums[i] = triangle[triangle.size() - 1][i];

  for (int i = triangle.size() - 1; i > 0; --i)
    for (int j = 0; j < i; ++j)
      sums[j] = min(sums[j], sums[j + 1]) + triangle[i - 1][j];

  return sums[0];
}

int main()
{
  vector<vector<int>> triangle({{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}});
  cout << Triangle(triangle) << endl;
  return 0;
}