#include "../../../helperFunctions.h"

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/excel-sheet-column-number/description/
  Runtime: 100.0%
  Memory: 45.31%
******************************************/

int titleToNumber(string columnTitle)
{
  int sum = 0;
  int power = 0;
  for (int i = columnTitle.size() - 1; i >= 0; --i)
  {
    sum += (((int)columnTitle[i] - 64)) * pow(26, power);
    ++power;
  }
  return sum;
}

int main()
{
  cout << titleToNumber("AB") << endl;
  return 0;
}