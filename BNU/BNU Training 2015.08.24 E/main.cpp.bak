/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-24-14.14
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
const int MAXN=2010;

char M[MAXN][MAXN];
int main()
{
      int t;
      scanf("%d",&t);
      while(t--)
      {
            int n;
            scanf("%d",&n);
            getchar();
            for(int i=0;i<n;++i)
                  gets(M[i]);
            bool ans=true;
            for(int i=0;i<n;++i)
            {
                  for(int j=0;j<n;++j)
                  {
                        if(M[i][j]=='1') // i love j
                        {
                              for(int k=0;k<n;++k)
                              {
                                    if(M[j][k]=='1')  // j love k
                                    {
                                          if(M[k][i]!='1') // but k don't love i
                                          {
                                                ans=false;break;
                                          }
                                          else
                                          {
                                                M[k][i]='0';
                                                continue;
                                          }
                                    }
                                    if(!ans) break;
                              }
                        }
                        if(!ans)break;
                  }
                  if(!ans) break;
            }
            if(ans) puts("Yes");
            else puts("NO");
      }
      return 0;
}
/*

*/
