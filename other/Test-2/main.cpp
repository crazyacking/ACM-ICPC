/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-01-03-22.42
 */
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> pr;
vector<int> in;

class Solution
{
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pr,vector<int> in)
    {
        if(pr.size() == 0 || in.size() == 0)
            return NULL;
        int root = pr[0];
        TreeNode* node = new TreeNode(root);
        vector<int> prLeft, prRight, inLeft, inRight;

        int i=0;
        for(;in[i]!=root;++i);
        for(int j=0;j!=i;++j)
            inLeft.push_back(in[j]);
        for(int j=i+1;j<in.size();++j)
            inRight.push_back(in[j]);

        for(int j=1;j<i+1;++j)
            prLeft.push_back(pr[j]);
        for(int j=i+1;j<pr.size();++j)
            prRight.push_back(pr[j]);

        node->left = reConstructBinaryTree(prLeft,inLeft);
        node->right = reConstructBinaryTree(prRight,inRight);
        return node;
    }
};

void print_BFS(TreeNode* root)
{
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty())
      {
            TreeNode *now=q.front();
            q.pop();
            cout<<(now->val)<<" ";
            if(now->left) q.push(now->left);
            if(now->right) q.push(now->right);
      }
}

int main()
{
      // test demo
      int a[]={1,2,4,7,3,5,6,8};
      int b[]={4,7,2,1,5,3,8,6};
      pr.clear();
      in.clear();
      for(int i=0;i<8;++i)
      {
            pr.push_back(a[i]);
            in.push_back(b[i]);
      }
      Solution s;
      TreeNode *root=s.reConstructBinaryTree(pr,in);
      print_BFS(root);
      return 0;
}
