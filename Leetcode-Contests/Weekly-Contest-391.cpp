#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

int harshadNumber(int x)
{
  if (x == 100)
    return 1;
  return x % (x % 10 + int(x / 10)) == 0 ? x % 10 + int(x / 10) : -1;
}

int waterBottlesTwo(int numBottles, int numExchange)
{
  int fullBottles = numBottles;
  int emptyBottles = 0;
  int numExchangeLocal = numExchange;
  int bottlesDrunk = 0;

  while (true)
  {
    if (emptyBottles >= numExchangeLocal)
    {
      fullBottles += 1;
      emptyBottles -= numExchangeLocal;
      numExchangeLocal += 1;
    }
    else if (fullBottles != 0)
    {
      bottlesDrunk += fullBottles;
      emptyBottles += fullBottles;
      fullBottles = 0;
    }
    else
    {
      break;
    }
  }

  return bottlesDrunk;
}

bool isAlternating(vector<int> nums)
{
  for (int i = 1; i < nums.size(); ++i)
  {
    if (nums[i] == nums[i - 1])
      return false;
  }

  return true;
}

int additionFactorial(int x)
{
  int sum = 0;
  for (int i = 1; i <= x; ++i)
    sum += i;
  return sum;
}

long long countAlternatingSubarrays(vector<int> &nums)
{
  long long int numberOfAlternatingSubarrays = nums.size();
  int j = 1;

  for (int i = 1; i < nums.size(); ++i)
  {
    if (i == nums.size() || nums[i] != nums[i - 1])
    {
      numberOfAlternatingSubarrays += j;
      j += 1;
    }
    else
      j = 1;
  }

  return numberOfAlternatingSubarrays;
}

int main()
{
  vector<int> test({1, 0, 1, 0});

  cout << countAlternatingSubarrays(test) << endl;

  return 0;
}