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

void update(int x, int k)
{
  while (k <= n)
  {
    tree[k] += x;
    k += k & -k;
  }
}

void kruskals()
{
  for (auto u : edgeListRepresentation)
  {
    if (!same(a, b))
      unite(a, b);
  }
}

void treeDfs(int current, int previous)
{
  for (auto u : adj[current])
  {
    if (u.first != previous)
      treeDfs(u.first, current);
  }
}

void recursiveDfs(int x)
{
  for (auto u : adj[x])
  {
    if (!visited[u.first])
      recursiveDfs(u.first);
  }
}

int binaryIndexedSum(int k)
{
  int s = 0;
  while (k >= 1)
  {
    s += tree[k];
    k -= k & -k;
  }
  return s;
}

class UnionFind
{
private:
  vector<int> parents;
  vector<int> sizes;

public:
  UnionFind(int n)
  {
    for (int i = 0; i < n; ++i)
    {
      parents[i] = i;
      sizes[i] = 0;
    }
  }

  int top(int x)
  {
    while (x != parents[x])
      x = parents[x];
    return x;
  }

  bool same(int a, int b)
  {
    return top(a) == top(b);
  }

  void unite(int a, int b)
  {
    a = top(a);
    b = top(b);
    if (same(a, b))
      swap(a, b);
    sizes[a] += sizes[b];
    parents[b] = a;
  }
};

int sumSegmentTreeTopDown(int a, int b, int x, int y, int k)
{
  if (a < x || b > y)
    return 0;
  else if (a <= x && y <= b)
    return tree[k];
  int d = (a + b) / 2;
  return sumSegmentTreeTopDown(a, d, x, y, k * 2) + sumSegmentTreeTopDown(d, b, x, y, k * 2 + 1);
}

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

vector<int> getFactors(int x)
{
  vector<int> factors;
  for (int i = 1; i * i < x; ++i)
  {
    while (x % i == 0)
    {
      factors.push_back(i);
      i /= 2;
    }
  }
  return factors;
}

void floydWarshall()
{
  vector<vector<int>> distances;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (i == j)
        distances[i][j] = 0;
      else if (adjacencymatrixRepresentation[i][j])
        distances[i][j] = adjacencymatrixRepresentation[i][j];
      else
        distances[i][j] = INFINITY;
    }
  }

  for (int k = 0; k <= n; ++k)
  {
    for (int i = 0; i <= n; ++i)
    {
      for (int j = 0; j <= n; ++j)
      {
        distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
      }
    }
  }
}

int main()
{
  edgeListRepresentation.push_back(make_tuple(9, 7, 3));
  edgeListRepresentation.push_back(make_tuple(9, 1, 8));
  edgeListRepresentation.push_back(make_tuple(7, 1, -6));
  edgeListRepresentation.push_back(make_tuple(7, 3, -1));
  edgeListRepresentation.push_back(make_tuple(1, 5, 2));
  edgeListRepresentation.push_back(make_tuple(3, 5, 4));

  adjacencymatrixRepresentation = {
      {},
      {0, 0, 8, 3, 0, 0},
      {0, 0, 0, 0, 0, 2},
      {0, 0, 6, 0, 1, 0},
      {0, 0, 0, 0, 0, 4},
      {}};

  return 0;
}
