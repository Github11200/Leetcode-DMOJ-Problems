#include "../../../helperFunctions.h"

using namespace std;

/*******************************************************************************************
  Link: https://dmoj.ca/problem/ccc22s3
  Points: 15/15
  Inspiration: https://www.geekedu.org/blogs/2022-waterloo-ccc-senior-problem-solution#toc-8
*******************************************************************************************/

void goodSamples()
{
  long long N, M, K;
  scanf("%lld %lld %lld", &N, &M, &K);
  vector<long long> result;

  for (long long i = 0; i < N; ++i)
  {
    // How many notes we have remaining after the one on the current index
    long long remainingAfterThisIndex = N - i - 1;
    // The maximum number of good samples we can make, K - remainingAfterThisIndex just gives us how many we can add at this index, so if
    // K = 5 and remainingAfterThisIndex = 2 then we can add a MAXIMUM of 3, but if M = 2 then it limits it to just 2 more good samples
    long long currentMaxNotes = min(K - remainingAfterThisIndex, M);

    // If we can't add any more samples then just exit
    if (currentMaxNotes <= 0)
      break;

    long long value = 0;

    // If we can still add distinct integers and we do have to add them then do so
    if (currentMaxNotes > i)
    {
      // Get either i + 1 or M, whichever one is smaller, M just limits it so it doesn't go past the highest note
      value = min(M, i + 1);
      currentMaxNotes = value;
    }
    else
      value = result[i - currentMaxNotes]; // Use a previous note
    result.push_back(value);
    // Update the number of good samples we've created so far
    K -= currentMaxNotes;
  }

  if (K == 0 && result.size() == N)
  {
    for (long long i = 0; i < result.size(); ++i)
      printf("%lld ", result[i]);
    printf("\n");
    return;
  }
  printf("-1\n");
}

int main()
{
  goodSamples();
  return 0;
}