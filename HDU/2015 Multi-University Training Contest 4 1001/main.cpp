/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-30-16.50
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
const int MAXN=100010;
int a[MAXN];
void pre()
{
      int sum=0;
      int tmp;
      bool f[10];
      bool ff=0;
      for(int i=0,j,now;i<MAXN;++i)
      {
            ff=0;
            for(j=0;j<10;++j) f[j]=0;
            tmp=i;
            while(tmp)
            {
                  now=tmp%10;
                  if(f[now])
                  {
                        ff=1;
                        break;
                  }
                  else f[now]=true;
                  tmp/=10;
            }
            if(!ff) sum++;
            a[i]=sum;
      }
}
int main()
{
      pre();
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            int l,r;
            scanf("%d %d",&l,&r);
            printf("%d\n",a[r]-a[l-1]);
      }
      return 0;
}
/*

*/
