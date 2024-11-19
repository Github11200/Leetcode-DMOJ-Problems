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

void dijkstras(int x)
{
  priority_queue<pair<int, int>> nextNodes;
  vector<int> distances;

  distances[x] = 0;
  nextNodes.push({0, x});

  while (!nextNodes.empty())
  {
    int a = nextNodes.top().first;
    if (visited[a])
      continue;
    visited[a] = true;

    for (auto u : adj[a])
    {
      int b = u.first;
      int w = u.second;
      if (distances[a] + w < distances[b])
      {
        distances[b] = distances[a] + w;
        nextNodes.push({-distances[b], b});
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
