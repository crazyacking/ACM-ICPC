/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-29-09.57
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

const int MAXN=510;
const int MAXM=10010;
int dp[MAXN][MAXM];
int n;
int value[MAXN],weight[i];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      cin>>t;
      while(t--)
      {
            int nValue,nValue1,nValue2;
            cin>>nValue1>>nValue2;
            nValue=nValue2-nValue1;
            cin>>n;
            for(int i=1;i<=n;++i)
            {
                  cin>>value[i]>>weight[i];
            }
            memset(dp[0],INT_MAX,sizeof dp[0]);
            dp[0][0]=0;
            for(int i=1;i<=n;++i)
            {

            }

      }
      return 0;
}
/*

*/
