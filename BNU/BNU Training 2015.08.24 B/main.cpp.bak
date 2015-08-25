/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-24-13.04
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
#define  LL __int64
#define  ULL unsigned long long
using namespace std;

const int MAXN=100010;
class node1
{
public:
      int s,t,idx;
      node1(){}
      node1(int ss,int tt,int id):s(ss),t(tt),idx(id){}
      bool operator<(const node1 a) const
      {
            return s<a.s;
      }
}a[MAXN];

struct node2
{
      int s,t,idx;
      node2(){}
      node2(int ss,int tt,int id):s(ss),t(tt),idx(id){}
      bool operator<(const node2 a)const
      {
            return t<a.t;
      }
}b[MAXN];

int main()
{
      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
      //freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);

      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      LL ans;
      scanf("%d",&t);
      for(int Cas=1;Cas<=t;++Cas)
      {
            int n,q;
            scanf("%d %d",&n,&q);
            for(int i=0;i<n;++i)
            {
                  scanf("%d %d",&a[i].s,&a[i].t);
                  b[i].s=a[i].s,b[i].t=a[i].t;
            }
            sort(a,a+n);
            sort(b,b+n);
            for(int i=0;i<n;++i)
                  a[i].idx=i,b[i].idx=i;
            while(q--)
            {
                  ans=n;
                  int Q;
                  scanf("%d",&Q);
//                  cout<<(*lower_bound(a,a+n,node1(Q,0,0))).idx<<endl;
                  ans-=(n-(*upper_bound(a,a+n,node1(Q,0,0))).idx+1);
                  ans-=((*upper_bound(b,b+n,node2(0,Q,0))).idx-2);
//                  cout<<ans<<endl;
            }
      }
      return 0;
}
/*

*/
