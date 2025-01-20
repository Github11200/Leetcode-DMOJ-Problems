#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc06s2
  Points: 1050/1050
******************************************/

void attackOfTheCipherTexts()
{
  cin.sync_with_stdio(0);
  cin.tie(0);

  string plainText;
  string ciphered;
  string toDecode;

  getline(cin, plainText);
  getline(cin, ciphered);
  getline(cin, toDecode);

  string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
  set<char> keySet;
  set<char> valSet;

  for (int i = 0; i < letters.size(); ++i)
  {
    keySet.insert(letters[i]);
    valSet.insert(letters[i]);
  }

  unordered_map<char, char> mapping;
  for (int i = 0; i < plainText.size(); ++i)
  {
    mapping[ciphered[i]] = plainText[i];
    if (keySet.count(ciphered[i]) > 0)
      keySet.erase(ciphered[i]);
    if (valSet.count(plainText[i]) > 0)
      valSet.erase(plainText[i]);
  }

  if (keySet.size() == 1)
    mapping[*keySet.begin()] = *valSet.begin();

  string result;
  for (int i = 0; i < toDecode.size(); ++i)
  {
    if (mapping.count(toDecode[i]) == 0)
      result += ".";
    else
      result += mapping[toDecode[i]];
  }

  cout << result << endl;
}

int main()
{
  attackOfTheCipherTexts();
  return 0;
}