#include "../../../helperFunctions.h"

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/ransom-note/description/
  Runtime: 73.37%
  Memory: 53.74%
******************************************/

bool ransomNote(string ransomNote, string magazine)
{
  unordered_map<char, int> letterCounts;
  for (int i = 0; i < ransomNote.size(); ++i)
    ++letterCounts[ransomNote[i]];

  for (int i = 0; i < magazine.size(); ++i)
  {
    if (letterCounts.count(magazine[i]))
    {
      --letterCounts[magazine[i]];
      if (letterCounts[magazine[i]] == 0)
        letterCounts.erase(magazine[i]);
    }
  }

  return letterCounts.empty();
}

int main()
{
  cout << ransomNote("aa", "aab") << endl;
  return 0;
}