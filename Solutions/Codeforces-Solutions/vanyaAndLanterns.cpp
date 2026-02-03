#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

/******************************************
  Link: https://mirror.codeforces.com/problemset/problem/492/B
  Points: Accepted
******************************************/

int main() {
  int n, l;

  cin >> n >> l;
  vector<double> lanternPositions(n);
  for (double &position : lanternPositions)
    cin >> position;

  sort(lanternPositions.begin(), lanternPositions.end());

  double largestRadius = 0;
  for (int i = 1; i < lanternPositions.size(); ++i) {
    double difference = lanternPositions[i] - lanternPositions[i - 1];
    double radius = static_cast<double>(difference) / 2;

    if (radius > largestRadius)
      largestRadius = radius;
  }

  if (lanternPositions[0] != 0 && lanternPositions[0] > largestRadius)
    largestRadius = lanternPositions[0];
  if (lanternPositions.back() != l &&
      l - lanternPositions.back() > largestRadius)
    largestRadius = l - lanternPositions.back();

  cout << setprecision(17) << largestRadius << endl;

  return 0;
}
