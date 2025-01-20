#include <bits/stdc++.h>

using namespace std;

/*******************************************************************************************
  Link: https://dmoj.ca/problem/ccc21s3
  Points: 15/15
  Inspiration: https://www.youtube.com/watch?v=4ebeCt1CjPE
*******************************************************************************************/

struct Friend
{
  long long position;
  long long speed;
  long long hearingDistance;
};

long long getTime(vector<Friend> friends, int concertPosition)
{
  long long time = 0;
  for (int i = 0; i < friends.size(); ++i)
  {
    long long distance = abs(concertPosition - friends[i].position) - friends[i].hearingDistance;
    if (distance > 0)
      time += distance * friends[i].speed;
  }
  return time;
}

bool friendsSort(Friend a, Friend b) { return a.position < b.position; }

void lunchConcert()
{
  int N;
  scanf("%d", &N);

  if (N == 1)
  {
    printf("0\n");
    return;
  }

  vector<Friend> friends(N);
  long long low, high = 0;
  for (int i = 0; i < N; ++i)
  {
    Friend currentFriend = Friend();
    scanf("%lld %lld %lld", &currentFriend.position, &currentFriend.speed, &currentFriend.hearingDistance);
    friends[i] = currentFriend;

    if (currentFriend.position < low)
      low = currentFriend.position;
    if (currentFriend.position > high)
      high = currentFriend.position;
  }

  long long mid, time, leftTime, rightTime = 0;
  while (true)
  {
    mid = (low + high) / 2;
    time = getTime(friends, mid);

    leftTime = getTime(friends, mid - 1);
    rightTime = getTime(friends, mid + 1);

    if (time < leftTime && time < rightTime)
      break;
    if (leftTime == time || rightTime == time)
      break;
    if (time < leftTime)
      low = mid + 1;
    if (time < rightTime)
      high = mid - 1;
  }

  printf("%lld\n", time);
}

int main()
{
  lunchConcert();
  return 0;
}