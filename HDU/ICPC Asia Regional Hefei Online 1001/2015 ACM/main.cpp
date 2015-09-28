/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-27-13.12
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

int get1(int x)
{
      int ret = 0;
      while(x)
      {
            if(x%2==1) ++ret;
            x >>= 1;
      }
      return ret;
}

LL fun(LL x)
{
      LL bfd;
      LL t;
      LL c;
      LL m;
      LL rr;
      bfd = (x) & (-1LL*x);
      t = x + bfd;
      c = t ^ x;
      m = (c >> 2) / bfd;
      rr = t | m;
      return rr;
}



LL tem,answer;
int t;
int main()
{
      scanf("%d", &t);
      for(LL Cas=1;Cas<=t;++Cas)
      {
            int D, ss1, ss2;
            scanf("%d %d %d", &D, &ss1, &ss2);
            int t = get1(D);
            if(ss1 == 0) ss1 = 1;
            if(ss2 > 32) ss2 = 32;
            answer = fun(D),tem = D;
            for(int i = t - 1; i >= ss1; --i)
            {
                  tem -= (tem & (-1LL*tem));
                  LL x = tem;
                  while(x < D) x = fun(x);
                  answer=answer<x?answer:x;
            }
            tem = D;
            for(int i =t+1; i <= ss2; ++i)
            {
                  tem = tem | (tem + 1);
                  LL x = tem;
                  while(x < D) x = fun(x);
                  answer=answer<x?answer:x;
            }
            printf("Case #%I64d: %I64d\n", Cas, answer);
      }
}
