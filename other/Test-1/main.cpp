/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2013-10-29-10.19
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

const int MAXN=510;
const int MAXM=10010;
const int INF=(int)1e9+7;
int dp[MAXM];
int w[MAXN],v[MAXN];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      cin>>t;
      while(t--)
      {
            int m,v1,v2;
            cin>>v1>>v2;
            m=v2-v1;
            int n;
            cin>>n;
            for(int i=0;i<n;++i)
            {
                  cin>>v[i]>>w[i];
            }
            for(int i=0;i<=m;++i)
                  dp[i]=INF;
            dp[0]=0;
            for(int i=0;i<n;++i)
            {
                  for(int j=w[i];j<=m;++j)
                  {
                        if(dp[j]>dp[j-w[i]]+v[i])
                              dp[j]=dp[j-w[i]]+v[i];
                  }
            }
            if(dp[m]==INF)
                  cout<<"This is impossible."<<endl;
            else
                  cout<<"The minimum amount of money in the piggy-bank is "<<dp[m]<<"."<<endl;
      }
      return 0;
}
/*

*/
