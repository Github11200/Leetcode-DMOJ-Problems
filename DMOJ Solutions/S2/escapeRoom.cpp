#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc20s2
  Points: 15/15
******************************************/

void escapeRoom()
{
  int M, N;
  scanf("%d", &M);
  scanf("%d", &N);

  vector<vector<pair<int, int>>> adj(1000001);
  for (int i = 1; i <= M; ++i)
  {
    for (int j = 1; j <= N; ++j)
    {
      int input = 0;
      scanf("%d", &input);
      adj[input].push_back(pair<int, int>(i, j));
    }
  }

  queue<pair<int, int>> nextElements;
  vector<vector<bool>> visited(M + 1, vector<bool>(N + 1));
  visited[1][1] = true;
  nextElements.push(pair<int, int>(1, 1));

  while (!nextElements.empty())
  {
    pair<int, int> currentElement = nextElements.front();
    nextElements.pop();
    for (auto neighbour : adj[currentElement.first * currentElement.second])
    {
      if (neighbour.first == 1 && neighbour.second == 1)
      {
        printf("yes");
        return;
      }
      else if (visited[neighbour.first][neighbour.second] == 0)
      {
        nextElements.push(neighbour);
        visited[neighbour.first][neighbour.second] = true;
      }
    }
  }

  printf("no");
}

int main()
{
  escapeRoom();
  return 0;
}