#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://codeforces.com/problemset/problem/158/B
  Points: Accepted
******************************************/

int main() {
  int numberOfGroups;
  cin >> numberOfGroups;

  vector<int> groupSizes(numberOfGroups);
  int sizes[5] = {0, 0, 0, 0, 0};

  for (int i = 0; i < numberOfGroups; ++i) {
    cin >> groupSizes[i];
    ++sizes[groupSizes[i]];
  }

  int numberOfCars = 0;

  // The sizes of 4
  numberOfCars += sizes[4];

  // The sizes of 3
  numberOfCars += sizes[3];
  sizes[1] = sizes[1] - sizes[3] < 0 ? 0 : sizes[1] - sizes[3];

  // The sizes of 2
  numberOfCars += sizes[2] / 2;
  if (sizes[2] % 2 != 0) {
    ++numberOfCars;
    sizes[1] = sizes[1] - 2 < 0 ? 0 : sizes[1] - 2;
  }

  // The sizes of 1
  numberOfCars += (sizes[1] + 3) / 4;

  cout << numberOfCars << endl;

  return 0;
}
