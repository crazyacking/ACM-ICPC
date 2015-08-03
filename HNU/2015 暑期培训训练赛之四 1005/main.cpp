/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-02-20.36
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


double n,p,s,v;
double solve(double c)
{
      return s*(1+1./c)/v+n*( pow( log(n)/log(2.), c*sqrt(2.)) )/(p*1e9);
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%lf %lf %lf %lf",&n,&p,&s,&v))
      {
            double l=0,r=50;
            double mid,mmid;
            int step=200;
            while(step--)
            {
                  mid=(l+r)/2;
                  mmid=(mid+r)/2;
                  if(solve(mid)>solve(mmid)) l=mid;
                  else r=mmid;
            }
            printf("%.10f %.10f\n",solve(l),l);
      }
      return 0;
}
/*

*/
