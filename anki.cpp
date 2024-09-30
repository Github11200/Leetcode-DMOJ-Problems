#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <numeric>
#include <math.h>
#include <set>
#include <bits/stdc++.h>
#include <bitset>

using namespace std;

template <typename T>
void displayVector(vector<T> arr)
{
  for (auto x : arr)
    cout << x << endl;
}

template <typename T>
void display2DVector(vector<vector<T>> arr)
{
  for (int i = 0; i < arr.size(); ++i)
  {
    for (int j = 0; j < arr[i].size(); ++j)
      cout << arr[i][j] << " ";
    cout << endl;
  }
}

int N = 9;
vector<vector<pair<int, int>>> adj(N + 1);
vector<int> visited(N + 1);

vector<tuple<int, int, int>> edgeListRepresentation(N + 1);
vector<vector<int>> adjacencymatrixRepresentation;

// sum query from 0...k
void binaryIndexedTreeSumQuery(int k) {
  int s = 0;
  while (k >= 1) {
    s += tree[k];
    k -= k & -k;
  }
  return s;
}

void recursiveDfs(int x)
{
  cout << "Node: " << x << endl;
  for (auto u : adj[x])
  {
    if (visited[u.first])
      continue;
    recursiveDfs(u.first);
    visited[u.first] = true;
  }
}

class UnionFind
{
  vector<int> parents;
  vector<int> sizes;

  void init(int n)
  {
    for (int i = 0; i <= n; ++i)
    {
      this->parents[i] = i;
      this->sizes[i] = 1;
    }
  }

  int find(int x)
  {
    while (x != this->parents[x])
      x = this->parents[x];
    return x;
  }

  bool same(int a, int b)
  {
    return this->find(a) == this->find(b);
  }

  void unite(int a, int b)
  {
    a = this->find(a);
    b = this->find(b);
    if (this->sizes[a] < this->sizes[b])
      swap(a, b);
    this->sizes[a] += this->sizes[b];
    this->parents[b] = this->parents[a];
  }
};

void treeDfs(int current, int previous)
{
  for (auto u : adj[current])
  {
    if (u.first != previous)
      treeDfs(u.first, current);
  }
}

// Create spanning tree
void kruskals()
{
  for (auto e : edgeListRepresentation)
  {
    int a, b, w;
    tie(a, b, w) = e;
    if (!same(a, b))
      unite(a, b);
  }
}

int main()
{
  // .first = b, and .second = w
  adj[9] = {{7, 3}, {1, 8}};
  adj[7] = {{1, 6}, {3, 1}};
  adj[3] = {{5, 4}};
  adj[1] = {{5, 2}};

  edgeListRepresentation.push_back(tuple(9, 7, 3));
  edgeListRepresentation.push_back(tuple(9, 1, 8));
  edgeListRepresentation.push_back(tuple(7, 1, -6));
  edgeListRepresentation.push_back(tuple(7, 3, -1));
  edgeListRepresentation.push_back(tuple(1, 5, 2));
  edgeListRepresentation.push_back(tuple(3, 5, 4));

  adjacencymatrixRepresentation = {
      {},
      {0, 0, 8, 3, 0, 0},
      {0, 0, 0, 0, 0, 2},
      {0, 0, 6, 0, 1, 0},
      {0, 0, 0, 0, 0, 4},
      {}};

  return 0;
}
