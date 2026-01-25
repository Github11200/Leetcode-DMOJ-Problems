#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
// .first -> prettiness
// .second -> color
// .third -> index
vector<tuple<int, int, int>> colorAndPrettiness;
set<int> availableColors;

void solve()
{
  for (int i = 1; i <= M; ++i)
    availableColors.insert(i);

  sort(colorAndPrettiness.begin(), colorAndPrettiness.end());
  int sum = 0;
  int j = 0;
  bool wasChanged = false;
  for (int i = colorAndPrettiness.size() - 1; i >= 0 && j < M; --i)
  {
    int prettiness, color, index;
    tie(prettiness, color, index) = colorAndPrettiness[i];
    if (availableColors.count(color) > 0)
    {
      availableColors.erase(color);
      sum += prettiness;
      ++j;
    }
    else if (!wasChanged)
    {
      availableColors.erase(*availableColors.begin());
      sum += prettiness;
      ++j;
      wasChanged = true;
    }
  }

  printf("%d\n", sum);
}

int main()
{
  scanf("%d %d %d", &N, &M, &Q);

  for (int i = 0; i < N; ++i)
  {
    int color, prettiness;
    scanf("%d %d", &color, &prettiness);
    colorAndPrettiness.push_back(tuple<int, int, int>({prettiness, color, i + 1}));
  }

  solve();

  for (int i = 0; i < Q; ++i)
  {
    int action, index, newValue;
    scanf("%d %d %d", &action, &index, &newValue);

    for (int j = 0; j < colorAndPrettiness.size(); ++j)
    {
      int prettiness, color, indexTwo;
      tie(prettiness, color, indexTwo) = colorAndPrettiness[j];
      if (index == indexTwo)
      {
        if (action == 1)
          colorAndPrettiness[j] = tuple<int, int, int>({prettiness, newValue, indexTwo});
        else
          colorAndPrettiness[j] = tuple<int, int, int>({newValue, color, indexTwo});
        break;
      }
    }
    solve();
  }

  return 0;
}