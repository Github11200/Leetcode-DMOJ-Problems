#include <bits/stdc++.h>

using namespace std;

/*******************************************************************************************
  Link: https://dmoj.ca/problem/ccc05s3
  Points: 15/15
  Inspiration: https://github.com/kingMonkeh/CCC-Solutions/blob/main/2005%20S3.cpp
*******************************************************************************************/

void quantumOperations()
{
  int N, ARows, AColumns, BRows, BColumns;
  scanf("%d", &N);

  vector<vector<int>> A, B;

  scanf("%d %d", &ARows, &AColumns);
  A.resize(ARows, vector<int>(AColumns));
  for (int i = 0; i < ARows; ++i)
    for (int j = 0; j < AColumns; ++j)
      scanf("%d", &A[i][j]);

  for (int i = 0; i < N - 1; ++i)
  {
    scanf("%d %d", &BRows, &BColumns);
    B.clear();
    B.resize(BRows, vector<int>(BColumns));
    for (int i = 0; i < BRows; ++i)
      for (int j = 0; j < BColumns; ++j)
        scanf("%d", &B[i][j]);

    vector<vector<int>> ACopy = A;
    A.clear();
    A.resize(ARows * BRows, vector<int>(AColumns * BColumns));
    for (int j = 0; j < ACopy.size(); ++j)
      for (int k = 0; k < ACopy[j].size(); ++k)
        for (int m = 0; m < B.size(); ++m)
          for (int n = 0; n < B[m].size(); ++n)
            A[m + BRows * j][n + BColumns * k] = ACopy[j][k] * B[m][n];

    ARows *= BRows;
    AColumns *= BColumns;
  }

  int maximumElement = INT_MIN;
  int minimumElement = INT_MAX;
  int maximumRowSum = INT_MIN;
  int minimumRowSum = INT_MAX;
  int maximumColumnSum = INT_MIN;
  int minimumColumnSum = INT_MAX;

  vector<int> rowSums(A.size(), 0);
  vector<int> columnSums(A[0].size(), 0);

  for (int i = 0; i < A.size(); ++i)
  {
    for (int j = 0; j < A[i].size(); ++j)
    {
      maximumElement = max(maximumElement, A[i][j]);
      minimumElement = min(minimumElement, A[i][j]);

      rowSums[i] += A[i][j];
      columnSums[j] += A[i][j];
    }
  }

  for (int i = 0; i < rowSums.size(); ++i)
  {
    maximumRowSum = max(maximumRowSum, rowSums[i]);
    minimumRowSum = min(minimumRowSum, rowSums[i]);
  }

  for (int i = 0; i < columnSums.size(); ++i)
  {
    maximumColumnSum = max(maximumColumnSum, columnSums[i]);
    minimumColumnSum = min(minimumColumnSum, columnSums[i]);
  }

  printf("%d\n", maximumElement);
  printf("%d\n", minimumElement);
  printf("%d\n", maximumRowSum);
  printf("%d\n", minimumRowSum);
  printf("%d\n", maximumColumnSum);
  printf("%d\n", minimumColumnSum);
}

int main()
{
  quantumOperations();
  return 0;
}