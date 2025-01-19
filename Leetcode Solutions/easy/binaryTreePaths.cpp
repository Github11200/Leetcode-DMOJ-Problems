#include <bits/stdc++.h>
#include "../../helperFunctions.h"

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/binary-tree-paths/description/
  Runtime: 36.61%
  Memory: 12.98%
******************************************/

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<string> dfs(TreeNode *root, string currentPath)
{
  static vector<string> paths;
  if (root->left == nullptr && root->right == nullptr)
  {
    currentPath += to_string(root->val);
    paths.push_back(currentPath);
    return paths;
  }

  if (root->left != nullptr)
    dfs(root->left, currentPath + to_string(root->val) + "->");
  if (root->right != nullptr)
    dfs(root->right, currentPath + to_string(root->val) + "->");

  if (currentPath == "")
  {
    vector<string> tempReturn = paths;
    paths.clear();
    return tempReturn;
  }
  return paths;
}

vector<string> binaryTreePaths(TreeNode *root)
{
  stack<TreeNode *> nextNodes;
  nextNodes.push(root);
  string path = "";
  vector<string> paths;
  while (!nextNodes.empty())
  {
    TreeNode *currentNode = nextNodes.top();
    nextNodes.pop();
    while (currentNode->left != nullptr)
    {
      nextNodes.push(currentNode->left);
    }
  }
  return paths;
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);

  vector<string> result = binaryTreePaths(root);
  displayVector(result);

  return 0;
}