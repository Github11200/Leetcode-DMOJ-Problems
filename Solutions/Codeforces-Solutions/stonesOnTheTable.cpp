#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://codeforces.com/problemset/problem/266/A
  Points: Accepted
******************************************/

int main()
{
  int n;
  scanf("%d", &n);
  int numberToRemove = 0;
  char previousInput;
  char input;
  for (int i = 0; i < n; ++i)
  {
    cin >> input;
    if (i > 0 && input == previousInput)
      ++numberToRemove;
    previousInput = input;
  }

  printf("%d", numberToRemove);

  return 0;
}
