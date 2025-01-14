#include <bits/stdc++.h>

using namespace std;

/*******************************************************************************************
  Link: https://dmoj.ca/problem/ccc13s3
  Points: 15/15
*******************************************************************************************/

int numberOfTimesWinning(vector<vector<int>> gamesToPlay, vector<int> scores, int favouriteTeam)
{
  if (gamesToPlay.size() == 0)
  {
    int maxScore = -1;
    int teamWithMaxScore = -1;
    for (int i = 1; i < scores.size(); ++i)
    {
      if (scores[i] > maxScore)
      {
        maxScore = scores[i];
        teamWithMaxScore = i;
      }
      else if (scores[i] == maxScore && teamWithMaxScore == favouriteTeam && maxScore != -1)
        return 0;
    }

    if (teamWithMaxScore == favouriteTeam)
      return 1;
    else
      return 0;
  }

  int numberOfTimesWon = 0;
  vector<int> tempScores1, tempScores2, tempScores3;
  tempScores1 = scores;
  tempScores2 = scores;
  tempScores3 = scores;

  tempScores1[gamesToPlay[0][0]] += 3;
  tempScores2[gamesToPlay[0][1]] += 3;
  tempScores3[gamesToPlay[0][0]] += 1;
  tempScores3[gamesToPlay[0][1]] += 1;

  gamesToPlay.erase(gamesToPlay.begin());

  return numberOfTimesWinning(gamesToPlay, tempScores1, favouriteTeam) + numberOfTimesWinning(gamesToPlay, tempScores2, favouriteTeam) + numberOfTimesWinning(gamesToPlay, tempScores3, favouriteTeam);
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

  int numberOfTimesChampion = numberOfTimesWinning(gamesToPlay, scores, favouriteTeam);

  printf("%d", numberOfTimesChampion);
}

int main()
{
  chancesOfWinning();
  return 0;
}