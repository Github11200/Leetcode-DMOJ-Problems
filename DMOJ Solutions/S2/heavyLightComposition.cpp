#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc24s2
  Points: 15/15
******************************************/

void heavyLightComposition()
{
  int T, N;

  scanf("%d", &T);
  scanf("%d", &N);

  vector<char> result(T, 'T');
  string input = "";
  for (int i = 0; i < T; ++i)
  {
    cin >> input;
    unordered_map<char, bool> isHeavy;
    for (auto c : input)
    {
      if (isHeavy.count(c) > 0)
        isHeavy[c] = true;
      else
        isHeavy[c] = false;
    }

    bool previousHeavy = isHeavy[input[0]];
    for (int j = 1; j < input.size(); ++j)
    {
      if (isHeavy[input[j]] == previousHeavy)
      {
        result[i] = 'F';
        break;
      }
      previousHeavy = isHeavy[input[j]];
    }
  }

  for (auto c : result)
    printf("%c\n", c);
}

int main()
{
  heavyLightComposition();
  return 0;
}