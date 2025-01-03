#include <bits/stdc++.h>

using namespace std;

/*******************************************************************************************
  Link: https://dmoj.ca/problem/ccc17s3
  Points: 15/15
  Original solution: https://github.com/TommyPang/CCC-Solutions/blob/main/CCC17S3.java
*******************************************************************************************/

void nailedIt()
{
  int N;
  scanf("%d", &N);

  // Get the input and store the count of each height, not the heights themselves
  // For example, if you have 3 pieces of wood of like 5, then at index 5 store 3
  int heightCounts[2001];
  for (int i = 0; i < N; ++i)
  {
    int temp;
    scanf("%d", &temp);
    ++heightCounts[temp];
  }

  // Get the combinations of lengths that we can make, like if we have one piece of wood of size 2 and one
  // of size 3, then we can make a piece of wood of size 5, and do this for all the combinations
  int combinations[4001] = {0};
  for (int i = 1; i <= 2000; ++i)
  {
    if (heightCounts[i] != 0)
    {
      // If we have more than one piece of wood at the current index like 2, 3, 4,... then that means we can add it withitself heightCounts[i] / 2 times
      // For example, if we have 5 pieces of wood of size 2 then we can make 2 pieces of wood of size 4
      if (heightCounts[i] > 1)
        combinations[i * 2] += heightCounts[i] / 2;

      // Just get the pairs of wood that we can get, like if we have 2 pieces of wood of length 2 and 1 piece of wood of length 4 then we can make a
      // piece of wood of length 6, and using the min statement we can figure out we can only make one length of size 6, not 2, 3, etc
      for (int j = i + 1; j <= 2000; ++j)
        if (j != 0)
          combinations[i + j] += min(heightCounts[i], heightCounts[j]);
    }
  }

  // Here we compute the actual max length we can get and the different heights it can be
  int maxLength = 1;
  int heights = 0;
  for (int i = 1; i <= 4000; ++i)
  {
    // If max length is current 2 and combinations[i] is 5 at index 6 then that means we can have it be 5 pieces long with piece piece having a height of 6
    if (combinations[i] > maxLength)
    {
      // This means we can update the max length and reset heights back to 1
      maxLength = combinations[i];
      heights = 1;
    }
    // If it's the same length than it means it's just another height we can have
    else if (combinations[i] == maxLength)
      ++heights;
  }

  printf("%d %d", maxLength, heights);
}

int main()
{
  nailedIt();
  return 0;
}