/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-01-04-18.01
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
vector<int> pr;
vector<int> in;

struct TreeNode
{
      int val;
      TreeNode *left,*right;
      TreeNode(int v):val(v),left(NULL),right(NULL){}
};

TreeNode* reBuildBinaryTree(vector<int> pr,vector<int> in)
{
      if(pr.size()==0 || in.size()==0)
            return NULL;
      int root=pr[0];
      TreeNode *node=new TreeNode(root);
      vector<int> prLeft,prRight,inLeft,inRight;
      int i=0;
      for(;pr[0]!=in[i];++i);

      for(int j=0;j!=i;++j)
            inLeft.push_back(in[j]);
      for(int j=i+1;j<in.size();++j)
            inRight.push_back(in[j]);
      for(int j=1;j<i+1;++j)
            prLeft.push_back(pr[j]);
      for(int j=i+1;j<pr.size();++j)
            prRight.push_back(pr[j]);

      node->left=reBuildBinaryTree(prLeft,inLeft);
      node->right=reBuildBinaryTree(prRight,inRight);
      return node;
}


vector<int>po;
void getPostOrder(TreeNode *root,bool flag)
{
      if(root->left)
            getPostOrder(root->left,0);
      if(root->right)
            getPostOrder(root->right,0);
      po.push_back(root->val);
}
int main()
{
      while(cin>>n)
      {
            int tmp;
            pr.clear();
            in.clear();
            po.clear();
            for(int i=0;i<n;++i)
            {
                  cin>>tmp;
                  pr.push_back(tmp);
            }
            for(int i=0;i<n;++i)
            {
                  cin>>tmp;
                  in.push_back(tmp);
            }
            TreeNode *root=reBuildBinaryTree(pr,in);
            getPostOrder(root,1);
            for(int i=0;i<n;++i)
            {
                  if(i<n-1) cout<<po[i]<<" ";
                  else cout<<po[i]<<endl;
            }
      }
      return 0;
}
