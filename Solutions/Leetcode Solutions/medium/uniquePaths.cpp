#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/unique-paths/description/
  Runtime: 100.0%
  Memory: 83.19%
******************************************/

int uniquePaths(int m, int n)
{
  if (m == 1 || n == 1)
    return 1;

  vector<int> current(n, 1);
  int right = 1;
  for (int i = m - 2; i >= 0; --i)
  {
    right = 1;
    for (int j = n - 2; j >= 0; --j)
    {
      current[j] += right;
      right = current[j];
    }
  }

  return current[0];
}

int main()
{
  cout << uniquePaths(3, 7) << endl;
  return 0;
}