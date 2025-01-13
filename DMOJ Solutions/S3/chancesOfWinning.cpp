#include <bits/stdc++.h>

using namespace std;

/*******************************************************************************************
  Link:
  Points:
*******************************************************************************************/

int numberOfTimesWinning(vector<vector<int>> gamesToPlay, vector<int> scores, int teamThatAlwaysWins, int favouriteTeam)
{
  vector<vector<int>> tempGamesToPlay = gamesToPlay;
  for (int i = 0; i < gamesToPlay.size(); ++i)
  {
    if (gamesToPlay[i][0] == teamThatAlwaysWins || gamesToPlay[i][1] == teamThatAlwaysWins)
    {
      if (gamesToPlay[i][0] == teamThatAlwaysWins)
        scores[gamesToPlay[i][0]] += 3;
      else if (gamesToPlay[i][1] == teamThatAlwaysWins)
        scores[gamesToPlay[i][1]] += 3;
      for (int j = 0; j < tempGamesToPlay.size(); ++j)
      {
        if (tempGamesToPlay[j][0] == gamesToPlay[i][0] && tempGamesToPlay[j][1] == gamesToPlay[i][1])
        {
          tempGamesToPlay.erase(tempGamesToPlay.begin() + j);
          break;
        }
      }
    }
  }

  gamesToPlay = tempGamesToPlay;
  set<int> teamsToStillPlay;
  for (int i = 0; i < gamesToPlay.size(); ++i)
  {
    teamsToStillPlay.insert(gamesToPlay[i][0]);
    teamsToStillPlay.insert(gamesToPlay[i][1]);
  }

  if (teamsToStillPlay.size() == 0)
  {
    int maxScore = -1;
    int teamWithMaxScore = -1;
    for (int i = 1; i <= 4; ++i)
    {
      if (scores[i] > maxScore)
      {
        maxScore = scores[i];
        teamWithMaxScore = i;
      }
    }
    return teamWithMaxScore == favouriteTeam ? 1 : 0;
  }
  else
  {
    int numberOfTimesWon = 0;
    for (auto teamToStillPlay : teamsToStillPlay)
      numberOfTimesWon += numberOfTimesWinning(gamesToPlay, scores, teamToStillPlay, favouriteTeam);
    return numberOfTimesWon;
  }
}

void chancesOfWinning()
{
  int favouriteTeam, numberOfGamesPlayed;
  scanf("%d", &favouriteTeam);
  scanf("%d", &numberOfGamesPlayed);

  vector<vector<int>> gamesToPlay = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
  vector<int> scores(5, 0);

  for (int i = 0; i < numberOfGamesPlayed; ++i)
  {
    int A, B, scoreA, scoreB;
    scanf("%d %d %d %d", &A, &B, &scoreA, &scoreB);
    if (scoreA > scoreB)
      scores[A] += 3;
    else if (scoreA < scoreB)
    {
      scores[B] += 3;
    }
    else
    {
      scores[A] += 1;
      scores[B] += 1;
    }

    for (int i = 0; i < gamesToPlay.size(); ++i)
      if ((gamesToPlay[i][0] == A && gamesToPlay[i][1] == B) || (gamesToPlay[i][1] == A && gamesToPlay[i][0] == B))
        gamesToPlay.erase(gamesToPlay.begin() + i);
  }

  vector<vector<int>> initialGamesToPlaySnapshot = gamesToPlay;
  vector<int> initialScoresSnapshot = scores;

  int numberOfTimesChampion = 0;
  for (int i = 1; i <= 4; ++i)
    numberOfTimesChampion += numberOfTimesWinning(gamesToPlay, scores, i, favouriteTeam);

  printf("%d", numberOfTimesChampion);
}

int main()
{
  chancesOfWinning();
  return 0;
}