#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc02s3
  Points: 100/150
******************************************/

void blindfold()
{
  int r, c, m;

  scanf("%d", &r);
  scanf("%d", &c);

  vector<vector<char>> backyard(r, vector<char>(c));
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      cin >> backyard[i][j];

  scanf("%d", &m);
  vector<char> moves(m);
  for (int i = 0; i < m; ++i)
    cin >> moves[i];

  set<pair<int, int>> invalidPositions;
  for (int i = 0; i < r; ++i)
  {
    for (int j = 0; j < c; ++j)
    {
      if (backyard[i][j] == 'X' && invalidPositions.count(pair<int, int>(i, j)) > 0)
        continue;
      for (int k = 0; k < 4; ++k)
      {
        // 0 -> up, 1 -> right, 2 -> down, 3 -> left
        int direction = k;
        int currentRow = i;
        int currentColumn = j;
        bool canMove = true;
        for (auto move : moves)
        {
          if (move == 'F')
          {
            switch (direction)
            {
            case 0:
              --currentRow;
            case 1:
              ++currentColumn;
              break;
            case 2:
              ++currentRow;
              break;
            case 3:
              --currentColumn;
              break;
            default:
              break;
            }
          }
          else if (move == 'R')
          {
            ++direction;
            if (direction == 4)
              direction = 0;
          }
          else
          {
            --direction;
            if (direction == -1)
              direction = 3;
          }
          if (currentRow < 0 || currentRow == r || currentColumn < 0 || currentColumn > c || backyard[currentRow][currentColumn] == 'X')
          {
            canMove = false;
            invalidPositions.insert(pair<int, int>(currentRow, currentColumn));
            break;
          }
        }
        if (canMove)
          backyard[currentRow][currentColumn] = '*';
      }
    }
  }

  for (int i = 0; i < r; ++i)
  {
    for (int j = 0; j < c; ++j)
      printf("%c", backyard[i][j]);
    printf("\n");
  }
}

int main()
{
  blindfold();
  return 0;
}