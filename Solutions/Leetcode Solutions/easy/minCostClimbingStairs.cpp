#include "../../../helperFunctions.h"

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/min-cost-climbing-stairs/description/
  Runtime: 100.0%
  Memory: 11.78%s
******************************************/

int minCostClimbingStairs(vector<int> &cost)
{
  if (cost.size() == 2)
    return min(cost[0], cost[1]);

  vector<int> costs(cost.size());
  costs[costs.size() - 1] = cost[cost.size() - 1];
  costs[costs.size() - 2] = min(cost[cost.size() - 1], cost[cost.size() - 2]);
  for (int i = cost.size() - 3; i >= 0; --i)
    cost[i] += min(cost[i + 1], cost[i + 2]);

  return min(cost[0], cost[1]);
}

int main()
{
  vector<int> testing({10, 15, 20});
  cout << minCostClimbingStairs(testing) << endl;
  return 0;
}