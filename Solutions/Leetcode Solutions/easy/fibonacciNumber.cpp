#include "../../../helperFunctions.h"

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/fibonacci-number/description/
  Runtime: 77.95%
  Memory: 58.33%
******************************************/

int fibonacciNumber(int n)
{
  if (n == 0)
    return 0;

  int previous = 0;
  int current = 1;
  int i = 1;
  int temp = 0;
  while (i < n)
  {
    temp = current;
    current += previous;
    previous = temp;
    ++i;
  }

  return current;
}

int main()
{
  cout << fibonacciNumber(4) << endl;
  return 0;
}