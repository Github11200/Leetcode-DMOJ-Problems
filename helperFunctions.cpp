#ifndef HELPERFUNCTIONS_CPP
#define HELPERFUNCTIONS_CPP

#include "helperFunctions.h"

using namespace std;

template <typename T>
void display2DVector(const vector<vector<T>> &arr)
{
  for (const auto &row : arr)
  {
    for (const auto &elem : row)
      cout << elem << " ";
    cout << endl;
  }
}

template <typename T>
void displayVector(const vector<T> &arr)
{
  for (const auto &x : arr)
    cout << x << " ";
}

TreeNode *createDefaultTree()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  root->left->right->right = new TreeNode(7);
  root->right = new TreeNode(3);
  return root;
}

#endif
