#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc19s3
  Points: 16/16
  Inspiration: https://github.com/TommyPang/CCC-Solutions/blob/main/CCC19S3.java
******************************************/

void arithmeticSquare()
{
  int numberOfX = 0;
  string temp;
  vector<vector<int>> grid(3, vector<int>(3));
  vector<vector<bool>> x(3, vector<bool>(3, false));
  vector<int> rows(3, 0);
  vector<int> columns(3, 0);
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      cin >> temp;
      if (temp == "X")
      {
        x[i][j] = true;
        ++rows[i];
        ++columns[j];
        ++numberOfX;
      }
      else
        grid[i][j] = stoi(temp);
    }
  }

  while (numberOfX > 0)
  {
    bool doesNotFillableRowOrColumn = true;
    for (int i = 0; i < 3 && doesNotFillableRowOrColumn; ++i)
    {
      // If we only have one X in the row
      if (rows[i] == 1)
      {
        if (x[i][0])
        {
          grid[i][0] = grid[i][1] + (grid[i][1] - grid[i][2]);
          x[i][0] = false;
          --columns[0];
        }
        else if (x[i][1])
        {
          grid[i][1] = grid[i][0] + (grid[i][2] - grid[i][0]) / 2;
          x[i][1] = false;
          --columns[1];
        }
        else if (x[i][2])
        {
          grid[i][2] = grid[i][1] + (grid[i][1] - grid[i][0]);
          x[i][2] = false;
          --columns[2];
        }

        --numberOfX;
        --rows[i];
        doesNotFillableRowOrColumn = false;
      }
    }

    for (int i = 0; i < 3 && doesNotFillableRowOrColumn; ++i)
    {
      // If we only have one X in the column
      if (columns[i] == 1)
      {
        if (x[0][i])
        {
          grid[0][i] = grid[1][i] + (grid[1][i] - grid[2][i]);
          x[0][i] = false;
          --rows[0];
        }
        else if (x[1][i])
        {
          grid[1][i] = grid[0][i] + (grid[2][i] - grid[0][i]) / 2;
          x[1][i] = false;
          --rows[1];
        }
        else if (x[2][i])
        {
          grid[2][i] = grid[1][i] + (grid[1][i] - grid[0][i]);
          x[2][i] = false;
          --rows[2];
        }

        --numberOfX;
        --columns[i];
        doesNotFillableRowOrColumn = false;
      }
    }

    if (doesNotFillableRowOrColumn && x[1][1])
    {
      grid[1][1] = 1;
      x[1][1] = false;
      --rows[1];
      --columns[1];
      --numberOfX;
      doesNotFillableRowOrColumn = false;
    }
    if (doesNotFillableRowOrColumn && x[1][0])
    {
      grid[1][0] = 1;
      x[1][0] = false;
      --rows[1];
      --columns[0];
      --numberOfX;
      doesNotFillableRowOrColumn = false;
    }
    if (doesNotFillableRowOrColumn && x[1][2])
    {
      grid[1][2] = 1;
      x[1][2] = false;
      --rows[1];
      --columns[2];
      --numberOfX;
      doesNotFillableRowOrColumn = false;
    }
    if (doesNotFillableRowOrColumn && x[0][1])
    {
      grid[0][1] = 1;
      x[0][1] = false;
      --rows[0];
      --columns[1];
      --numberOfX;
      doesNotFillableRowOrColumn = false;
    }
    if (doesNotFillableRowOrColumn && x[2][1])
    {
      grid[2][1] = 1;
      x[2][1] = false;
      --rows[2];
      --columns[1];
      --numberOfX;
      doesNotFillableRowOrColumn = false;
    }
    if (doesNotFillableRowOrColumn && x[0][0])
    {
      grid[0][0] = 1;
      x[0][0] = false;
      --rows[0];
      --columns[0];
      --numberOfX;
      doesNotFillableRowOrColumn = false;
    }
  }

  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
      printf("%d ", grid[i][j]);
    printf("\n");
  }
}

int main()
{
  arithmeticSquare();
  return 0;
}