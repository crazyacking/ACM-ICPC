/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-14-22.52
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
const int MAXN=10+(int)1e5;
int n,j,gap;
char s[MAXN];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(scanf("%d",&n),n!=-1)
      {
            scanf("%s",s+1);
            int ans=0;
            for(j=2;j<n;++j)
            {
                  if(s[j]=='1')
                  {
                        for(gap=1;gap+j<=n&&j-gap>=1;++gap)
                        {
                              if(s[j-gap]=='1'&&s[gap+j]=='1') ans++;
                        }
                  }
            }
            printf("%d\n",ans);
      }
      return 0;
}
/*

*/
