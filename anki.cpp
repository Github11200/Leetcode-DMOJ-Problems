#include "helperFunctions.h"

using namespace std;

void iterativeInOrderTraversal(TreeNode *root)
{
  stack<TreeNode *> nextNodes;
  while (!nextNodes.empty() || root != nullptr)
  {
    while (root != nullptr)
    {
      nextNodes.push(root);
      root = root->left;
    }
    root = nextNodes.top();
    nextNodes.pop();
    printf("%d ", root->val);
    root = root->right;
  }
}

void iterativePreOrderTraversal(TreeNode *root)
{
  stack<TreeNode *> nextNodes;
  nextNodes.push(root);
  while (!nextNodes.empty())
  {
    root = nextNodes.top();
    nextNodes.pop();
    printf("%d ", root->val);
    if (root->right != nullptr)
      nextNodes.push(root->right);
    if (root->left != nullptr)
      nextNodes.push(root->left);
  }
}

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
        while (!nextNodes.empty() && temp == nextNodes.top()->right)
        {
          temp = nextNodes.top();
          nextNodes.pop();
          printf("%d ", temp->val);
        }
      }
      else
        root = temp;
    }
  }
}

int jumpGame2(vector<int> nums)
{
  int l = 0;
  int r = 0;
  int res = 0;
  while (r < nums.size() - 1)
  {
    int farthest = 0;
    for (int i = l; i <= r; ++i)
      farthest = max(farthest, nums[i] + i);
    l = r + 1;
    r = farthest;
    ++res;
  }
  return res;
}

int main()
{
  cout << jumpGame2(vector<int>({2, 3, 1, 1, 4})) << endl;
  return 0;
}