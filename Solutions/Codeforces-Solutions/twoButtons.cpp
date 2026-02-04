#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>

#define Pair pair<int, int>

using namespace std;

/******************************************
  Link: https://codeforces.com/contest/520/problem/B
  Points: Accepted
******************************************/

int main() {
  int n, m;
  cin >> n >> m;

  queue<pair<int, int>> q;
  q.push(Pair(n, 1));

  int currentDepth = 1;

  unordered_map<int, int> checked;

  while (!q.empty()) {
    Pair curr = q.front();
    q.pop();

    int value = curr.first;
    int depth = curr.second;
    currentDepth = depth;

    if (checked.count(value))
      continue;
    checked[value] = 0;

    if (value == m || value * 2 == m || value - 1 == m)
      break;

    if (value * 2 <= m * 2)
      q.push(Pair(value * 2, depth + 1));
    if (value - 1 > 0)
      q.push(Pair(value - 1, depth + 1));
  }

  cout << currentDepth << endl;

  return 0;
}
