#include "../../../helperFunctions.h"

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/candy/description/
  Runtime: 100.0%
  Memory: 25.41%
******************************************/

int candy(vector<int> &ratings)
{
  vector<int> candies(ratings.size(), 1);
  for (int i = 0; i < ratings.size(); ++i)
  {
    if (i > 0 && ratings[i] < ratings[i - 1] && candies[i - 1] <= candies[i])
      candies[i - 1] = candies[i] + 1;
    if (i < ratings.size() - 1 && ratings[i] < ratings[i + 1] && candies[i + 1] <= candies[i])
      candies[i + 1] = candies[i] + 1;
  }

  for (int i = ratings.size() - 1; i >= 0; --i)
  {
    if (i > 0 && ratings[i] < ratings[i - 1] && candies[i - 1] <= candies[i])
      candies[i - 1] = candies[i] + 1;
    if (i < ratings.size() - 1 && ratings[i] < ratings[i + 1] && candies[i + 1] <= candies[i])
      candies[i + 1] = candies[i] + 1;
  }

  int sum = 0;
  for (int i = 0; i < candies.size(); ++i)
    sum += candies[i];
  return sum;
}

int main()
{
  vector<int> nums1({1, 0, 2});
  cout
      << candy(nums1) << endl;
  return 0;
}