/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-05-09.40
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

const int maxn = 1100;
int n;
int a[maxn];
int cnt,now;
int vis[maxn];
int main()
{
      while(scanf("%d",&n)!=EOF)
      {
            memset(vis,0,sizeof(vis));
            cnt=0,now=0;
            for(int i=1; i<=n; i++)
                  scanf("%d",&a[i]);
            while(1)
            {
                  if(cnt%2==0)
                  {
                        for(int i=1; i<=n; i++)
                        {
                              if(vis[i]) continue;
                              if(a[i]<=now)
                              {
                                    vis[i]=1;
                                    now++;
                              }
                        }
                  }
                  else
                  {
                        for(int i=n; i>=1; i--)
                        {
                              if(vis[i]) continue;
                              if(a[i]<=now)
                              {
                                    vis[i]=1;
                                    now++;
                              }
                        }
                  }
                  if(now==n)break;
                  cnt++;
            }
            printf("%d\n",cnt);
      }
      return 0;
}
