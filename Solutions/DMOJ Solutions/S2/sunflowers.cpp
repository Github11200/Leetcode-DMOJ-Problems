#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc18s2
  Points: 15/15
******************************************/

void sunflowers()
{
  int N;
  scanf("%d", &N);

  vector<vector<int>> grid(N, vector<int>(N, 0));
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      cin >> grid[i][j];

  bool isRowWrong = false;
  for (int i = 1; i < N; ++i)
  {
    if (grid[0][i] < grid[0][i - 1])
    {
      isRowWrong = true;
      break;
    }
  }

  bool isColumnWrong = false;
  for (int i = 1; i < N; ++i)
  {
    if (grid[i][0] < grid[i - 1][0])
    {
      isColumnWrong = true;
      break;
    }
  }

  set<pair<int, int>> previousCoordinates;
  if (isRowWrong && isColumnWrong)
  {
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        if (previousCoordinates.count(pair<int, int>(i, j)) == 0)
        {
          swap(grid[i][j], grid[N - 1 - i][N - 1 - j]);
          previousCoordinates.insert(pair<int, int>(N - 1 - i, N - 1 - j));
        }
      }
    }
  }
  else if (!isRowWrong && isColumnWrong)
  {
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        if (previousCoordinates.count(pair<int, int>(i, j)) == 0)
        {
          swap(grid[i][j], grid[j][N - 1 - i]);
          previousCoordinates.insert(pair<int, int>(j, N - 1 - i));
        }
      }
    }
  }
  else if (isRowWrong && !isColumnWrong)
  {
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        if (previousCoordinates.count(pair<int, int>(i, j)) == 0)
        {
          swap(grid[i][j], grid[N - 1 - j][i]);
          previousCoordinates.insert(pair<int, int>(N - 1 - j, i));
        }
      }
    }
  }

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
      printf("%d ", grid[i][j]);
    printf("\n");
  }
}

int main()
{
  sunflowers();
  return 0;
}