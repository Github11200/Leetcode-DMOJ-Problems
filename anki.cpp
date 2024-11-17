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

void bfs(int x)
{
  queue<int> nextNodes;

  nextNodes.push(x);
  while (!nextNodes.empty())
  {
    int top = nextNodes.front();
    if (visited[top])
      continue;
    visited[top] = true;
    for (auto u : adj[top])

      nextNodes.push(u.first);
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

bool isPrime(int x)
{
  for (int i = 1; i * i < x; ++i)
  {
    if (x % i == 0)
      return false;
  }
  return true;
}

int sumSegmentTreeTopDown(int a, int b, int x, int y, int k)
{
  if (a < x || b > y)
    return 0;
  else if (x <= a && b <= y)
    return tree[k];
  int d = (a + b) / 2;
  return sumSegmentTreeTopDown(a, d, x, y, k * 2) + sumSegmentTreeTopDown(d + 1, b, x, y, k * 2 + 1);
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
