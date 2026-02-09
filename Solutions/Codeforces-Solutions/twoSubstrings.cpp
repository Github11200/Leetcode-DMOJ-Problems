#include <bits/stdc++.h>
#include <strings.h>

using namespace std;

/******************************************
  Link: https://codeforces.com/problemset/problem/550/A
  Points: Accepted
******************************************/

int main() {
  string s;
  cin >> s;

  int abFirstOccurence = s.find("AB");
  int baFirstOccurence = s.find("BA");

  if (abFirstOccurence == string::npos || baFirstOccurence == string::npos) {
    cout << "NO" << endl;
    return 0;
  }

  for (int i = abFirstOccurence + 2; i < s.size() - 1; ++i) {
    string currentString;
    currentString += s[i];
    currentString += s[i + 1];

    if (currentString == "BA") {
      cout << "YES" << endl;
      return 0;
    }
  }

  for (int i = baFirstOccurence + 2; i < s.size() - 1; ++i) {
    string currentString;
    currentString += s[i];
    currentString += s[i + 1];

    if (currentString == "AB") {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;

  return 0;
}
