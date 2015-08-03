/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-03-13.50
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
const LL MAXN=10+(LL)1e5;
LL n,m;
LL a[MAXN];
bool vis[MAXN];
LL b[MAXN];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%d %d",&n,&m))
      {
            for(LL i=0;i<n;++i)
            {
                  scanf("%d",&a[i]);
            }
            sort(a,a+n);
            LL l=0,r=n-1;
            memset(vis,0,sizeof vis);
            b[0]=INT_MAX;
            LL cnt=1;
            while(l<r)
            {
                  if(a[r]+a[l]>m)
                  {
                        b[cnt++]=a[l++],b[cnt++]=a[r--];
                        vis[l]=1,vis[r]=1;
                  }
                  else
                  {
                        b[cnt++]=a[l++];
                        b[cnt++]=a[l++];
                  }
            }
            if(l==r)
            {
                  b[cnt++]=a[l];
            }
            LL ans=0,tmp;
            for(LL i=1;i<=cnt;)
            {
                  tmp=b[i]+b[i-1];
                  if(tmp>m) ans++;
                  {
                        ++ans;
                        ++i;
                  }
                  else
                  {
                        ++i;
                        if(i>=cnt) break;
                        ++ans;
                        ++i;
                  }


            }
            prLLf("%d\n",ans);
            for(LL i=1;i<=cnt;++i)
            {
                  prLLf(i==n-1?"%d\n":"%d ",b[i]);
            }
      }
      return 0;
}
/*

*/
