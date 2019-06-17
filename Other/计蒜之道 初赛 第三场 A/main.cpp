/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-18-20.57
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

int  aa[100000010];

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            int n;
            scanf("%d",&n);
            while(n--)
            {
                  memset(aa,0,sizeof aa);
                  int r,a,b;
                  scanf("%d %d %d",&r,&a,&b);
                  for(int i=a+1;i<=b;++i)
                  {
                        int t;
                        if(i<0)
                              t=360+i;
                        else t=i;
                        aa[t]=max(aa[t],r);
                  }
            }
            double res=0;
            for(int i=0;i<=360;)
            {
                  if(aa[i]==0) i++;continue;
                  int j=i;
                  int tmp=aa[i];
                  while(j<=360 && aa[j]==tmp) j++;
                  res+=0.5*tmp *(2*tmp *M_PI)*(j-i)/360;
                  i=j;

            }
            printf("%.3f\n",res);

      }

      return 0;
}
/*

*/
