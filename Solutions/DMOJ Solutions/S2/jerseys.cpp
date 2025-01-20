#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc15s2
  Points: 15/15
******************************************/

int sizeToInt(char size)
{
  int integerSize = 0;
  switch (size)
  {
  case 'S':
    integerSize = 0;
    break;
  case 'M':
    integerSize = 1;
    break;
  case 'L':
    integerSize = 2;
    break;
  default:
    break;
  }
  return integerSize;
}

void jerseys()
{
  int numberOfJerseys;
  int numberOfAthletes;

  scanf("%d", &numberOfJerseys);
  scanf("%d", &numberOfAthletes);

  int *jerseys = new int[numberOfJerseys];
  for (int i = 0; i < numberOfJerseys; ++i)
  {
    char temp;
    cin >> temp;
    jerseys[i] = sizeToInt(temp);
  }

  int fulfilled = 0;
  char size;
  int number;

  for (int i = 0; i < numberOfAthletes; ++i)
  {
    cin >> size >> number;
    if (jerseys[number - 1] >= sizeToInt(size))
    {
      ++fulfilled;
      jerseys[number - 1] = INT_MIN;
    }
  }

  printf("%d", fulfilled);
}

int main()
{
  jerseys();
  return 0;
}