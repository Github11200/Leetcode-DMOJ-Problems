#include "helperFunctions.h"

using namespace std;

string addBinary(string a, string b)
{
  int i = a.size() - 1;
  int j = b.size() - 1;
  int carry = 0;

  string c = "";
  while (i >= 0 || j >= 0 || carry != 0)
  {
    if (i >= 0 && a[i] == '1')
      ++carry;
    if (j >= 0 && b[j] == '1')
      ++carry;

    c = to_string(carry % 2) + c;
    carry /= 2;
    --i;
    --j;
  }
  return c;
}

int decodeWays(string s)
{
  vector<int> dp(s.size() + 1, 1);
  for (int i = s.size() - 1; i >= 0; --i)
  {
    if (s[i] == '0')
    {
      dp[i] = 0;
      continue;
    }
    dp[i] = dp[i + 1];
    if (i < s.size() - 1 && (s[i] == '1' || (s[i] == '2' && int(s[i + 1]) <= 54)))
      dp[i] += dp[i + 2];
  }
  return dp[0];
}

int main()
{
  cout << decodeWays("11106");
  return 0;
}