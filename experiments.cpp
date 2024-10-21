#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <numeric>
#include <math.h>
#include <set>
#include <bits/stdc++.h>
#include <bitset>

using namespace std;

vector<int> z(string s)
{
  int n = s.size();
  vector<int> z(n);
  int x = 0, y = 0;
  for (int i = 1; i < n; i++)
  {
    // We basically want to check if we have another prefix from before using z[i - x] (i is current pointer and subtracting x gets us the position from the start)
    // then y - i + 1 gets us how far we are from y
    z[i] = max(0, min(z[i - x], y - i + 1));

    // (i + z[i] < n) this makes sure we don't go out of bounds when accessing s with these values
    // (s[s[i]] == s[i + z[i]]) here s[s[i]] checks the starting of the string, the prefix, since s[i] is usually 0
    // then s[i + z[i]] checks the current pointer, and then these two continue get incremented if z[i] is incremented
    // this will then get us the longest prefix
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
    {
      // set x to the be start at the current index i
      x = i;
      // set y to be the size of the range
      y = i + z[i];
      // increment z[i] because it will be used to subsequently check a longer and longer string
      z[i]++;
    }
  }
  return z;
}

int main()
{
  z("ACBACDACBACBACDA");

  return 0;
}