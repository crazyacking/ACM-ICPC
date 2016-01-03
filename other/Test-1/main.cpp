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
    TreeNode *left;///////////////
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution
{
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in)
    {
        //判定递归终止条件；
        if(pre.size() == 0 || in.size() == 0)
        {
            return NULL;
        }
        //定义Node节点并其求根节点；
        int root = pre[0];
        TreeNode* node = new TreeNode(root);
        vector<int>::iterator it;
        //1.求左右子树的遍历序列；
        vector<int> preLeft, preRight, inLeft, inRight;
        //（1）.求根节点在中序遍历序列中的位置；
        vector<int>::iterator i;
        for(it = in.begin(); it != in.end(); it++)
        {
            if(root == *it)
            {
                i = it;
            }
        }
        //（2）.求左右子树的中序遍历子序列；
        int k = 0;
        for(it = in.begin(); it != in.end(); it++)
        {
            if(k == 0)
            {
                inLeft.push_back(*it);
            }
            else if(k == 1)
            {
                inRight.push_back(*it);
            }
            else {}
            if(it == i)
            {
                k = 1;
            }
        }
        //（3）.求左右子树的前序遍历子序列；
        k = 0;
        vector<int>::iterator ite;
        for(it = pre.begin()+1; it != pre.end(); it++)
        {
            for(ite = inLeft.begin(); ite != inLeft.end(); ite++)
            {
                if(*it == *ite)
                {
                    preLeft.push_back(*it);
                    k = 1;
                }
            }
            if(k == 0)
            {
                preRight.push_back(*it);
            }
            k = 0;
        }
        //根据遍历序列求出跟的左右节点；
        node->left = reConstructBinaryTree(preLeft,inLeft);
        node->right = reConstructBinaryTree(preRight,inRight);
        //返回节点地址；
        return node;
    }
};

int main()
{
    return 0;
}
