#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link:
  Points:
******************************************/

void flipper()
{
  string input;
  cin >> input;

  vector<vector<int>> grid = {{1, 2}, {3, 4}};

  for (int i = 0; i < input.size(); ++i)
  {
    if (input[i] == 'H')
    {
      swap(grid[0][0], grid[1][0]);
      swap(grid[0][1], grid[1][1]);
    }
    else
    {
      swap(grid[0][0], grid[0][1]);
      swap(grid[1][0], grid[1][1]);
    }
  }

  for (int i = 0; i < 2; ++i)
  {
    for (int j = 0; j < 2; ++j)
      printf("%d ", grid[i][j]);
    printf("\n");
  }
}

int main()
{
  flipper();
  return 0;
}