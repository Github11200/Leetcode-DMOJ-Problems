#include "helperFunctions.h"

using namespace std;

void interativeInOrderTraversal(TreeNode *root)
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
    printf("%d ", root->val);
    nextNodes.pop();
    root = root->right;
  }
}

int main()
{
  return 0;
}