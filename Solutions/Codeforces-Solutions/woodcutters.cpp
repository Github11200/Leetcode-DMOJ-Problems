#include <bits/stdc++.h>

using namespace std;

#define Pair pair<int, int>

int main() {
  int n;
  cin >> n;

  vector<Pair> trees(n);
  for (auto &tree : trees)
    cin >> tree.first >> tree.second;

  int treesFallen = 1;
  int previousFallenRightDistance = -1;
  for (int i = 1; i < trees.size(); ++i) {
    if (trees[i].first - trees[i].second > trees[i - 1].first) {
      if (previousFallenRightDistance == -1 ||
          trees[i].first - trees[i].second > previousFallenRightDistance) {
        ++treesFallen;
        continue;
      }
    }

    // If we can't make the tree fall left, then make it fall right
    if (i == trees.size() - 1 ||
        trees[i].first + trees[i].second < trees[i + 1].first) {
      if (trees[i].first + trees[i].second > previousFallenRightDistance)
        previousFallenRightDistance = trees[i].first + trees[i].second;
      ++treesFallen;
    }
  }

  cout << treesFallen << endl;

  return 0;
}
