#include <bits/stdc++.h>

using namespace std;

/*******************************************************************************************
  Link: https://dmoj.ca/problem/ccc07s3
  Points: 15/15
*******************************************************************************************/

void friends()
{
  int numberOfStudents;
  scanf("%d", &numberOfStudents);

  unordered_map<int, vector<int>> friends;
  for (int i = 0; i < numberOfStudents; ++i)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    friends[a].push_back(b);
  }

  vector<string> results;
  int a, b = -1;
  while (a != 0 && b != 0)
  {
    scanf("%d %d", &a, &b);
    if (a == 0 && b == 0)
      break;

    queue<int> nextStudents;
    set<int> visited;

    unordered_map<int, int> distances;

    nextStudents.push(a);
    distances[a] = -1;
    visited.insert(a);
    while (!nextStudents.empty())
    {
      int currentStudent = nextStudents.front();
      nextStudents.pop();

      for (auto neighbour : friends[currentStudent])
      {
        if (visited.count(neighbour) > 0)
          continue;
        visited.insert(neighbour);

        distances[neighbour] = distances[currentStudent] + 1;
        nextStudents.push(neighbour);
      }
    }

    if (distances.count(b) > 0)
      results.push_back("Yes " + to_string(distances[b]) + "\n");
    else
      results.push_back("No\n");
  }

  for (int i = 0; i < results.size(); ++i)
    cout << results[i];
}

int main()
{
  friends();
  return 0;
}