#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;
  scanf("%d %d", &N, &M);

  unordered_map<int, vector<pair<int, int>>> adj;
  for (int i = 0; i < M; ++i)
  {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    adj[a].push_back(pair<int, int>(b, c));
  }

  stack<int> nextNodes;
  set<int> visited;
  nextNodes.push(1);
  int minCoins = 0;
  int currentCoins = 0;
  int currentTemp = 0;
  while (!nextNodes.empty())
  {
    int currentNode = nextNodes.top();
    nextNodes.pop();
    if (visited.count(currentNode) > 0)
      continue;
    visited.insert(currentNode);

    currentCoins += abs(currentTemp - currentNode);
  }

  return 0;
}