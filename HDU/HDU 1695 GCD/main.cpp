/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-08-21.45
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

const int NN=100010;
bool v[NN];
int p[NN];
void makePrime()
{
      int num=-1,i,j;
      for(i=2; i<NN; ++i)
      {
            if(!v[i]) { p[++num]=i; }
            for(j=0; j<=num && i*p[j]<NN; ++j)
            {
                  v[i*p[j]]=true;
                  if(i%p[j]==0) { break; }
            }
      }
}

struct node
{
      int fac;
      bool ti;
      node() {}
      node(int a,bool b):fac(a),ti(b) {}
};
vector<node> pa[NN];

void pre()
{
      int i,j,a,cnt,si;
      for(i=1; i<=100000; ++i)
      {
            a=i;
            cnt=0;
            for(j=0; j<=9672; ++j)
            {
                  if(!(a%p[j]))
                  {
                        pa[i].push_back(node(p[j],false));
                        si=pa[i].size();
                        for(int k=0; k<si-1; ++k)
                        {
                              pa[i].push_back(node(pa[i][si-1].fac*pa[i][k].fac,!pa[i][k].ti));
                        }
                        while(!(a%p[j]))
                              a/=p[j];
                  }
                  if(p[j]>a || a<=0) break;
            }
      }
}


int main()
{
      makePrime();
      pre();
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      for(int Cas=1; Cas<=t; ++Cas)
      {
            int a,b,c,d,k,si;
            scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
            if(k==0)
            {
                  printf("Case %d: 0\n",Cas);
                  continue;
            }
            a=b/k;
            b=d/k;
            if(a>b) swap(a,b);
            LL ans=b;
            if(a==0) ans=0;
            for(int i=2; i<=a; ++i)
            {
                  si=pa[i].size();
                  for(int j=0; j<si; ++j)
                  {
                        if(!(pa[i][j].ti))
                        {
                              ans+=((b-i+1)-b/pa[i][j].fac+(i-1)/pa[i][j].fac);
                        }
                        else
                        {
                              ans-=((b-i+1)-b/pa[i][j].fac+(i-1)/pa[i][j].fac);
                        }
                  }
            }
            printf("Case %d: %I64d\n", Cas, ans);
      }
      return 0;
}
/*

*/
