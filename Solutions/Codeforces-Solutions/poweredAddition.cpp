#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &item : a)
      cin >> item;

    int minimumSecondsRequired = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i] >= a[i - 1])
        continue;

      int j = 1;
      for (; j <= 31 && a[i] < a[i - 1]; ++j)
        a[i] += pow(2, j - 1);
      if (j > minimumSecondsRequired)
        minimumSecondsRequired = j - 1;
    }

    cout << minimumSecondsRequired << endl;
  }

  return 0;
}
