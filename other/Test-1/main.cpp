/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-04-17.20
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

class Solution
{
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in)
    {
        if(pre.size()==0 || in.size()==0)
            return nullptr;
        TreeNode* ans=recursiveSolve(pre,in,0,pre.size()-1,0,in.size()-1);
        return ans;
    }

    TreeNode* recursiveSolve(vector<int>& pre,vector<int>& in,int l1,int r1,int l2,int r2)
    {
        if(l1>r1 || l2>r2)
            return nullptr;
        int val=pre[l1];
        TreeNode *t=new TreeNode(val);
        int gap=0,cnt=0;
        for(int i=l2;i<=r2;++i)
        {
            if(in[i]==pre[l1])
            {
                gap=i;
                break;
            }
            cnt++;
        }
        t->left=recursiveSolve(pre,in,l1+1,l1+cnt,l2,gap-1);
        t->right=recursiveSolve(pre,in,l1+cnt+1,r1,gap+1,r2);
        return t;
    }

};


void bfs(TreeNode* ans)
{
    queue<TreeNode*> que;
    while(!que.empty()) que.pop();
    if(ans)
        que.push(ans);
    while(!que.empty())
    {
        TreeNode* now=que.front();
        que.pop();
        cout<<(now->val)<<endl;
        if(now->left)
            que.push(now->left);
        if(now->right)
            que.push(now->right);
    }
}

int main()
{
    Solution solution;
    int n,k;
    while(cin>>n)
    {
        vector<int> pre,in;
        for(int i=0;i<n;++i)
        {
           cin>>k;
           pre.push_back(k);
        }
        for(int i=0;i<n;++i)
        {
            cin>>k;
            in.push_back(k);
        }
        TreeNode* ans=solution.reConstructBinaryTree(pre,in);
        bfs(ans);
    }
    return 0;
}
/*

*/
