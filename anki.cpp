#include "helperFunctions.h"

using namespace std;

void gates()
{
  int numberOfGates, numberOfPlanes;
  scanf("%d", &numberOfGates);
  scanf("%d", &numberOfPlanes);

  set<int, greater<int>> gatesUsed;
  vector<int> gatesToDock(numberOfPlanes);
  for (int i = 0; i < gatesToDock.size(); ++i)
    scanf("%d", &gatesToDock[i]);
  for (int i = 1; i <= numberOfGates; ++i)
    gatesUsed.insert(i);

  int planesDocked = 0;
  for (int i = 0; i < numberOfPlanes; ++i)
  {
    auto gate = gatesUsed.lower_bound(gatesToDock[i]);
    if (gate == gatesUsed.end())
      break;
    ++planesDocked;
    gatesUsed.erase(gate);
  }

  printf("%d\n", planesDocked);
}

int N = 5;
void dijkstras(int x)
{
  vector<int> distances(N, INFINITY);
  vector<bool> processed(N, false);
  priority_queue<pair<int, int>> nextNodes;
  nextNodes.push({0, x});
  distances[x] = 0;
  while (!nextNodes.empty())
  {
    int a = nextNodes.top().second;
    nextNodes.pop();
    if (processed[a])
      continue;
    processed[a] = true;
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

void goodSamples()
{
  long long N, M, K;
  scanf("%lld %lld %lld", &N, &M, &K);

  vector<long long> result;
  for (long long i = 0; i < N; ++i)
  {
    long long remainingAfterCurrent = N - i - 1;
    long long maximumNewSamplesCurrently = min(M, K - remainingAfterCurrent);

    if (maximumNewSamplesCurrently <= 0)
      break;

    long long value = 0;
    if (maximumNewSamplesCurrently > i)
    {
      value = min(i + 1, M);
      maximumNewSamplesCurrently = value;
    }
    else
      value = result[i - maximumNewSamplesCurrently];

    result.push_back(value);
    K -= maximumNewSamplesCurrently;
  }

  if (K == 0 && result.size() == N)
  {
    for (long long i = 0; i < N; ++i)
      printf("%lld ", result[i]);
    printf("\n");
    return;
  }
  printf("-1\n");
}

int main()
{
  gates();
  return 0;
}