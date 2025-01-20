#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/joi05fp2
  Points: 20/20
******************************************/

void String()
{
  int n;
  string input;
  scanf("%d", &n);
  cin >> input;

  string newString = "";
  for (int i = 0; i < n; ++i)
  {
    char current = ' ';
    int length = 0;
    for (int j = 0; j < input.size(); ++j)
    {
      if (current == ' ')
      {
        current = input[0];
        ++length;
      }
      else if (input[j] == current)
        ++length;
      else if (input[j] != current)
      {
        newString += to_string(length) + current;
        current = input[j];
        length = 1;
      }
    }
    newString += to_string(length) + current;
    input = newString;
    newString = "";
  }

  printf("%s\n", input.c_str());
}

int main()
{
  String();
  return 0;
}