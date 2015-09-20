/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-20-13.22
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
const double eps(1e-10);

int t,ans;
const int MOD = 7+(int)1e9;
const int N = 2000005;
double x;
double a[N];
int main()
{
      cin>>t;
      double l = 0, r = 0.5,mid=0;
      int cnt=0;
      for(int i = 1; i <= 1000; i += 2)
      {
            a[cnt++]=mid;
            l = mid;
            mid = (l + r) / 2;
      }
      while(t--)
      {
            cin>>x;
            ans = 0;
            for(int i=0;i<cnt;++i)
            {
                  if(a[i] < x)
                  {
                        ans =ans+ 4;
                  }
                  if(fabs(a[i] - x) < eps)
                  {
                        ans = -1;
                        break;
                  }
                  if(a[i] > x) break;
            }
            cout<<ans<<endl;
      }
}
