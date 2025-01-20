#include "../../helperFunctions.h"

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
  printf("\n");
}

int main()
{
  iterativePostOrderTraversal(createDefaultTree());
  return 0;
}