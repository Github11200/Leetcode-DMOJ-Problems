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

int main()
{
  iterativeInOrderTraversal(createDefaultTree());
  return 0;
}