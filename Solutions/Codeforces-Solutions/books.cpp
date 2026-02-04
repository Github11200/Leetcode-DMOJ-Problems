#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://codeforces.com/problemset/problem/279/B
  Points: Accepted
******************************************/

int main() {
  int n, freeMinutes;
  cin >> n >> freeMinutes;

  vector<int> bookTimes(n);
  for (auto &bookTime : bookTimes)
    cin >> bookTime;

  int i = 0;
  int j = 0;

  int sum = 0;
  int maxNumberOfBooksRead = 0;
  for (; j < bookTimes.size(); ++j) {
    if (bookTimes[j] + sum > freeMinutes) {
      int booksRead = j - i;
      if (booksRead > maxNumberOfBooksRead)
        maxNumberOfBooksRead = booksRead;
      sum -= bookTimes[i++];
    }
    sum += bookTimes[j];
  }

  if (sum <= freeMinutes && j - i > maxNumberOfBooksRead)
    maxNumberOfBooksRead = j - i;
  cout << maxNumberOfBooksRead << endl;

  return 0;
}
