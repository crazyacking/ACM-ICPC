/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-09-10.31
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
const int MAXN=1010;

int dp[MAXN][MAXN];
void RMQ_init(const vector<int>& A)
{
      int n=A.size();
      for(int i=0;i<n;++i) dp[i][0]=A[i];
      for(int j=1;(1<<j)<=n;++j)
      {
            for(int i=0;i+(1<<j)-1<n;++i)
            {
                  dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
            }
      }
}

int RMQ(int L,int R)
{
      int k=0;
      while((1<<(k+1))<=R-L+1) ++k;
      return min(dp[L][k],dp[R-(1<<k)+1][k]);
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n,tmp;
      while(~scanf("%d",&n))
      {
            vector<int> ve;
            for(int i=0;i<n;++i)
            {
                  scanf("%d",&tmp);
                  ve.push_back(tmp);
            }
            RMQ_init(ve);
            int Q,L,R;
            scanf("%d",&Q);
            while(Q--)
            {
                  scanf("%d %d",&L,&R);
                  printf("%d\n",RMQ(L,R));
            }
      }
      return 0;
}
/*

*/
