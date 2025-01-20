#include "../../helperFunctions.h"

using namespace std;

void iterativePostOrderTraversal(TreeNode *root)
{
  stack<TreeNode *> nextNodes;
  nextNodes.push(root);
  while (!nextNodes.empty())
  {
    root = nextNodes.top();
    printf("%d ", root->val);
    nextNodes.pop();
    if (root->right != nullptr)
      nextNodes.push(root->right);
    if (root->left != nullptr)
      nextNodes.push(root->left);
  }
  printf("\n");
}

int main()
{
  iterativePostOrderTraversal(createDefaultTree());
  return 0;
}