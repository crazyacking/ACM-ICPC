/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-07-12.11
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

      while(~scanf("%d %d",&n,&m))
      {
            int ans=0;
            int a[15];
            for(int i=n;i<=m;++i)
            {
                  memset(a,0,sizeof a);
                  int j=i;
                  while(j)
                  {
                        if(a[j%10]) break;
                        a[j%10]=1;
                        j=j/10;
                  }
                  if(!j) ans++;
            }
            printf("%d\n",ans);
      }
      return 0;
}
/*

*/
