/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-15-23.25
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

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      double n;
      while(scanf("%lf",&n) , n>0)
      {
            int ans=0;
            double len=0.0;
            for(int i=2;len<n;++i)
            {
                  len+=(1.0/i);
                  ans++;
            }
            printf("%d card(s)\n",ans);
      }
      return 0;
}
/*

*/
