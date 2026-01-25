#include <bits/stdc++.h>

using namespace std;

// Ascii code of 1 - 49
// Ascii code of 9 - 57

int main()
{
  string RLEencoded;

  long long c;
  cin >> RLEencoded;
  scanf("%lld", &c);

  string number = "";
  long long decodedLength = 0;
  for (long long i = 0; i < RLEencoded.size(); ++i)
  {
    if (int(RLEencoded[i]) >= 48 && int(RLEencoded[i]) <= 57)
      number += RLEencoded[i];
    else if (number != "")
    {
      decodedLength += stoi(number);
      number = "";
    }
  }

  if (number != "")
    decodedLength += stoi(number);
  number = "";

  long long index = c % decodedLength;
  decodedLength = 0;
  char currentChar = RLEencoded[0];
  for (long long i = 0; i < RLEencoded.size(); ++i)
  {
    if ((long long)(RLEencoded[i]) >= 48 && (long long)(RLEencoded[i]) <= 57)
      number += RLEencoded[i];
    else if (number != "")
    {
      decodedLength += stoi(number);
      if (decodedLength >= index)
      {
        cout << currentChar << endl;
        return 0;
      }
      number = "";
      currentChar = RLEencoded[i];
    }
  }

  printf("%c\n", currentChar);

  return 0;
}