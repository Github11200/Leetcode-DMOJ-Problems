#include "helperFunctions.h"

using namespace std;

void iterativePostOrderTraversal(TreeNode *root)
{
  stack<TreeNode *> nextNodes;
  while (!nextNodes.empty() || root != nullptr)
  {
    if (root != nullptr)
    {
      nextNodes.push(root);
      root = root->left;
    }
    else
    {
      TreeNode *temp = nextNodes.top()->right;
      if (temp == nullptr)
      {
        temp = nextNodes.top();
        nextNodes.pop();
        printf("%d ", temp->val);
        while (!nextNodes.empty() && nextNodes.top()->right == temp)
        {
          temp = nextNodes.top();
          printf("%d ", temp->val);
          nextNodes.pop();
        }
      }
      else
        root = temp;
    }
  }
}

void goodSamples()
{
  int N, M, K;
  scanf("%d %d %d", &N, &M, &K);

  vector<int> res;
  for (int i = 0; i < N; ++i)
  {
    int numberRemainingAfterCurrent = N - i - 1;
    int maxSamplesAtCurrent = min(M, K - numberRemainingAfterCurrent);

    if (maxSamplesAtCurrent <= 0)
      break;

    int value = 0;
    if (maxSamplesAtCurrent > i)
    {
      value = min(i + 1, M);
      maxSamplesAtCurrent = value;
    }
    else
      value = res[i - maxSamplesAtCurrent];

    res.push_back(value);
    K -= maxSamplesAtCurrent;
  }

  if (res.size() == N && K == 0)
  {
    for (int i = 0; i < res.size(); ++i)
      printf("%d ", res[i]);
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