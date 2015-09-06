/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-06-11.08
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
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

stack<int> st;
queue<int> qu;
priority_queue<int> pq;
int main()
{
      //freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
      //freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);

      ios_base::sync_with_stdio(false);
      cin.tie(0);
      bool f[3];
      int n,ty,x;
      while(~scanf("%d",&n))
      {
            while(!st.empty()) st.pop();
            while(!qu.empty()) qu.pop();
            while(!pq.empty()) pq.pop();
            memset(f,true,sizeof f);
            while(n--)
            {
                scanf("%d %d",&ty,&x);
                if(ty==1)
                {
                      st.push(x);
                      qu.push(x);
                      pq.push(x);
                }
                else
                {
                      if((!st.empty())&&x!=st.top() || st.empty())
                      {
                            f[0]=0;
                      }
                      if((!qu.empty())&&x!=qu.front() || qu.empty())
                      {
                            f[1]=0;
                      }
                      if((!pq.empty())&&x!=pq.top() || pq.empty())
                      {
                            f[2]=0;
                      }
                      if(!st.empty())   st.pop();
                      if(!qu.empty())   qu.pop();
                      if(!pq.empty())   pq.pop();
                }
            }
            int cnt=0;
            for(int i=0;i<3;++i) cnt+=f[i]?1:0;
            if(cnt==1)
            {
                  if(f[0]) puts("stack");
                  else if(f[1]) puts("queue");
                  else puts("priority queue");
            }
            else if(cnt>1) puts("not sure");
            else puts("impossible");
      }
      return 0;
}
/*

*/
