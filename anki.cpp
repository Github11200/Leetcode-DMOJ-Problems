#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <numeric>
#include <math.h>
#include <set>
#include <bits/stdc++.h>

using namespace std;

string addBinary(string a, string b)
{
  int i = a.size() - 1;
  int j = b.size() - 1;
  int carry = 0;

  string c = "";
  while (i >= 0 || j >= 0 || carry != 0)
  {
    if (i >= 0 && a[i] == '1')
      ++carry;
    if (j >= 0 && b[j] == '1')
      ++carry;

    c = to_string(carry % 2) + c;
    carry /= 2;
    --i;
    --j;
  }

  return c;
}

void swipe()
{
  int N;
  scanf("%d", &N);

  vector<int> A(N), B(N), BPrime, firstOccurrences, lastOccurrences;
  for (int i = 0; i < N; ++i)
    scanf("%d", &A[i]);
  for (int i = 0; i < N; ++i)
  {
    scanf("%d", &B[i]);
    if (i == 0 || B[i] != B[i - 1])
    {
      BPrime.push_back(B[i]);
      firstOccurrences.push_back(i);
      lastOccurrences.push_back(i);
    }
    else if (i > 0 && B[i] == B[i - 1])
      ++lastOccurrences[lastOccurrences.size() - 1];
  }

  int j = 0;
  for (int i = 0; i < A.size(); ++i)
    if (A[i] == BPrime[j])
      ++j;

  if (j == BPrime.size())
    printf("YES\n");
  else
  {
    printf("NO\n");
    return;
  }

  j = 0;
  vector<pair<int, int>> leftSwipes, rightSwipes;
  for (int i = 0; i < A.size(); ++i)
  {
    if (A[i] == BPrime[j])
    {
      if (i < lastOccurrences[j])
        rightSwipes.push_back(pair<int, int>(i, lastOccurrences[j]));
      if (i > firstOccurrences[j])
        leftSwipes.push_back(pair<int, int>(firstOccurrences[j], i));
      ++j;
    }
  }

  sort(rightSwipes.rbegin(), rightSwipes.rend());
  sort(leftSwipes.begin(), leftSwipes.end());

  printf("%d\n", leftSwipes.size() + rightSwipes.size());
  for (int i = 0; i < rightSwipes.size(); ++i)
    printf("R %d %d", rightSwipes[i].first, rightSwipes[i].second);
  for (int i = 0; i < leftSwipes.size(); ++i)
    printf("L %d %d", leftSwipes[i].first, leftSwipes[i].second);
}

void arithmeticSquare()
{
  vector<vector<int>> grid(3, vector<int>(3, 0));
  vector<vector<bool>> x(3, vector<bool>(3, false));
  vector<int> rows(3, 0), columns(3, 0);
  int numberOfXs = 0;

  string temp;
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
        ++numberOfXs;
      }
      else
        grid[i][j] = stoi(temp);
    }
  }

  while (numberOfXs > 0)
  {
    bool hasNotChanged = true;
    for (int i = 0; i < 3 && hasNotChanged; ++i)
    {
      if (rows[i] == 1)
      {
        if (x[i][0])
        {
          grid[i][0] = grid[i][1] + (grid[i][1] - grid[i][2]);
          x[i][0] = false;
          --columns[0];
        }
        if (x[i][1])
        {
          grid[i][1] = grid[i][0] + ((grid[i][2] - grid[i][0]) / 2);
          x[i][1] = false;
          --columns[1];
        }
        if (x[i][2])
        {
          grid[i][2] = grid[i][1] + (grid[i][1] - grid[i][0]);
          x[i][2] = false;
          --columns[2];
        }
        --numberOfXs;
        --rows[i];
        hasNotChanged = false;
      }
    }

    for (int i = 0; i < 3 && hasNotChanged; ++i)
    {
      if (columns[i] == 1)
      {
        if (x[0][i])
        {
          grid[0][i] = grid[1][i] + (grid[1][i] - grid[2][i]);
          x[0][i] = false;
          --rows[0];
        }
        if (x[1][i])
        {
          grid[1][i] = grid[0][i] + ((grid[2][i] - grid[0][i]) / 2);
          x[1][i] = false;
          --rows[1];
        }
        if (x[2][i])
        {
          grid[2][i] = grid[1][i] + (grid[1][i] - grid[0][i]);
          x[2][i] = false;
          --rows[2];
        }
        --numberOfXs;
        --columns[i];
        hasNotChanged = false;
      }
    }

    if (x[0][0] && hasNotChanged)
    {
      grid[0][0] = 0;
      x[0][0] = false;
      --rows[0];
      --columns[0];
      --numberOfXs;
        }
    if (x[1][1] && hasNotChanged)
    {
      grid[1][1] = 0;
      x[1][1] = false;
      --rows[1];
      --columns[1];
      --numberOfXs;
    }
    if (x[0][1] && hasNotChanged)
    {
      grid[0][1] = 0;
      x[0][1] = false;
      --rows[0];
      --columns[1];
      --numberOfXs;
    }
    if (x[1][0] && hasNotChanged)
    {
      grid[1][0] = 0;
      x[1][0] = false;
      --rows[1];
      --columns[0];
      --numberOfXs;
    }
    if (x[1][2] && hasNotChanged)
    {
      grid[1][2] = 0;
      x[1][2] = false;
      --rows[1];
      --columns[2];
      --numberOfXs;
    }
    if (x[2][1] && hasNotChanged)
    {
      grid[2][1] = 0;
      x[2][1] = false;
      --rows[2];
      --columns[1];
      --numberOfXs;
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