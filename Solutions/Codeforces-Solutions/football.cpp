#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://codeforces.com/problemset/problem/96/A
  Points: Accepted
******************************************/

int main() {
  string players;
  cin >> players;

  int numberOfConsecutivePlayers = 1;
  char currentPlayer = players[0];
  for (int i = 1; i < players.size(); ++i) {
    if (players[i] == currentPlayer)
      ++numberOfConsecutivePlayers;
    else {
      numberOfConsecutivePlayers = 1;
      currentPlayer = players[i];
    }

    if (numberOfConsecutivePlayers == 7) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}
