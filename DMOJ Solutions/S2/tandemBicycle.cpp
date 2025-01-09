#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc16s2
  Points: 15/15
******************************************/

void tandemBicycle()
{
  int questionNumber, N;

  scanf("%d", &questionNumber);
  scanf("%d", &N);

  vector<int> dmojistan(N);
  vector<int> pegland(N);

  for (int i = 0; i < N; ++i)
    scanf("%d", &dmojistan[i]);

  sort(dmojistan.rbegin(), dmojistan.rend());

  for (int i = 0; i < N; ++i)
    scanf("%d", &pegland[i]);

  if (questionNumber == 1)
    sort(pegland.rbegin(), pegland.rend());
  else
    sort(pegland.begin(), pegland.end());

  int totalSpeed = 0;
  for (int i = 0; i < N; ++i)
    totalSpeed += max(dmojistan[i], pegland[i]);

  printf("%d", totalSpeed);
}

int main()
{
  tandemBicycle();
  return 0;
}