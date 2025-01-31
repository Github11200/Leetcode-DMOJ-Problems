#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link:
  Runtime:
  Memory:
******************************************/

string longestPalindromicSubstring(string s)
{
  int farthestLeft = 1;
  int farthestRight = 0;
  int i = 0;
  for (; i < s.size(); ++i)
  {
    int j = i;
    int k = i;
    while (j >= 0 && k < s.size())
    {
      if (s[j] == s[k])
      {
        if (k - j > farthestRight - farthestLeft)
        {
          farthestLeft = j;
          farthestRight = k;
        }
      }
      else if (s[j] != s[k])
        break;
      --j;
      ++k;
    }
  }

  i = 0;
  for (; i < s.size(); ++i)
  {
    int j = i;
    int k = i + 1;
    while (j >= 0 && k < s.size())
    {
      if (s[j] == s[k])
      {
        if (k - j > farthestRight - farthestLeft)
        {
          farthestLeft = j;
          farthestRight = k;
        }
      }
      else if (s[j] != s[k])
        break;
      --j;
      ++k;
    }
  }

  string longestPalindrome = "";
  for (int i = farthestLeft; i <= farthestRight; ++i)
    longestPalindrome += s[i];
  return longestPalindrome;
}

int main()
{
  cout << longestPalindromicSubstring("cbbd") << endl;
  return 0;
}