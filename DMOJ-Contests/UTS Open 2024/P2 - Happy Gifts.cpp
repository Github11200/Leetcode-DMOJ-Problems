#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/utso24p2
  Points: 0/100
******************************************/

void happyGifts()
{
  int numberOfGifts, numberOfMoves;
  scanf("%d %d", &numberOfGifts, &numberOfMoves);

  vector<pair<int, bool>> absoluteValueGifts;
  for (int i = 0; i < numberOfGifts; ++i)
  {
    pair<int, bool> absoluteValueGift(0, false);
    int gift;
    scanf("%d", &gift);
    if (gift < 0)
      absoluteValueGift.second = true;
    absoluteValueGift.first = abs(gift);
    absoluteValueGifts.push_back(absoluteValueGift);
  }

  sort(absoluteValueGifts.rbegin(), absoluteValueGifts.rend(), [](auto &left, auto &right)
       { return left.first < (right.first); });
  int sum = 0;
  for (int i = 0; i < absoluteValueGifts.size() && numberOfMoves > 0; ++i)
  {
    if (absoluteValueGifts[i].second == true)
    {
      if (numberOfMoves - 1 == 0)
      {
        // try finding a positive number to use instead
        int j = i + 1;
        for (; j < absoluteValueGifts.size(); ++j)
        {
          if (absoluteValueGifts[j].second == false)
          {
            sum += absoluteValueGifts[j].second;
            break;
          }
        }
      }
      else
      {
        absoluteValueGifts[i].second = false;
        --i;
        --numberOfMoves;
      }
    }
    else
    {
      sum += absoluteValueGifts[i].first;
      --numberOfMoves;
    }
  }

  printf("%d", sum);
}

int main()
{
  happyGifts();
  return 0;
}