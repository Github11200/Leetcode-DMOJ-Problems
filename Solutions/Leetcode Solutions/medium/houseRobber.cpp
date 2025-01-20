#include "../../../helperFunctions.h"

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/house-robber/description/
  Runtime: 100.0%
  Memory: 20.20%
******************************************/

int rob(vector<int> &nums)
{
  if (nums.size() == 1)
    return nums[0];
  else if (nums.size() == 2)
    return max(nums[0], nums[1]);

  vector<int> houseValues(nums.size());
  houseValues[0] = nums[0];
  houseValues[1] = nums[1];
  for (int i = 2; i < houseValues.size(); ++i)
  {
    int max1 = -1;
    for (int j = 2; i - j >= 0; ++j)
      max1 = max(max1, houseValues[i - j] + nums[i]);
    houseValues[i] = max(houseValues[i - 1], max1);
  }

  return houseValues[houseValues.size() - 1];
}

int main()
{
  vector<int> testing({1, 2, 3, 1});
  cout << rob(testing) << endl;

  return 0;
}