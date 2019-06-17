/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-27-14.04
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
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

const int MAXN=5000;
struct node
{
      int x,y;
      bool operator < (node a) const
      {
            return x==a.x?y<a.y:x<a.x;
      }
};
node a[MAXN];

bool v[MAXN];
int n;
bool dfs(int k)
{
      if(k==n+1 || ( abs(a[n+1].x-a[k].x)+abs(a[n+1].y-a[k].y))<=1000 )
      {
            return true;
      }
      for(int i=0;i<n+2;++i)
      {
            long long dis=abs(a[i].x-a[k].x)+abs(a[i].y-a[k].y);
            if(i!=k && v[i]==false && dis<=1000)
            {
                  v[i]=true;
                  if(dfs(i))
                        return true;
                  v[i]=false;
            }
      }
      return false;
}

int main()
{
      int t;
      scanf("%d",&t);
      while(t--)
      {
            for(int i=0;i<MAXN;++i)
                  a[i].x=0,a[i].y=0;
            scanf("%d",&n);
            for(int i=0;i<n+2;++i)
            {
                  scanf("%d %d",&a[i].x,&a[i].y);
            }
            memset(v,0,sizeof v);
            if(dfs(0))
            {
                  puts("happy");
            }
            else puts("sad");
      }
      return 0;
}
/*

*/
