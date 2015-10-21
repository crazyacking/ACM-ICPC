/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-16-19.36
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

set<int> xy[1100],yz[1100];

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n,m,k;
      while(scanf("%d %d %d",&n,&m,&k),n+m+k)
      {
            LL ans=0;
            for(int i=0;i<1100;++i)
            {
                  xy[i].clear();
                  yz[i].clear();
            }

            int p;
            scanf("%d",&p);
            getchar();
            int len;
            char s[50];
            int a1,a2,base;
            for(int i=0,j=0,k=0; i<p; ++i)
            {
                  gets(s);
                  len=strlen(s);
                  a1=a2=0;
                  base=1;
                  for(j=len-1; j>=0; --j)
                  {
                        if(s[j]>='0' &&s[j]<='9')
                        {
                              a2+=base*(s[j]-'0');
                              base*=10;
                        }
                        else break;
                  }
                  base=1;
                  for(k=j; k>=0; --k)
                  {
                        if(s[k]>='0' &&s[k]<='9')
                        {
                              a1+=base*(s[k]-'0');
                              base*=10;
                        }
                  }
//                  cout<<a1<< " "<<a2<<endl;
                  if(s[0]=='c')
                  {
                        xy[a1].insert(a2);
                  }
                  else
                  {
                        yz[a1].insert(a2);

                  }
            }

//            for(int i=0;i<1100;++i)
//            {
//                  xy[i].erase(unique(xy[i].begin(),xy[i].end()),xy[i].end());
//                  yz[i].erase(unique(yz[i].begin(),yz[i].end()),yz[i].end());
//            }
//            puts("-----------------------------------------------------------------");
//
//            for(int j=1;j<=m;++j)
//            {
//                  printf("%d\n",yz[j].size());
//            }
//            puts("-----------------------------------------------------------------");

            for(int i=1;i<=n;++i)
            {
                  for(int j=1;j<=m;++j)
                  {
                        if(xy[i].find(j)!=xy[i].end()) continue;
                        ans+=k-yz[j].size();
                  }
            }
            printf("%lld\n",ans);

      }
      return 0;
}
/*

*/
