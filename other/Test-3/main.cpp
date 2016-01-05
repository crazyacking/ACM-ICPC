/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-01-04-22.07
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

int n;
vector<int> po;
vector<int> in;

struct TreeNode
{
      int val;
      TreeNode *left,*right;
      TreeNode(int v):val(v),left(NULL),right(NULL){}
};

TreeNode* reBuildBinaryTree(vector<int> po,vector<int> in)
{
      if(po.size()==0 || in.size()==0)
            return NULL;

      int root=po[po.size()-1];
      TreeNode* node=new TreeNode(root);
      vector<int> poLeft,poRight,inLeft,inRight;
      int i=0;
      for(;in[i]!=root;++i);

      for(int j=0;j<i;++j)
            inLeft.push_back(in[j]);
      for(int j=i+1;j<in.size();++j)
            inRight.push_back(in[j]);
      for(int j=0;j<i;++j)
            poLeft.push_back(po[j]);
      for(int j=i;j<po.size()-1;++j)
            poRight.push_back(po[j]);
      node->left=reBuildBinaryTree(poLeft,inLeft);
      node->right=reBuildBinaryTree(poRight,inRight);
      return node;

}

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
      int a[]={7,4,2,5,8,6,3,1};
      int b[]={4,7,2,1,5,3,8,6};
      po.clear();
      in.clear();
      for(int i=0;i<8;++i)
      {
            po.push_back(a[i]);
            in.push_back(b[i]);
      }
      TreeNode *root=reBuildBinaryTree(po,in);
      print_BFS(root);
      return 0;
}
