#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/yac9p3
  Points: 0/100
******************************************/

bool isGood(vector<int> arr, int start, int end)
{
  vector<int> arr2;
  for (int i = start; i <= end; ++i)
    arr2.push_back(arr[i]);
  int s = arr2.size();

  bool shouldRestart = true;
  while (shouldRestart)
  {
    shouldRestart = false;
    for (int i = 0; i < s; ++i)
    {
      if (arr2[i] % (i + 1) == 0)
        arr2[i] /= (i + 1);
      else if (arr2[0] == 1)
      {
        arr2.erase(arr2.begin());
        --s;
        i = 0;
      }

      if (arr2[i] != 1)
        shouldRestart = true;
    }
  }

  while (!arr2.empty())
  {
    if (arr2[0] == 1)
      arr2.erase(arr2.begin());
    else
      return false;
  }
  return true;
}

void divideAndDelete()
{
  int N;
  scanf("%d", &N);

  vector<int> arr(N);
  for (int i = 0; i < N; ++i)
    scanf("%d", &arr[i]);

  long long numberOfGoodSubarrays = 0;
  for (int i = 0; i < N; ++i)
  {
    if (arr[i] == 1)
    {
      ++numberOfGoodSubarrays;
      int j = i + 1;
      int index = 2;
      for (; j < N; ++j)
      {
        if (arr[j] == 1 || (arr[j] % index == 0 && isGood(arr, i, j)))
        {
          ++numberOfGoodSubarrays;
          ++index;
        }
        else
          break;
      }
    }
  }

  printf("%lld\n", numberOfGoodSubarrays);
}

int main()
{
  divideAndDelete();
  return 0;
}