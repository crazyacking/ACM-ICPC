/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-06-20.45
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

struct buff
{
      int x,p;
      buff(){}
      buff(int x,int p):x(x),p(p){}
      bool operator<(const buff& a)const
      {
            return x<a.x;
      }
};
const int MAXN=766;
int a[MAXN][MAXN],n;
void work(int* a,int* b,int* c)
{
      multiset<buff> s;
      for(int i=0;i<n;++i)
            s.insert(buff(a[i]+b[0],0));
      for(int i=0;i<n;++i)
      {
            buff bf=*s.begin();
            s.erase(s.begin());
            c[i]=bf.x;
            int p=bf.p;
            if(p<n-1)s.insert(buff(bf.x-b[p]+b[p+1],p+1));
      }
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%d",&n))
      {
            for(int i=0;i<n;++i)
            {
                  for(int j=0;j<n;++j)
                        scanf("%d",&a[i][j]);
                  sort(a[i],a[i]+n);
            }
            for(int i=1;i<n;++i)
                  work(a[0],a[i],a[0]);
            for(int i=0;i<n;++i)
                  printf(i==n-1?"%d\n":"%d ",a[0][i]);
      }
      return 0;
}
/*

*/
