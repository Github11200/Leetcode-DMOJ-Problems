#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc12s2
  Points: 50/50
******************************************/

void aromaticNumbers()
{
  string input;
  cin >> input;

  unordered_map<char, int> baseValues{
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000}};

  int totalSum = 0;
  for (int i = 1; i < input.size(); i += 2)
  {
    int sum = (input[i - 1] - '0') * baseValues[input[i]];
    if (i > 1 && baseValues[input[i]] > baseValues[input[i - 2]])
      totalSum -= 2 * ((input[i - 3] - '0') * baseValues[input[i - 2]]);
    totalSum += sum;
  }

  printf("%d", totalSum);
}

int main()
{
  aromaticNumbers();
  return 0;
}