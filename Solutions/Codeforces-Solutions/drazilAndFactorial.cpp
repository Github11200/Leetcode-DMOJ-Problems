#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://codeforces.com/problemset/problem/515/C
  Points: Accepted
******************************************/

#define ll long long

int main() {
  ll n, a;
  cin >> n;

  unordered_map<int, vector<int>> x = {
      {2, vector<int>({2})},          {3, vector<int>({3})},
      {4, vector<int>({3, 2, 2})},    {5, vector<int>({5})},
      {6, vector<int>({5, 3})},       {7, vector<int>({7})},
      {8, vector<int>({7, 2, 2, 2})}, {9, vector<int>({7, 3, 3, 2})}};

  vector<int> factorialNums;
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    if (c == '0' || c == '1')
      continue;

    vector<int> nums = x[c - '0'];
    for (const auto &num : nums)
      factorialNums.push_back(num);
  }

  sort(factorialNums.begin(), factorialNums.end(), greater<>());
  string result;
  for (auto num : factorialNums)
    result += to_string(num);

  cout << result << endl;

  return 0;
}
