#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i)
  {
    int n;
    cin >> n;

    if (n % 11 == 0)
    {
      cout << "YES" << endl;
      continue;
    }

    string nString = to_string(n);
    if (nString.size() == 1 || nString.size() == 2)
    {
      cout << "NO" << endl;
      continue;
    }

    int num = 0;
    int previousDigit = -1;
    for (int j = 0; j < nString.size() - 1; ++j)
    {
      int len = nString.size() - j;
      string elevenString = "";
      for (int k = 0; k < len; ++k)
        elevenString += "1";

      int digit = nString[j] - '0';
      if (previousDigit != -1)
        digit -= abs(previousDigit);
      num += stoi(elevenString) * digit;

      previousDigit = digit;
    }

    if (num == n)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
