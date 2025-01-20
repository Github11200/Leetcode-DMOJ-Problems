#include "../../../helperFunctions.h"

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/n-th-tribonacci-number/description/
  Runtime: 100.0%
  Memory: 78.23%
******************************************/

int nthTribonacciNumber(int n)
{
  if (n == 0)
    return 0;
  else if (n == 1 || n == 2)
    return 1;

  int t0 = 0;
  int t1 = 1;
  int t2 = 1;

  int i = 3;
  while (i < n + 1)
  {
    int next = t0 + t1 + t2;
    t0 = t1;
    t1 = t2;
    t2 = next;
    ++i;
  }

  return t2;
}

int main()
{
  cout << nthTribonacciNumber(4) << endl;
  return 0;
}