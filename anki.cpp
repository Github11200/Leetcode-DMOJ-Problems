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

int jumpGame2(vector<int> nums)
{
  int left = 0;
  int right = 0;
  int numberOfJumps = 0;
  while (right < nums.size())
  {
    int farthest = 0;
    for (int i = left; i < right; ++i)
      farthest = max(farthest, i + nums[i]);
    left = right + 1;
    right = farthest;
    ++numberOfJumps;
  }

  return numberOfJumps;
}

void arithmeticSquare()
{
  vector<vector<int>> grid(3, vector<int>(3, 0));
  vector<vector<bool>> x(3, vector<bool>(3, false));
  vector<int> rows(3), columns(3);
  int numberOfXs = 0;

  for (int i = 0; i < 3; ++i)
  {
    string temp;
    for (int j = 0; j < 3; ++j)
    {
      cin >> temp;
      if (temp == "X")
      {
        ++numberOfXs;
        x[i][j] = true;
        ++rows[i];
        ++columns[j];
      }
      else
        grid[i][j] = stoi(temp);
    }
  }

  while (numberOfXs > 0)
  {
    bool shouldNotRestart = true;
    for (int i = 0; i < 3 && shouldNotRestart; ++i)
    {
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
          grid[i][1] = grid[i][0] + ((grid[i][2] - grid[i][0]) / 2);
          x[i][1] = false;
          --columns[1];
        }
        else if (x[i][2])
        {
          grid[i][2] = grid[i][1] + (grid[i][1] - grid[i][0]);
          x[i][2] = false;
          --columns[2];
        }
        --numberOfXs;
        shouldNotRestart = false;
        --rows[i];
      }
    }

    for (int i = 0; i < 3 && shouldNotRestart; ++i)
    {
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
          grid[1][i] = grid[0][i] + ((grid[2][i] - grid[0][i]) / 2);
          x[1][i] = false;
          --rows[1];
        }
        else if (x[2][i])
        {
          grid[2][i] = grid[1][i] + (grid[1][i] - grid[0][i]);
          x[2][i] = false;
          --rows[2];
        }
        --numberOfXs;
        shouldNotRestart = false;
        --columns[i];
      }
    }

    if (x[0][0] && shouldNotRestart)
    {
      x[0][0] = false;
      grid[0][0] = 0;
      --numberOfXs;
      shouldNotRestart = false;
      --rows[0];
      --columns[0];
    }
    if (x[1][1] && shouldNotRestart)
    {
      x[1][1] = false;
      grid[1][1] = 0;
      --numberOfXs;
      shouldNotRestart = false;
      --rows[1];
      --columns[1];
    }
    if (x[0][1] && shouldNotRestart)
    {
      x[0][1] = false;
      grid[0][1] = 0;
      --numberOfXs;
      shouldNotRestart = false;
      --rows[0];
      --columns[1];
    }
    if (x[1][0] && shouldNotRestart)
    {
      x[1][0] = false;
      grid[1][0] = 0;
      --numberOfXs;
      shouldNotRestart = false;
      --rows[1];
      --columns[0];
    }
    if (x[1][2] && shouldNotRestart)
    {
      x[1][2] = false;
      grid[1][2] = 0;
      --numberOfXs;
      shouldNotRestart = false;
      --rows[1];
      --columns[2];
    }
    if (x[2][1] && shouldNotRestart)
    {
      x[2][1] = false;
      grid[2][1] = 0;
      --numberOfXs;
      shouldNotRestart = false;
      --rows[2];
      --columns[1];
    }
  }

  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
      printf("%d ", grid[i][j]);
    printf("\n");
  }
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
    if (i == 0 || B[i - 1] != B[i])
    {
      BPrime.push_back(B[i]);
      firstOccurrences.push_back(i);
      lastOccurrences.push_back(i);
    }
    else if (i > 0 && B[i - 1] == B[i])
      ++lastOccurrences[lastOccurrences.size() - 1];
  }

  int j = 0;
  for (int i = 0; i < N; ++i)
    if (A[i] == BPrime[j])
      ++j;

  if (j == BPrime.size())
    printf("YES\n");
  else
  {
    printf("NO\n");
    return;
  }

  vector<pair<int, int>> leftSwipes, rightSwipes;
  j = 0;
  for (int i = 0; i < N; ++i)
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

  printf("%d\n", rightSwipes.size() + leftSwipes.size());
  for (int i = 0; i < rightSwipes.size(); ++i)
    printf("R %d %d\n", rightSwipes[i].first, rightSwipes[i].second);
  for (int i = 0; i < leftSwipes.size(); ++i)
    printf("L %d %d\n", leftSwipes[i].first, leftSwipes[i].second);
}

void nailedIt()
{
  int N;
  scanf("%d", &N);

  vector<int> counts(2001);
  for (int i = 0; i < N; ++i)
  {
    int temp;
    scanf("%d", &temp);
    ++counts[temp];
  }

  vector<int> combinations(4001);
  for (int i = 0; i < counts.size(); ++i)
  {
    if (counts[i] == 0)
      continue;
    if (counts[i] > 1)
      combinations[i * 2] = counts[i] / 2;
    for (int j = i + 1; j < counts.size(); ++j)
    {
      if (counts[j] == 0)
        continue;
      combinations[i + j] += max(counts[i], counts[j]);
    }
  }

  int maxLength = 0;
  int height = 0;
  for (int i = 0; i < combinations.size(); ++i)
  {
    if (combinations[i] > maxLength)
    {
      maxLength = combinations[i];
      height = 1;
    }
    else if (combinations[i] == maxLength)
      ++height;
  }

  printf("%d %d", maxLength, height);
}

string addBinary(string a, string b)
{
  int i = a.size() - 1;
  int j = b.size() - 1;
  int carry = 0;

  string c = "";

  while (i >= 0 || j >= 0 || carry >= 0)
  {
    if (i >= 0 && a[i] == '1')
      ++carry;
    if (j >= 0 && b[j] == '1')
      ++carry;

    c += to_string(carry % 2);
    carry /= 2;
    --i;
    --j;
  }

  return c;
}

int main()
{
  nailedIt();
  return 0;
}