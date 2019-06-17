/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-01-03-21.09
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



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x),left(NULL),right(NULL) {}
};


class Solution
{
public:
    vector<int> tpr;
    vector<int> tin;
    void reBuild(int a,int b,int n,TreeNode *treeNode)
    {
        if(n==1) // leaf node
        {
            treeNode = new TreeNode(tpr[a]);
            return ;
        }
        else if(n<=0) // null node
            return ;
        int i=0;
        for(; tpr[a]!=tin[b+i]; ++i);
        TreeNode *lson,*rson;
        reBuild(a+1,b,i,lson);
        reBuild(a+1+i,b+1+i,n-i-1,rson);
        treeNode = new TreeNode(tpr[a]);
        treeNode->left=lson;
        treeNode->right=rson;
    }
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in)
    {
        tpr.clear();
        tin.clear();

        for(int i=0; i<pre.size(); ++i)
            tpr.push_back(pre[i]);
        for(int i=0; i<in.size(); ++i)
            tin.push_back(in[i]);

        TreeNode *root;
        int n=pre.size();
        reBuild(0,0,n,root);
        return root;
    }
};

void DFS(TreeNode *root)
{
    if(root)
    {
        cout<<(root->val)<< " ";
    }
    else return ;
    if(root->left)
        DFS(root->left);
    if(root->right)
        DFS(root->right);
}

int main()
{
    freopen("D:\\Desktop\\in.txt","r",stdin);
    int n;
    vector<int>pre;
    vector<int>in;
    while(cin>>n)
    {
        pre.clear();
        in.clear();
        for(int i=0; i<n; ++i)
        {
            int tmp;
            cin>>tmp;
            pre.push_back(tmp);
        }

        /**
        * reverse pre
        *
        */
        reverse(pre.begin(),pre.end());

        for(int i=0; i<n; ++i)
        {
            int tmp;
            cin>>tmp;
            in.push_back(tmp);
        }
        Solution a;
        TreeNode *root=a.reConstructBinaryTree(pre,in);
        DFS(root);
    }
    return 0;
}
