#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc14s2
  Points: 250/250
******************************************/

void assigningPartners()
{
  int N;
  scanf("%d", &N);

  vector<string> classOne(N, "");
  unordered_map<string, string> partners;

  for (int i = 0; i < N; ++i)
    cin >> classOne[i];

  string name = "";
  int j = 0;
  for (int i = 0; i < N; ++i)
  {
    cin >> name;
    if (name == classOne[j] || partners.count(name) > 0 && partners[name] != classOne[j])
    {
      printf("bad");
      return;
    }
    else
      partners[classOne[j]] = name;
    ++j;
  }

  printf("good");
}

int main()
{
  assigningPartners();
  return 0;
}