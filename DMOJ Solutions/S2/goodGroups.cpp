#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc22s2
  Points: 15/15
******************************************/

void goodGroups()
{
  int X, Y, G;

  unordered_map<string, vector<string>> sameGroups;
  unordered_map<string, vector<string>> seperateGroups;

  scanf("%d", &X);
  for (int i = 0; i < X; ++i)
  {
    string studentOne, studentTwo;
    cin >> studentOne >> studentTwo;
    sameGroups[studentOne].push_back(studentTwo);
    sameGroups[studentTwo].push_back(studentOne);
  }

  scanf("%d", &Y);
  for (int i = 0; i < Y; ++i)
  {
    string studentOne, studentTwo;
    cin >> studentOne >> studentTwo;
    seperateGroups[studentOne].push_back(studentTwo);
    seperateGroups[studentTwo].push_back(studentOne);
  }

  int numberOfViolations = 0;
  set<string> students;
  scanf("%d", &G);
  for (int i = 0; i < G; ++i)
  {
    string studentOne, studentTwo, studentThree;
    cin >> studentOne >> studentTwo >> studentThree;

    students.insert(studentOne);
    students.insert(studentTwo);
    students.insert(studentThree);

    if (sameGroups.count(studentOne) > 0)
    {
      for (auto student : sameGroups[studentOne])
      {
        if (students.count(student) == 0)
          ++numberOfViolations;
      }
    }

    if (sameGroups.count(studentTwo) > 0)
    {
      for (auto student : sameGroups[studentTwo])
      {
        if (students.count(student) == 0)
          ++numberOfViolations;
      }
    }

    if (sameGroups.count(studentThree) > 0)
    {
      for (auto student : sameGroups[studentThree])
      {
        if (students.count(student) == 0)
          ++numberOfViolations;
      }
    }

    if (seperateGroups.count(studentOne) > 0)
    {
      for (auto student : seperateGroups[studentOne])
      {
        if (students.count(student) > 0)
          ++numberOfViolations;
      }
    }

    if (seperateGroups.count(studentTwo) > 0)
    {
      for (auto student : seperateGroups[studentTwo])
      {
        if (students.count(student) > 0)
          ++numberOfViolations;
      }
    }

    if (seperateGroups.count(studentThree) > 0)
    {
      for (auto student : seperateGroups[studentThree])
      {
        if (students.count(student) > 0)
          ++numberOfViolations;
      }
    }

    students.clear();
  }

  printf("%d", numberOfViolations / 2);
}

int main()
{
  goodGroups();
  return 0;
}