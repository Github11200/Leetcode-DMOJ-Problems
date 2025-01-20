#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc01s3
  Points: 50/50
******************************************/

bool canbfsToB(unordered_map<char, set<char>> roads)
{
  queue<char> nextRoads;
  set<char> visited;
  nextRoads.push('A');
  while (!nextRoads.empty())
  {
    char currentRoad = nextRoads.front();
    nextRoads.pop();
    if (visited.count(currentRoad))
      continue;
    visited.insert(currentRoad);
    if (currentRoad == 'B')
      return true;
    for (auto neighbour : roads[currentRoad])
      nextRoads.push(neighbour);
  }
  return false;
}

void strategicBombing()
{
  unordered_map<char, set<char>> adjacencyList;
  string path;
  cin >> path;
  while (path != "**")
  {
    adjacencyList[path[0]].insert(path[1]);
    adjacencyList[path[1]].insert(path[0]);
    cin >> path;
  }

  vector<char> roadsToCut;
  for (auto element : adjacencyList)
    roadsToCut.push_back(element.first);

  unordered_map<char, set<char>> results;
  for (int i = 0; i < roadsToCut.size(); ++i)
  {
    char firstElement = *adjacencyList[roadsToCut[i]].begin();
    // Get neighbours and remove from their values
    adjacencyList[firstElement].erase(roadsToCut[i]);
    adjacencyList[roadsToCut[i]].erase(firstElement);
    if (!canbfsToB(adjacencyList))
    {
      if ((results.count(firstElement) == 0 || results[firstElement].count(roadsToCut[i]) == 0) && (results.count(roadsToCut[i]) == 0 || results[roadsToCut[i]].count(firstElement) == 0))
        results[firstElement].insert(roadsToCut[i]);
    }
    adjacencyList[firstElement].insert(roadsToCut[i]);
    adjacencyList[roadsToCut[i]].insert(firstElement);

    // Get neighbours and remove from their values
    char lastElement = *adjacencyList[roadsToCut[i]].rbegin();
    adjacencyList[lastElement].erase(roadsToCut[i]);
    adjacencyList[roadsToCut[i]].erase(lastElement);
    if (!canbfsToB(adjacencyList))
    {
      if ((results.count(lastElement) == 0 || results[lastElement].count(roadsToCut[i]) == 0) && (results.count(roadsToCut[i]) == 0 || results[roadsToCut[i]].count(lastElement) == 0))
        results[lastElement].insert(roadsToCut[i]);
    }
    adjacencyList[lastElement].insert(roadsToCut[i]);
    adjacencyList[roadsToCut[i]].insert(lastElement);
  }

  for (auto result : results)
    for (auto secondLetter : result.second)
      cout << result.first << secondLetter << endl;

  printf("There are %d disconnecting roads.\n", results.size());
}

int main()
{
  strategicBombing();
  return 0;
}