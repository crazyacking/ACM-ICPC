/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-09-16.41
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
const int MAXN=100010;

int a[MAXN],dp[MAXN][30],f[MAXN],n,q;


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
      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
      //freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);

      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(scanf("%d",&n),n)
      {
            scanf("%d",&q);
            vector<int> ve;
            for(int i=1;i<=n;++i)
                  scanf("%d",&a[i]);
            a[0]=a[1]-1;
            int x=a[1];
            ve.push_back(1);
            for(int i=2;i<=n;++i)
            {
                  if(x==a[i]) ve.push_back(ve[i-1]+1);
                  else x=a[i],ve.push_back(1);
            }
            RMQ_init(ve);
            while(q--)
            {
                  int L,R;
                  scanf("%d %d",&L,&R);
                  --L,--R;
                  int p=L;
                  while(p<=R && f[p]==f[p-1]) ++p;
                  int ans=RMQ(p,R);
                  printf("%d\n",max(ans,p-L));
            }
      }
      return 0;
}
/*

*/
