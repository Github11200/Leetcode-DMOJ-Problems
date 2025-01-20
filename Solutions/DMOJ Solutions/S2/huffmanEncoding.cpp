#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc10s2
  Points: 60/60
******************************************/

void huffmanEncoding()
{
  int k;
  scanf("%d", &k);

  unordered_map<string, char> encodedCharacters;
  for (int i = 0; i < k; ++i)
  {
    char letter;
    string sequence;
    cin >> letter >> sequence;
    encodedCharacters[sequence] = letter;
  }

  string sequence;
  string output = "";
  cin >> sequence;

  for (int i = 0; i < sequence.size();)
  {
    string substring = "";
    while (encodedCharacters.count(substring) == 0 && i < sequence.size())
    {
      substring += sequence[i];
      ++i;
    }
    output += encodedCharacters[substring];
  }

  cout << output;
}

int main()
{
  huffmanEncoding();
  return 0;
}