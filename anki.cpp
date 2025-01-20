#include "helperFunctions.h"

using namespace std;

string addBinary(string a, string b)
{
  int i = a.size() - 1;
  int j = b.size() - 1;
  int carry = 0;
  string c = "";
  while (i >= 0 || j >= 0 || carry > 0)
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

void gates()
{
  int numberOfGates, numberOfPlanes;
  scanf("%d", &numberOfGates);
  scanf("%d", &numberOfPlanes);

  set<int, greater<int>> gates;
  vector<int> planes(numberOfPlanes);

  for (int i = 0; i < numberOfPlanes; ++i)
    scanf("%d", &planes[i]);

  for (int i = 1; i <= numberOfGates; ++i)
    gates.insert(i);

  int planesDocked = 0;
  for (int i = 0; i < numberOfPlanes; ++i)
  {
    auto result = gates.lower_bound(planes[i]);
    if (result == gates.end())
      break;
    ++planesDocked;
    gates.erase(*result);
  }

  printf("%d\n", planesDocked);
}

void swipe()
{
  int N;
  scanf("%d", &N);

  vector<int> A(N), B(N), BPrime, firstOccurences, lastOccurences;
  for (int i = 0; i < N; ++i)
    scanf("%d", &A[i]);

  for (int i = 0; i < N; ++i)
  {
    scanf("%d", &B[i]);
    if (BPrime.size() == 0 || BPrime[BPrime.size() - 1] != B[i])
    {
      firstOccurences.push_back(i);
      lastOccurences.push_back(i);
      BPrime.push_back(B[i]);
    }
    else if (BPrime[BPrime.size() - 1] == B[i])
      ++lastOccurences[lastOccurences.size() - 1];
  }

  int j = 0;
  for (int i = 0; i < A.size(); ++i)
    if (A[i] == BPrime[j])
      ++j;

  if (j == BPrime.size())
    printf("YES\n");
  else
  {
    printf("NO\n");
    return;
  }

  j = 0;
  vector<pair<int, int>> leftSwipes, rightSwipes;
  for (int i = 0; i < A.size() && j < BPrime.size(); ++i)
  {
    if (A[i] == BPrime[j])
    {
      if (i < lastOccurences[j])
        rightSwipes.push_back(pair<int, int>(i, lastOccurences[j]));
      if (i > firstOccurences[j])
        leftSwipes.push_back(pair<int, int>(firstOccurences[j], i));
      ++j;
    }
  }

  sort(rightSwipes.rbegin(), rightSwipes.rend());
  sort(leftSwipes.begin(), leftSwipes.end());

  printf("%d\n", rightSwipes.size() + leftSwipes.size());
  for (int i = 0; i < rightSwipes.size(); ++i)
    printf("R %d %d\n", rightSwipes[i].first, rightSwipes[i].second);
  for (int i = 0; i < leftSwipes.size(); ++i)
    printf("L %d %d\n", leftSwipes[i].first, leftSwipes[i].second);
}

int main()
{
  swipe();
  return 0;
}