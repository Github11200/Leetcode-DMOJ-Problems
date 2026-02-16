#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    vector<char> arr(n);
    int numberOfSheep = 0;

    int average = 0;
    vector<int> indexes;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      if (arr[i] == '*') {
        ++numberOfSheep;
        average += i + 1;
        indexes.push_back(i + 1);
      }
    }

    if (n == 1 || numberOfSheep == 0 || numberOfSheep == 1 ||
        numberOfSheep == n) {
      cout << "0" << endl;
      continue;
    }

    average /= numberOfSheep;

    int numLeft = 0, numRight = 0;
    for (int i = 0; i < indexes.size(); ++i) {
      if (indexes[i] <= average)
        ++numLeft;
      else
        ++numRight;
    }

    int moves = 0, moves2 = 0;
    int j = 0;
    for (int i = average - numLeft + 1; i <= average + numRight; ++i) {
      moves += abs(indexes[j] - i);
      ++j;
    }

    cout << min(moves, moves2) << endl;
  }

  return 0;
}
