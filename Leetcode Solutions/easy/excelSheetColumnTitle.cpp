#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/excel-sheet-column-title/description/
  Runtime: 100.0%
  Memory: 82.11%
******************************************/

string excelSheetColumnTitle(int columnNumber)
{
  if (columnNumber <= 26)
  {
    if (columnNumber == 0)
      return "Z";
    int asciiVal = 64 + columnNumber;
    string res = "";
    res += char(asciiVal);
    return res;
  }

  int numberOne = floor(columnNumber / 26);
  int numberTwo = columnNumber % 26;

  if (numberTwo == 0)
    return excelSheetColumnTitle(numberOne - 1) + "Z";
  return excelSheetColumnTitle(numberOne) + excelSheetColumnTitle(numberTwo);
}

int main()
{
  cout << excelSheetColumnTitle(701) << endl;
  return 0;
}