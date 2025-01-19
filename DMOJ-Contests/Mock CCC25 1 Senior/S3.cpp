#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/joi05fp3
  Points: 20/20
******************************************/

bool isCorrectOrder(string a, string b)
{
  string numberOne = "";
  for (int i = a.size() - 1; i >= 0; --i)
  {
    if (a[i] == ' ')
      break;
    numberOne = a[i] + numberOne;
  }
  string numberTwo = "";
  for (int i = 0; i < b.size(); ++i)
  {
    if (b[i] == ' ')
      break;
    numberTwo += b[i];
  }

  if (stoi(numberOne) < stoi(numberTwo))
    return false;
  return true;
}

bool custom(string a, string b)
{
  vector<int> aNumbers, bNumbers;
  string temp = "";
  for (int i = 0; i < a.size(); ++i)
  {
    if (a[i] == ' ')
    {
      aNumbers.push_back(stoi(temp));
      temp = "";
    }
    else
      temp += a[i];
  }
  aNumbers.push_back(stoi(temp));
  temp = "";
  for (int i = 0; i < b.size(); ++i)
  {
    if (b[i] == ' ')
    {
      bNumbers.push_back(stoi(temp));
      temp = "";
    }
    else
      temp += b[i];
  }
  bNumbers.push_back(stoi(temp));

  int i = 0;
  int j = 0;
  while (i < aNumbers.size() && j < bNumbers.size())
  {
    if (aNumbers[i] < bNumbers[j])
      return true;
    else if (aNumbers[i] > bNumbers[j])
      return false;
    ++i;
    ++j;
  }
  return aNumbers.size() < bNumbers.size();
}

void square()
{
  int n;
  scanf("%d", &n);

  unordered_map<int, vector<string>> memoized;
  memoized[1].push_back("1");

  for (int i = 2; i <= n; ++i)
  {
    vector<string> memo;
    set<string> used;
    memo.push_back(to_string(i));
    used.insert(to_string(i));
    int j = i - 1;
    int k = 1;
    string current = "";
    while (k <= j)
    {
      for (int x = 0; x < memoized[j].size(); ++x)
      {
        current += memoized[j][x] + " ";
        for (int y = 0; y < memoized[k].size(); ++y)
        {
          if (isCorrectOrder(memoized[j][x], memoized[k][y]) && used.count(current + memoized[k][y]) == 0)
          {
            memo.push_back(current + memoized[k][y]);
            used.insert(current + memoized[k][y]);
          }
        }
        current = "";
      }
      current = "";
      --j;
      ++k;
    }
    sort(memo.rbegin(), memo.rend(), custom);
    memoized[i] = memo;
  }

  for (auto str : memoized[n])
    printf("%s\n", str.c_str());
}

int main()
{
  square();
  return 0;
}