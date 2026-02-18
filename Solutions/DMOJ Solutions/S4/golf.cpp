#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc00s4
  Points: 7/7
******************************************/

#define Pair pair<int, int>

int main() {
  int distance, numberOfClubs;
  cin >> distance >> numberOfClubs;

  vector<int> clubs(numberOfClubs);
  for (auto &club : clubs)
    cin >> club;

  sort(clubs.begin(), clubs.end());
  vector<int> dp(5281, 0);
  dp[1] = clubs[0] == 1 ? 1 : 0;

  int currentDistance = 2;
  for (; currentDistance <= distance; ++currentDistance) {
    int minMoves = INT_MAX;
    int currentMoves = 1;
    for (int j = 0; j < clubs.size(); ++j) {
      int newDistance = currentDistance - clubs[j];
      if (newDistance <= 0) {
        if (newDistance == 0)
          minMoves = 1;
        break;
      }

      if (dp[newDistance] == 0)
        continue;

      currentMoves += dp[newDistance];
      minMoves = min(minMoves, currentMoves);
      currentMoves = 1;
    }

    dp[currentDistance] = minMoves == INT_MAX ? 0 : minMoves;
  }

  if (dp[distance] == 0)
    cout << "Roberta acknowledges defeat." << endl;
  else
    cout << "Roberta wins in " << dp[distance] << " strokes." << endl;

  return 0;
}
