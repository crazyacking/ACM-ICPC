/*
* -----------------------------------------------------------------
* Copyright (c) 2015 crazyacking All rights reserved.
* -----------------------------------------------------------------
*       Author: crazyacking
*       Verdict: Accepted
*       Submission Date: 2014-06-18-16.39
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

int n=0;
double ex[30+5]= {0.0},dp[30+5]= {0.0},t=0.0,bp=0.0;
int main()
{
      dp[0]=1;
      for(int i=1; i<=30; i++)
            dp[i]=dp[i-1]*2;
      while(scanf("%d%lf",&n,&t)!=EOF&&(n>0))
      {
            ex[n]=dp[n];
            for(int i=n-1; i>=0; i--)
            {
                  bp=dp[i]/ex[i+1];
                  if(bp<=t)
                        ex[i]=(1+t)/2 * ex[i+1];
                  else
                        ex[i]=(bp-t)/(1-t) * dp[i] + (1-bp)/(1-t) * (1+bp)/2 * ex[i+1];
            }
            printf("%.3lf\n",ex[0]);
      }
      return(0);
}
