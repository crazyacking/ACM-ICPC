/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2013-11-21-22.04
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
const int MAXN=150010;

int k,m,n,val[MAXN];
char name[MAXN][205];
int th[MAXN],let[MAXN],ans[MAXN];

struct op_dr
{
      int th,let;
      bool operator<(const op_dr& a)const
      {
            return th<a.th;
      }
}op[MAXN];
struct val_id
{
      int val,id;
      bool operator<(const val_id& a)const
      {
            return val>a.val ||(val==a.val && id<a.id);
      }
} vi[MAXN];
int main()
{
      int t;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%d %d %d",&k,&m,&n);
            for(int i=1;i<=k;++i)
            {
                  scanf("%s %d",name[i],&vi[i].val);
                  vi[i].id=i;
            }
            for(int i=1;i<=m;++i)
            {
                  scanf("%d %d",&op[i].th,&op[i].let);
            }
            op[m+1].th=k,op[m+1].let=k;
            sort(op+1,op+2+m);
            int cnt=1;
            int num=1;
            multiset<val_id> ms;
            for(int i=1;i<=m+1;++i)
            {
                  while(cnt<=op[i].th)
                  {
                        ms.insert(vi[cnt++]);
                  }
                  int in=1;
                  while(in<=op[i].let && ms.size()>0)
                  {
                        val_id tmp=*ms.begin();
                        ms.erase(ms.begin());
                        ans[num++]=tmp.id;
                        ++in;
                  }
            }
            int tmp;
            for(int i=1;i<=n;++i)
            {
                  scanf("%d",&tmp);
                  printf(i==n?"%s\n":"%s ",name[ans[tmp]]);
            }
      }
      return 0;
}
/*

*/
