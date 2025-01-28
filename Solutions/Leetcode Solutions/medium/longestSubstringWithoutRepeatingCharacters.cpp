#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
  Runtime: 551 ms
  Memory: 144.45 mb
******************************************/

int lengthOfLongestSubstring(string s)
{
  int longest = -1;
  int currentLength = 0;
  unordered_map<char, int> previousCharacters;
  for (int i = 0; i < s.size(); ++i)
  {
    if (previousCharacters.count(s[i]) == 0)
    {
      previousCharacters[s[i]] = i;
      ++currentLength;
    }
    else
    {
      i = previousCharacters[s[i]];
      longest = max(longest, currentLength);
      currentLength = 0;
      previousCharacters.clear();
    }
  }

  longest = max(longest, currentLength);
  return longest;
}

int main()
{
  cout << lengthOfLongestSubstring("dvdf") << endl;
  return 0;
}