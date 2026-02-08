#include <bits/stdc++.h>

using namespace std;

// ABAXXXAB

int main() {
  string s;
  cin >> s;

  vector<int> ab;
  vector<int> ba;

  for (int i = 0; i < s.size() - 1; ++i) {
    string currentString;
    currentString += s[i];
    currentString += s[i + 1];

    if (currentString != "AB")
      continue;

    for (int j = i + 2; j < s.size() - 1; ++j) {
      string newString;
      newString += s[j];
      newString += s[j + 1];
      if (newString == "BA") {
        cout << "YES" << endl;
        return 0;
      }
    }
  }

  for (int i = s.size() - 1; i > 0; --i) {
    string currentString;
    currentString += s[i];
    currentString += s[i - 1];

    if (currentString != "AB")
      continue;

    for (int j = i - 2; j > 0; --j) {
      string newString;
      newString += s[j];
      newString += s[j - 1];
      if (newString == "BA") {
        cout << "YES" << endl;
        return 0;
      }
    }
  }

  cout << "NO" << endl;

  return 0;
}
