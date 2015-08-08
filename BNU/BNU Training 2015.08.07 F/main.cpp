/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-07-22.47
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

const int MAXN=1010;
char s1[MAXN],s2[MAXN],ans[MAXN];
int dp[MAXN][MAXN],path[MAXN][MAXN];

void solve()
{
      memset(dp,0,sizeof dp);
      memset(path,0,sizeof path);
      int cnt=0;
      int l1=strlen(s1),l2=strlen(s2);
      for(int i=0;i<l1;++i) dp[i][0]=0;
      for(int j=0;j<l2;++j) dp[0][j]=0;
      int enx=0,eny=0;
      for(int i=0;i<l1;++i)
      {
            for(int j=0;j<l2;++j)
            {
                  if(s1[i]==s2[j])
                  {
                        dp[i][j]=dp[i-1][j-1]+1;
                        path[i][j]=1;
                        enx=max(enx,i);
                        eny=max(eny,j);
                  }
                  else
                  {

                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                        if(dp[i-1][j]>=dp[i][j-1]) path[i][j]=2;
                        else path[i][j]=3;
                  }
            }
      }
      ans[cnt++]=s1[enx];
      cout<<enx<<" "<<eny<<endl;
      while(enx>=0 && eny>=0)
      {
            if(path[enx][eny]==1)
            {
                  enx--;
                  eny--;
                  ans[cnt++]=s1[enx];
            }
            else if(path[enx][eny] ==2)
            {
                  enx--;
            }
            else if(path[enx][eny]==3) eny--;
      }
      /**< 有问题,输出path看看 */
      puts("- - - - - - - - - - - Program Run Here ! - - - - - - - - - - - - ");

      for(int i=0;i<l1;++i)
      {
            for(int j=0;j<l2;++j)
            {
                  printf("%d",path[i][j]);
            }
            puts("");
      }
      puts("- - - - - - - - - - - Program Run Here ! - - - - - - - - - - - - ");

      ans[cnt]='\0';
      strrev(ans);
      puts(ans);
      printf("%d\n",dp[l1-1][l2-1]);
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%s%s",s1,s2))
      {
            solve();
      }
      return 0;
}
/*

*/
