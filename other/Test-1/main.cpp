/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-03-17.09
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
const int MAXN=1000010;
int n,a[MAXN],b[MAXN],s[MAXN];
LL ans;
vector<int> v[MAXN];
void solve(int x)
{
      int top=0;
      queue<int> q;
      q.push(x);
      while(!q.empty())
      {
            int r=q.front(); q.pop();
            s[top++]=r;
            for(int i=0; i<v[r].size(); i++) q.push(v[r][i]);
      }
      while(top--)
      {
            vector<int> t;
            int y=s[top];
            for(int i=0; i<v[y].size(); i++) t.push_back(a[v[y][i]]);
            sort(t.begin(),t.end());
            int l=0;
            for(int i=0; i<t.size(); i++) ans+=l,l+=t[i];
            a[y]+=l;
      }
}
int main()
{
      scanf("%d",&n);
      for(int i=0; i<n; i++)
      {
            scanf("%d%d",a+i,b+i);
            if(b[i]!=-1)
                  v[b[i]].push_back(i);
            else v[n].push_back(i);
      }
      for(int i=0; i<v[n].size(); i++) solve(v[n][i]);
      printf("%lld\n",ans);
      return 0;
}
