#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/string-to-integer-atoi/description/
  Runtime: 100.00%
  Memory: 82.37%
  Inspiration: https://leetcode.com/problems/string-to-integer-atoi/solutions/4445711/beats-100-of-users-with-c-best-solution-fast-solution-easy-to-understand/
******************************************/

int stringToInteger(string s)
{
  int result = 0;
  bool sign = false;
  int i = 0;
  while (i < s.size())
  {
    if (s[i] == ' ')
      ++i;
    else
      break;
  }

  if (s[i] == '+')
  {
    sign = true;
    ++i;
  }
  if (s[i] == '-')
  {
    sign = false;
    ++i;
  }
  long answer = 0;
  for (; i < s.size(); ++i)
  {
    if (isdigit(s[i]))
    {
      answer = answer * 10 + (s[i] - '0');
      if (answer > INT_MAX && sign)
        return INT_MAX;
      if (answer > INT_MAX && !sign)
        return INT_MIN;
    }
    else
      return answer * (sign ? 1 : -1);
  }
  return answer * (sign ? 1 : -1);
}

int main()
{
  cout << stringToInteger("-91283472332") << endl;
  return 0;
}