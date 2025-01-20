#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

template <typename T>
void display2DVector(const vector<vector<T>> &arr);

template <typename T>
void displayVector(const vector<T> &arr);

TreeNode *createDefaultTree();

#include "helperFunctions.cpp"

#endif
