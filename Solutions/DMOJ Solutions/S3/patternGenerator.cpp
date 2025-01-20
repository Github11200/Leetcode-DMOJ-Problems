#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc96s3
  Points: 15/15
******************************************/

vector<vector<string>> patterns;
void getBitPatterns(int n, int k, int i, string pattern, int numberOfOnes)
{
  if (n == pattern.size())
  {
    if (numberOfOnes == k)
      patterns[i].push_back(pattern);
    return;
  }
  if (numberOfOnes < k)
    getBitPatterns(n, k, i, pattern + "1", numberOfOnes + 1);
  getBitPatterns(n, k, i, pattern + "0", numberOfOnes);
}

void patternGenerator()
{
  int n, k, numberOfTestCases;
  scanf("%d", &numberOfTestCases);

  for (int i = 0; i < numberOfTestCases; ++i)
  {
    scanf("%d %d", &n, &k);
    patterns.push_back(vector<string>());
    getBitPatterns(n, k, i, "", 0);
  }

  for (int i = 0; i < patterns.size(); ++i)
  {
    printf("The bit patterns are\n");
    for (auto c : patterns[i])
      cout << c << "\n";

    if (i < patterns.size() - 1)
      printf("\n");
  }
}

int main()
{
  patternGenerator();
  return 0;
}