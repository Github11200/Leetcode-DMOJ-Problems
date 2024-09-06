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

int N = 5;
vector<vector<int>> adj(N + 1);
vector<int> visited(N + 1);

void bfs(int startingNode)
{
  queue<int> nextNodes;
  vector<int> distances(N + 1);

  nextNodes.push(startingNode);
  distances[startingNode] = 0;
  while (!nextNodes.empty())
  {
    int currentNode = nextNodes.front();
    nextNodes.pop();
    cout << "Node: " << currentNode;

    for (auto u : adj[currentNode])
    {
      if (visited[u])
        continue;
      visited[u] = true;
      distances[u] = distances[currentNode] + 1;
      nextNodes.push(u);
    }
  }
}

void dfs(int startingNode)
{
  if (visited[startingNode])
    return;
  visited[startingNode] = true;
  cout << "Node: " << startingNode;
  for (auto u : adj[startingNode])
    dfs(u);
}

int main()
{
  adj[1].push_back(2);
  adj[1].push_back(4);
  adj[2].push_back(3);
  adj[2].push_back(5);
  adj[3].push_back(5);

  dfs(1);

  return 0;
}
