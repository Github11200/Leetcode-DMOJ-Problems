#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://codeforces.com/problemset/problem/580/C
  Points: Accepted
******************************************/

#define P pair<int, int>

struct Vertex {
  bool hasCat;
  vector<int> neighbours;

  Vertex() = default;
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<Vertex> tree(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    tree[i].hasCat = x == 1 ? true : false;
  }

  for (int i = 0; i < n - 1; ++i) {
    int n1, n2;
    cin >> n1 >> n2;
    --n1, --n2;

    tree[n1].neighbours.push_back(n2);
    tree[n2].neighbours.push_back(n1);
  }

  stack<P> s;
  vector<bool> visited(n);
  s.push(P(0, tree[0].hasCat));
  int count = 0;
  while (!s.empty()) {
    int index = s.top().first;
    Vertex current = tree[index];
    int consecutive = s.top().second;
    s.pop();

    if (visited[index])
      continue;
    visited[index] = true;

    if (consecutive > m)
      continue;
    if (current.neighbours.size() == 1 && visited[current.neighbours[0]]) {
      ++count;
      continue;
    }

    for (auto neighbour : current.neighbours) {
      int newConsecutive = 0;
      if (!tree[neighbour].hasCat)
        newConsecutive = 0;
      else
        newConsecutive = consecutive + 1;
      s.push(P(neighbour, newConsecutive));
    }
  }

  cout << count << endl;

  return 0;
}
