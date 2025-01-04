#include <bits/stdc++.h>

using namespace std;

/*******************************************************************************************
  Link: https://dmoj.ca/problem/ccc98s3
  Points: 7/15
*******************************************************************************************/

void move(int &currentX, int &currentY, int distance, int direction)
{
  switch (direction)
  {
  case 0:
    currentY += distance;
    break;
  case 1:
    currentX += distance;
    break;
  case 2:
    currentY -= distance;
    break;
  case 3:
    currentX -= distance;
    break;
  }
}

void turn(int &currentDirection, int amountToTurn)
{
  currentDirection += amountToTurn;
  if (currentDirection > 3)
    currentDirection = currentDirection - 4;
  else if (currentDirection < 0)
    currentDirection = 4 + currentDirection;
}

string turningInstructions(int deltaDirection)
{
  string result = "";
  if (deltaDirection > 0)
    result += "2\n";
  else if (deltaDirection < 0)
    result += "3\n";
  if (deltaDirection == 2)
    result += "2\n";
  else if (deltaDirection == -2)
    result += "3\n";
  return result;
}

void marsRover()
{
  int numberOfExcursions;
  scanf("%d", &numberOfExcursions);

  vector<vector<string>> instructions(numberOfExcursions);
  for (int i = 0; i < numberOfExcursions; ++i)
  {
    // 0 -> up, 1 -> right, 2 -> down, 3 -> left
    int direction = 0;
    int deltaX = 0;
    int deltaY = 0;
    int command = -1;
    int distanceToMove = 0;
    while (true)
    {
      scanf("%d", &command);
      if (command == 0)
        break;

      switch (command)
      {
      case 1:
        scanf("%d", &distanceToMove);
        move(deltaX, deltaY, distanceToMove, direction);
        break;
      case 2:
        turn(direction, 1);
        break;
      case 3:
        turn(direction, -1);
        break;
      }
    }

    // Now we have to move in the opposite direction
    deltaX = -deltaX;
    deltaY = -deltaY;

    int distance = abs(deltaX) + abs(deltaY);
    int deltaDirection = 0;
    instructions[i].push_back("Distance is " + to_string(distance) + "\n");

    // Move in the X direction first
    if (deltaX < 0)
      deltaDirection = 3 - direction;
    else if (deltaX > 0)
      deltaDirection = 1 - direction;

    if (deltaDirection != 0 && deltaX != 0)
    {
      instructions[i].push_back(turningInstructions(deltaDirection));
      turn(direction, deltaDirection);
    }
    if (deltaX != 0)
      instructions[i].push_back("1\n" + to_string(abs(deltaX)) + "\n");

    // Now move in the y direction
    if (deltaY < 0)
      deltaDirection = 2 - direction;
    else if (deltaY > 0)
      deltaDirection = 0 - direction;

    if (deltaDirection != 0 && deltaY != 0)
    {
      instructions[i].push_back(turningInstructions(deltaDirection));
      turn(direction, deltaDirection);
    }
    if (deltaY != 0)
      instructions[i].push_back("1\n" + to_string(abs(deltaY)) + "\n");
  }

  for (int i = 0; i < instructions.size(); ++i)
  {
    for (int j = 0; j < instructions[i].size(); ++j)
      cout << instructions[i][j];
  }
}

int main()
{
  marsRover();
  return 0;
}