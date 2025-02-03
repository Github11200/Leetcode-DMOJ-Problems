#include "../../../helperFunctions.h"

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/decode-ways/description/
  Runtime: 100.00%
  Memory: 90.44%
******************************************/

int decodeWays(string s)
{
  int temp = 1;
  int current = 1;
  int next = 1;
  for (int i = s.size() - 1; i >= 0; --i)
  {
    if (s[i] == '0')
    {
      next = current;
      temp = 0;
      current = 0;
      continue;
    }
    temp = current;
    if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && int(s[i + 1]) <= 54)))
      temp += next;
    next = current;
    current = temp;
  }
  return temp;
}

int main()
{
  cout << decodeWays("226") << endl;
  return 0;
}