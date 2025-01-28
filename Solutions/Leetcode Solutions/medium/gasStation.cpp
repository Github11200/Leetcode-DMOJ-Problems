#include "../../../helperFunctions.h"

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/gas-station/description/
  Runtime: 100.0%
  Memory: 72.09%
******************************************/

int gasStation(vector<int> &gas, vector<int> &cost)
{
  int gasSum = 0;
  int costSum = 0;
  for (int i = 0; i < gas.size(); ++i)
  {
    gasSum += gas[i];
    costSum += cost[i];
  }

  if (gasSum < costSum)
    return -1;

  int start = 0;
  int sum = 0;
  for (int i = 0; i < gas.size(); ++i)
  {
    sum += gas[i] - cost[i];
    if (sum < 0)
    {
      sum = 0;
      start = i + 1;
    }
  }
  return start;
}

int main()
{
  vector<int> nums1({5, 1, 2, 3, 4});
  vector<int> nums2({4, 4, 1, 5, 1});
  cout << gasStation(nums1, nums2) << endl;
  return 0;
}