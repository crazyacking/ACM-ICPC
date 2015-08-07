/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-06-15.08
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

const int MAXN=10+(int)1e5;
int n;
int a[MAXN];

void dfs(int k,int t)
{
      if(k>n)
      {
            for(int i=1;i<n;++i)
            {
                  if(a[i]!=a[i-1])
                  {
                        return false;
                  }
            }
            puts("YES");
            return true;
      }
      if(t==1)
      {
            a[k+1]+=1;
            dfs(k+1,1);

            dfs(k+1,1);
            dfs(k+1,-1);
            dfs(k+1,0);
            dfs(k-1,1);
            dfs(k-1,-1);
            dfs(k-1,0);
      }
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%d",&n);
            ULL sum=0;
            for(int i=0;i<n;++i)
            {
                  scanf("%d",&a[i]);
                  sum+=a[i];
            }
            if(sum%n==0)
            {
                  int ave=sum/n;
                  bool f=1;
                  for(int i=0;i<n;++i)
                  {
                        if(!(a[i]+1==ave || a[i]-1==ave || a[i]+2==ave || a[i]-2==ave || a[i]==ave)){ f=0;break;}
                  }
                  if(!f){ puts("NO"); continue; }

            }
            else
            {
                  puts("NO");continue;
            }

      }

      return 0;
}
/*

*/
