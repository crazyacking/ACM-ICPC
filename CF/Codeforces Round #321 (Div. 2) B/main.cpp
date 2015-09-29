/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-29-10.14
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

struct node
{
      int m,f;
      node() {}
      node(int m,int f):m(m),f(f) {}
      bool operator<(const node& a)const
      {
            return m<a.m;
      }
};
deque<node> dq;
vector<node> ve;
int main()
{
      int n,d;
      scanf("%d %d",&n,&d);
      int m,f;
      LL sum=0;
      LL ans=0;
      for(int i=0; i<n; ++i)
      {
            scanf("%d %d",&m,&f);
            ve.push_back(node(m,f));
      }
      sort(ve.begin(),ve.end());
      for(int i=0; i<n; ++i)
      {
            dq.push_front(ve[i]);
            sum+=ve[i].f;
            node b=dq.back();
            node f=dq.front();
            while(abs(b.m-f.m)>=d)
            {
                  sum-=b.f;
                  dq.pop_back();
                  b=dq.back();
                  f=dq.front();
            }
            ans=max(ans,sum);
      }
      printf("%I64d\n",ans);
      return 0;
}
/*

*/
