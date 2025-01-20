#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc12s3
  Points: 15/15
******************************************/

void absolutelyAcidic()
{
  int N, temp;
  scanf("%d", &N);

  unordered_map<int, int> freq;
  int maxFrequencies = 0;
  for (int i = 0; i < N; ++i)
  {
    cin >> temp;
    ++freq[temp];
    maxFrequencies = max(maxFrequencies, freq[temp]);
  }

  vector<set<int, greater<int>>> frequencies(maxFrequencies + 1);
  for (auto frequency : freq)
    frequencies[frequency.second].insert(frequency.first);

  set<int, greater<int>> lastElements = frequencies[frequencies.size() - 1];
  if (lastElements.size() > 1)
    printf("%d\n", abs(*lastElements.begin() - *prev(lastElements.end())));
  else
  {
    int i = frequencies.size() - 2;
    for (; i >= 0; --i)
      if (!frequencies[i].empty())
        break;
    set<int, greater<int>> secondLastElements = frequencies[i];
    int result = -1;
    for (auto element : secondLastElements)
      result = max(result, abs(*lastElements.begin() - element));

    printf("%d\n", result);
  }
}

int main()
{
  absolutelyAcidic();
  return 0;
}