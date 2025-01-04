#include <bits/stdc++.h>

using namespace std;

/*******************************************************************************************
  Link: https://dmoj.ca/problem/ccc09s3
  Points: 15/15
*******************************************************************************************/

void degreesOfSeperation()
{
  char input;
  int x, y;
  unordered_map<int, set<int>> friends = {{1, set<int>({6})}, {2, set<int>({6})}, {3, set<int>({6, 4, 15, 5})}, {4, set<int>({3, 6, 5})}, {5, set<int>({3, 4, 6})}, {6, set<int>({2, 1, 7, 5, 4, 3})}, {7, set<int>({6, 8})}, {8, set<int>({7, 9})}, {9, set<int>({8, 10, 12})}, {10, set<int>({9, 11})}, {11, set<int>({12, 10})}, {12, set<int>({11, 9, 13})}, {13, set<int>({12, 14, 15})}, {14, set<int>({13})}, {15, set<int>({13, 3})}, {16, set<int>({18, 17})}, {17, set<int>({16, 17})}, {18, set<int>({16, 17})}};
  vector<string> results;
  while (true)
  {
    cin >> input;

    if (input == 'q')
      break;
    if (input == 'i')
    {
      scanf("%d", &x);
      scanf("%d", &y);
      friends[x].insert(y);
      friends[y].insert(x);
    }
    if (input == 'd')
    {
      scanf("%d", &x);
      scanf("%d", &y);
      friends[x].erase(y);
      friends[y].erase(x);
    }
    if (input == 'n')
    {
      scanf("%d", &x);
      results.push_back(to_string(friends[x].size()) + "\n");
    }
    if (input == 'f')
    {
      scanf("%d", &x);
      set<int> friendOfFriends;
      for (auto neighbour : friends[x])
        for (auto friendOfFriend : friends[neighbour])
          if (friends[friendOfFriend].count(x) == 0 && friendOfFriend != x)
            friendOfFriends.insert(friendOfFriend);

      results.push_back(to_string(friendOfFriends.size()) + "\n");
    }
    if (input == 's')
    {
      scanf("%d", &x);
      scanf("%d", &y);
      queue<pair<int, int>> nextFriends;
      set<int> visited;
      bool isConnected = false;

      nextFriends.push(pair<int, int>(x, 0));
      while (!nextFriends.empty())
      {
        int currentFriend = nextFriends.front().first;
        int distance = nextFriends.front().second;
        nextFriends.pop();

        if (currentFriend == y)
        {
          results.push_back(to_string(distance) + "\n");
          isConnected = true;
          break;
        }

        if (visited.count(currentFriend) > 0)
          continue;
        visited.insert(currentFriend);

        for (auto neighbour : friends[currentFriend])
          nextFriends.push(pair<int, int>(neighbour, distance + 1));
      }

      if (!isConnected)
        results.push_back("Not connected\n");
    }
  }

  for (int i = 0; i < results.size(); ++i)
    cout << results[i];
}

int main()
{
  degreesOfSeperation();
  return 0;
}