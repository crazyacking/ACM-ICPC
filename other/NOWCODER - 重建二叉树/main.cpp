/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-10-11.21
* Time: 0MS
* Memory: 137KB
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
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

// Definition for binary tree
struct TreeNode
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(){}
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
      // define function
      void reBuildBinaryTreeFunction(vector<int> pre,       // Pre order traversal
                                     vector<int> in,        // in order traversal
                                     TreeNode** rootNode);   // the root node of binary tree

      struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in)
      {
            int treeLen=pre.size();
            TreeNode** rootNode;
            reBuildBinaryTreeFunction(&pre,       // Pre order traversal
                                      &in,        // in order traversal
                                      rootNode,
                                      treeLen);   // the root node of binary tree

      }


      //  Recursive to rebuild binary tree
      void reBuildBinaryTreeFunction(vector<int>* pre,       // Pre order traversal
                                     vector<int>* in,        // in order traversal
                                     TreeNode** rootNode,
                                     int treeLen)   // the root node of binary tree
      {
            if(treeLen==0)
                  return ;
            TreeNode* tempNode=new TreeNode;
            tempNode->val=*pre;
            tempNode->left=NULL;
            tempNode->right=NULL;
            if(*rootNode==NULL)
                  *rootNode=tempNode;
            if(treeLen==1)
                  return ;
            auto theBeginNodeInPreOrder=pre.begin();
            auto theLeftEndNodeInPreOrder=pre.begin();
            int tempLen=0;
            while(theBeginNodeInPreOrder!=theLeftEndNodeInPreOrder)
            {
                  if(theBeginNodeInPreOrder==pre.end() || theLeftEndNodeInPreOrder==pre.end())
                  {
                        return ;
                  }
                  ++tempLen;
                  if(tempLen>treeLen)
                  {
                        break;
                  }
                  ++theLeftEndNodeInPreOrder;
            }

            // find the length in left sub-Tree
            int leftLen=0;
            leftLen=(int)(theLeftEndNodeInPreOrder-theBeginNodeInPreOrder);

            // find the length in right sub-Tree
            int rightLen=0;
            rightLen=treeLen-leftLen-1;

            // reBuild left sub-Tree
            if(leftLen>0)
            {
                  ++pre;
                  reBuildBinaryTreeFunction(pre,in,&((*rootNode)->left),treeLen);
                  --pre;
            }

            // reBuild right sub-Tree
            if(rightLen>0)
            {
                  for(int i=0;i<leftLen+1;++i)
                        ++pre,++in;
                  reBuildBinaryTreeFunction(pre+leftLen+1,in+leftLen+1,&((*rootNode)->right),treeLen);
                  for(int i=0;i<leftLen+1;++i)
                        --pre,--in;
            }
      }


};

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      Solution instanceBinaryTree=new Solution();

      return 0;
}
/*

*/


