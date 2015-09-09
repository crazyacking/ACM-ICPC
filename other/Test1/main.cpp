/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-09-13.48
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
int n,m;
int dp[100][100],gr[MAXN];
int a[MAXN];
vector<pair<int,int> > ve;

void RMQ_init()
{
      for(int i=0;i<n;++i) dp[i][0]=a[i];
      for(int j=1;(1<<j)<=n;++j)
      {
            for(int i=0;i+(1<<j)-1<n;++i)
            {
                  dp[gr[i]][gr[j]]=max(ve[dp[gr[i]][gr[j-1]]].second,ve[dp[gr[i+(1<<(j-1))]][gr[j-1]]].second);
            }
      }
}

int RMQ(int L,int R)
{
      int k=0;
      while((1<<(k+1))<=R-L+1) ++k;
      return max(ve[dp[gr[L]][gr[k]]].second,ve[dp[gr[R-(1<<k)+1]][gr[k]]].second);
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(scanf("%d",&n),n!=0)
      {
            scanf("%d",&m);
            ve.clear();
            for(int i=0;i<n;++i)
            {
                  scanf("%d",&a[i]);
            }
            int num=0;
            for(int i=1;i<=n;++i)
            {
                  gr[i-1]=ve.size();
                  if(a[i]!=a[i-1])
                  {
                        ve.push_back(make_pair(a[i-1],num+1));
                        num=0;
                  }
                  else ++num;
            }
            //
            for(int i=0;i<n;++i)
            {
                  printf("%2d ",gr[i]);
            }
            puts("");
            auto p=ve.begin();
            for(int i=0;i<ve.size();++i,++p)
            {
                  printf("%d %d %d\n",i,p->first,p->second);
            }
            while(m--)
            {
                  int L,R;
                  scanf("%d %d",&L,&R);
                  printf("%d\n",RMQ(L-1,R-1));
            }
      }
      return 0;
}
/*

*/
