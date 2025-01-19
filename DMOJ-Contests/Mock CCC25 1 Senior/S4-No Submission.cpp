#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/joi05fp2
  Points: 20/20
******************************************/

void stringOfRings()
{
  int n;
  scanf("%d", &n);
  vector<vector<int>> strings;
  for (int i = 0; i < n; ++i)
  {
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    strings.push_back(vector<int>({num1, num2}));
  }

  set<vector<int>> tempStrings(strings.begin(), strings.end());
  int maxSize = 2;
  bool restart = false;
  while (true)
  {
    strings = vector<vector<int>>(tempStrings.begin(), tempStrings.end());
    for (int i = 0; i < n && !restart; ++i)
    {
      if (tempStrings.count(strings[i]) == 0)
        continue;
      for (int j = 0; j < n && !restart; ++j)
      {
        if (i == j || tempStrings.count(strings[j]) == 0)
          continue;
        tempStrings.erase(strings[i]);
        tempStrings.erase(strings[j]);
        restart = true;
        vector<int> newString;

        // Last letter of first string equals first letter of second string
        if (strings[i][strings[i].size() - 1] == strings[j][0])
        {
          for (int k = 0; k < strings[i].size(); ++k)
            newString.push_back(strings[i][k]);
          for (int k = 1; k < strings[j].size(); ++k)
            newString.push_back(strings[j][k]);
        }
        // First letter of first string equals first letter of second string
        else if (strings[i][0] == strings[j][0])
        {
          for (int k = strings[j].size() - 1; k >= 0; --k)
            newString.push_back(strings[j][k]);
          for (int k = 1; k < strings[i].size(); ++k)
            newString.push_back(strings[i][k]);
        }
        // Last letter of first string equlas last letter of second string
        else if (strings[i][strings[i].size() - 1] == strings[j][strings[j].size() - 1])
        {
          for (int k = 0; k < strings[i].size(); ++k)
            newString.push_back(strings[i][k]);
          for (int k = strings[j].size() - 2; k >= 0; --k)
            newString.push_back(strings[j][k]);
        }
        // First letter of first string equlas last letter of second string
        else if (strings[i][0] == strings[j][strings[j].size() - 1])
        {
          for (int k = 0; k < strings[j].size(); ++k)
            newString.push_back(strings[j][k]);
          for (int k = 1; k < strings[i].size(); ++k)
            newString.push_back(strings[i][k]);
        }

        if (maxSize < newString.size() - 1)
          maxSize = newString.size() - 1;

        // It's a loop
        if (newString[0] == newString[newString.size() - 1])
          break;

        tempStrings.insert(newString);
        break;
      }
    }

    if (restart == false)
      break;
  }

  printf("%d\n", maxSize);
}

int main()
{
  stringOfRings();
  return 0;
}