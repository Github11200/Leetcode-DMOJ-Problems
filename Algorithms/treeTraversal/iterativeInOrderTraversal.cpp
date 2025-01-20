#include "../../helperFunctions.h"

using namespace std;

void iterativePostOrderTraversal(TreeNode *root)
{
  stack<TreeNode *> nextNodes;
  while (!nextNodes.empty() || root != nullptr)
  {
    while (root != nullptr)
    {
      nextNodes.push(root);
      root = root->left;
    }
    printf("%d ", nextNodes.top()->val);
    root = nextNodes.top()->right;
    nextNodes.pop();
  }
  printf("\n");
}

int main()
{
  iterativePostOrderTraversal(createDefaultTree());
  return 0;
}