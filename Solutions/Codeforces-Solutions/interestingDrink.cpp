#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>

using namespace std;

/******************************************
  Link: https://codeforces.com/problemset/problem/706/B
  Points: Accepted
******************************************/

int main() {
  int numberOfShops;
  cin >> numberOfShops;

  vector<int> shopPrices(numberOfShops);
  for (int i = 0; i < numberOfShops; ++i)
    cin >> shopPrices[i];

  sort(shopPrices.begin(), shopPrices.end());

  int numberOfDays;
  cin >> numberOfDays;

  int currentSpending = 0;
  for (int i = 0; i < numberOfDays; ++i) {
    cin >> currentSpending;
    auto iterator =
        upper_bound(shopPrices.begin(), shopPrices.end(), currentSpending);
    cout << distance(shopPrices.begin(), iterator) << endl;
  }

  return 0;
}
