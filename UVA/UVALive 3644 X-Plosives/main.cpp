/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-07-14.43
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
const int MAXN=10+(int)1e5;
int fa[MAXN];
int findset(int x)
{
      return x==fa[x]?x:fa[x]=findset(fa[x]);
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int a,b,refuse=0;;
      for(int i=0;i<MAXN;++i) fa[i]=i;
      while(~scanf("%d",&a))
      {
            if(a==-1)
            {
                  printf("%d\n",refuse);
                  refuse=0;
                  for(int i=0;i<MAXN;++i) fa[i]=i;
            }
            else
            {
                  scanf("%d",&b);
                  int x=findset(a);
                  int y=findset(b);
                  if(x==y) ++refuse;
                  else fa[x]=y;
            }
      }

      return 0;
}
/*

*/
