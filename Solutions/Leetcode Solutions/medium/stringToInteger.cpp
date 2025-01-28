#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link:
  Runtime:
  Memory:
******************************************/

int stringToInteger(string s)
{
  int result = NULL;
  vector<int> digits;
  int sign = 1;
  for (int i = 0; i < s.size(); ++i)
  {
    if (s[i] == ' ')
      continue;

    // It's a negative
    if (int(s[i]) == 45)
      sign *= -1;
    // It's a positive
    else if (int(s[i]) == 43)
      sign *= 1;
    else if (int(s[i]) >= 48 && int(s[i]) <= 57)
      digits.push_back(s[i] - '0');

    // Not an integer
    if (int(s[i]) < 48 || int(s[i]) > 57 || (i < s.size() - 1 && (int(s[i + 1]) < 48 || int(s[i + 1]) > 57)))
      break;
  }

  result = 0;
  for (int i = digits.size() - 1; i >= 0; --i)
    result += digits[i] * pow(10, digits.size() - 1 - i);

  return result * sign;
}

int main()
{
  cout << stringToInteger("1337c0d3") << endl;
  return 0;
}