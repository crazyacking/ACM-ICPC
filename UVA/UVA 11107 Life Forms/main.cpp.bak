/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-31-22.19
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

const int maxn = 100 + 20;
const int maxl = 1000 + 20;
const int sa_maxl = maxn * maxl;
int s[sa_maxl];
int sa[sa_maxl];
int t[sa_maxl], t2[sa_maxl], c[sa_maxl];

char str[maxn][maxl];
int idx[sa_maxl];

void build_sa(int * s, int * sa, int n, int m)
{
      int i, *x = t, *y = t2;
      for(i = 0; i < m; i++) c[i] = 0;
      for(i = 0; i < n; i++) c[x[i] = s[i]]++;
      for(i = 1; i < m; i++) c[i] += c[i-1];
      for(i = n-1; i >= 0;  i--) sa[--c[x[i]]] = i;
      for(int k = 1; k <= n; k <<= 1)
      {
            int p = 0;
            for(i = n-k; i < n; i++) y[p++] = i;
            for(i = 0; i < n; i++) if(sa[i] >= k) y[p++] = sa[i] - k;
            for(i = 0; i < m; i++) c[i] = 0;
            for(i = 0; i < n; i++) c[x[y[i]]]++;
            for(i = 0; i < m; i++) c[i] += c[i-1];
            for(i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
            swap(x, y);
            p = 1; x[sa[0]] = 0;
            for(i = 1; i < n; i++)
                  x[sa[i]] = y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k] ? p-1 : p++;
            if(p >= n) break;
            m = p;
      }
}

int Rank[sa_maxl], height[sa_maxl];
void getHeight(int n)
{
      int i, j, k = 0;
      for(i = 0; i < n; i++) Rank[sa[i]] = i;
      for(i = 0; i < n; i++)
      {
            if(k) k--;
            int j = sa[Rank[i]-1];
            while(s[i+k] == s[j+k]) k++;
            height[Rank[i]] = k;
      }
}

int flag[sa_maxl];
bool good(int L, int R, int n, int limt)
{
      if(R - L < limt) return false;
      memset(flag, 0, sizeof(flag));
      int cnt = 0;
      for(int i = L; i < R; i++)
      {
            int x = idx[sa[i]];
            if(x != n && !flag[x]) { flag[x] = 1; cnt++; }
      }
      return cnt >= limt;
}

void print_sub(int len, int L, int n)
{
      while(idx[L] == n) L++;
      int x = sa[L];
      for(int i = 0; i < len; i++)
      {
            putchar(s[x+i] + 'a' - 1);
      }
      putchar('\n');
}

bool judge(int len, int n, int limt, bool print)
{
      int L = 0;
      for(int R = 1; R <= n; R++)
      {
            if(R == n || height[R] < len)
            {
                  if(good(L, R, n, limt))
                  {
                        if(print) { print_sub(len, L, n); }
                        else return true;
                  }
                  L = R;
            }
      }
      return false;
}


int main()
{
      int n;
      int kase = 1;
      while(scanf("%d", &n),n)
      {
            if(kase++ > 1) putchar(10);
            int len = 0;
            int maxlen = 0;
            for(int i=0; i<n; i++)
            {
                  scanf("%s", str[i]);
                  int sz = strlen(str[i]);
                  maxlen = max(maxlen, sz);
                  for(int j=0; j<sz; j++)
                  {
                        s[len] = str[i][j] - 'a' + 1;
                        idx[len++] = i;
                  }
                  s[len] = 27 + i;
                  idx[len++] = n;
            }
            s[len] = 0;
            idx[len++] = n;
            int m = 27 + n;
            if(n == 1)
            {
                  puts(str[0]);
                  continue;
            }
            int limt = n / 2 + 1;
            build_sa(s, sa, len, m);
            getHeight(len);
            if(!judge(1, len, limt, false))
            {
                  puts("?");
                  continue;
            }
            int L = 1, R = maxlen;
            while(L < R)
            {
                  int M = L + (R-L+1) / 2;
                  if(judge(M, len, limt, false)) L = M;
                  else R = M - 1;
            }
            judge(L, len, limt, true);
      }
      return 0;
}
