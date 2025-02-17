#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/word-break/description/
  Runtime: 100.00%
  Memory: 82.41%
  Inspiration: https://www.youtube.com/watch?v=Sx9NNgInc3A
******************************************/

bool wordBreak(string s, vector<string> &wordDict)
{
  vector<int> dp(s.size() + 1, false);
  dp[s.size()] = true;

  for (int i = s.size() - 1; i >= 0; --i)
  {
    for (int j = 0; j < wordDict.size(); ++j)
    {
      if (i + wordDict[j].size() <= s.size())
      {
        string subStr = s.substr(i, wordDict[j].size());
        if (subStr == wordDict[j])
          dp[i] = dp[i + wordDict[j].size()];
      }
      if (dp[i])
        break;
    }
  }

  return dp[0];
}

int main()
{
  vector<string> dict({"apple", "pen"});
  string s = "applepenapple";
  cout << wordBreak(s, dict) << endl;
  return 0;
}