/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-22-13.43
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

const int MAXN = 200050 ;
const int N = 26;
LL ans;
char s[MAXN];
struct Palindromic_Tree
{
      int next[MAXN][N];
      int fail[MAXN];
      int cnt[MAXN];
      int num[MAXN];
      int len[MAXN];
      int S[MAXN];
      int last;
      int n ;
      int p ;
      int newnode(int l)
      {
            for(int i = 0 ; i < N ; ++ i) next[p][i] = 0 ;
            cnt[p] = 0 ;
            num[p] = 0 ;
            len[p] = l ;
            return p ++ ;
      }
      void init()
      {
            p = 0 ;
            newnode(0) ;
            newnode(-1) ;
            last = 0 ;
            n = 0 ;
            S[n] = -1 ;
            fail[0] = 1 ;
      }
      int get_fail(int x)
      {
            while(S[n - len[x] - 1] != S[n]) x = fail[x] ;
            return x ;
      }
      void add(int c)
      {
            c -= 'a';
            S[++ n] = c ;
            int cur = get_fail(last);
            if(!next[cur][c])
            {
                  int now = newnode(len[cur] + 2);
                  fail[now] = next[get_fail(fail[cur])][c] ;
                  next[cur][c] = now;
                  num[now] = num[fail[now]] + 1 ;
            }
            last = next[cur][c];
            cnt[last] ++;
      }
      void count() { for(int i = p - 1 ; i >= 0 ; -- i) cnt[fail[i]] += cnt[i]; }
} t1,t2;

void dfs(int u,int v)
{
      for(int i=0; i<N; ++i)
      {
            int x=t1.next[u][i];
            int y=t2.next[v][i];
            if(x&&y)
            {
                  ans+=(LL)t1.cnt[x]*t2.cnt[y];
                  dfs(x,y);
            }
      }
}

int main()
{
      int t;
      scanf("%d",&t);
      for(int Cas=1; Cas<=t; ++Cas)
      {
            t1.init(),t2.init();
            scanf("%s",s);
            for(int i=0; s[i]; ++i) t1.add(s[i]);
            scanf("%s",s);
            for(int i=0; s[i]; ++i) t2.add(s[i]);
            t1.count(),t2.count();
            ans=0;
            dfs(0,0),dfs(1,1);
            printf("Case #%d: %lld\n",Cas,ans);
      }
      return 0;
}
