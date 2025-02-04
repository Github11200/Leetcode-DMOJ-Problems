#include "helperFunctions.h"

using namespace std;

vector<int> nextGreaterElement1(vector<int> &nums1, vector<int> &nums2)
{
  unordered_map<int, int> nums1Hash;
  for (int i = 0; i < nums1.size(); ++i)
    nums1Hash[i] = i;

  stack<int> descendingNums;
  vector<int> res(nums1.size(), -1);
  for (int i = 0; i < nums2.size(); ++i)
  {
    while (!descendingNums.empty() && nums2[i] > descendingNums.top())
    {
      res[nums1Hash[descendingNums.top()]] = nums2[i];
      descendingNums.pop();
    }
    if (nums1Hash.count(nums2[i]) > 0)
      descendingNums.push(nums2[i]);
  }

  return res;
}

int main()
{
  vector<int> nums1({4, 1, 2});
  vector<int> nums2({1, 3, 4, 2});
  displayVector(nextGreaterElement1(nums1, nums2));
  return 0;
}