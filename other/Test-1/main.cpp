/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-06-18.26
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
            int si=pre.size();
            bool v[si];
            for(int i=0; i<si; ++i)
            {
                  for(int j=0; j<si; ++j)
                  {
                        if(pre[i]==in[j])
                        {
                              v[j]=1;
                        }
                  }
            }
      }


      bool buildBinaryTree(int indexOfPre,int indexOfIn)
      {
            if(indexOfIn<=0)
            {
                  return false;
            }
            if(indexOfIn>=si)
            {
                  return true;
            }
            for(int i=indexOfIn; i<si;++i)
            {

            }
      }
};
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      Solution a;
      return 0;
}
/*

*/
