#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc21s2
  Points: 15/15
******************************************/

void modernArt()
{
  int M, N, K;

  scanf("%d", &M);
  scanf("%d", &N);
  scanf("%d", &K);

  // 0 -> Black
  // 1 -> Gold
  vector<bool> rows(M, false);
  vector<bool> columns(N, false);
  int numberOfGold = 0;
  for (int i = 0; i < K; ++i)
  {
    char rowOrColumn;
    int rowOrColumnNumber;
    cin >> rowOrColumn >> rowOrColumnNumber;
    --rowOrColumnNumber;

    if (rowOrColumn == 'R')
      rows[rowOrColumnNumber] = !rows[rowOrColumnNumber];
    else
      columns[rowOrColumnNumber] = !columns[rowOrColumnNumber];
  }

  int numberOfRowsOn = 0;
  for (int i = 0; i < rows.size(); ++i)
  {
    if (rows[i])
    {
      ++numberOfRowsOn;
      numberOfGold += N;
    }
  }

  for (int i = 0; i < columns.size(); ++i)
  {
    if (columns[i])
      numberOfGold += M - (numberOfRowsOn * 2);
  }

  printf("%d", numberOfGold);
}

int main()
{
  modernArt();
  return 0;
}