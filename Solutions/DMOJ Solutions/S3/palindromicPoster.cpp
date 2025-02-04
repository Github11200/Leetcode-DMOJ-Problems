#include <bits/stdc++.h>

using namespace std;

/*******************************************************************************************
  Link:
  Points:
*******************************************************************************************/

int N, M, R, C;
vector<vector<char>> res;
bool wasFlipped = false;

void display()
{
  if (wasFlipped)
  {
    for (int i = M - 1; i >= 0; --i)
    {
      for (int j = 0; j < N; ++j)
        printf("%c ", res[j][i]);
      printf("\n");
    }
  }
  else
  {
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < M; ++j)
        printf("%c ", res[i][j]);
      printf("\n");
    }
  }
}

void palindromicPoster()
{
  scanf("%d %d %d %d", &N, &M, &R, &C);

  if (C == M || C == 0)
  {
    swap(N, M);
    swap(R, C);
    wasFlipped = true;
  }

  res = vector<vector<char>>(N, vector<char>(M, 'a'));

  if (R == 0 && N == 0)
  {
    int letter = 0;
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < M; ++j)
      {
        res[i][j] = char(letter + 97);
        ++letter;
        letter %= 26;
      }
      letter += (i + 1) * 3;
      letter %= 26;
    }
  }
  if (R == N)
  {
    if (M % 2 == 0 && C % 2 != 0)
    {
      printf("IMPOSSIBLE\n");
      return;
    }
    int numberOfColumns = M;
    int i = 0;
    int j = M - 1;
    while (i <= j && numberOfColumns > 0)
    {
      res[0][i] = 'b';
      res[0][j] = 'b';
      i += 2;
      j -= 2;
      if (i == j)
        --numberOfColumns;
      else
        numberOfColumns -= 2;
    }
  }
  else if (R == N && C == M)
  {
    display();
    return;
  }
  else if (R == 0)
  {
    // Set the last column to 'b'
    for (int i = 0; i < N; ++i)
      res[i][M - 1] = 'b';
    // Set the last M - C characters to one character higher
    int lowerBound = (M - 1) - (M - C);
    for (int i = M - 1; i > lowerBound; --i)
      ++res[N - 1][i];
  }
  else
  {
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < M; ++j)
        res[i][j] = 'b';

    for (int i = 0; i < C; ++i)
      for (int j = 0; j < N; ++j)
        res[j][i] = 'b';
  }

  display();
}

int main()
{
  palindromicPoster();
  return 0;
}