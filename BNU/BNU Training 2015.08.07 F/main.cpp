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
int dp[MAXN][MAXN];
char pa[MAXN][MAXN];

void solve()
{
      int cnt=0;
      memset(dp,0,sizeof dp);
      memset(pa,0,sizeof pa);
      int l1=strlen(s1),l2=strlen(s2);
      for(int i=0;i<l1;++i) dp[i][0]=0;
      for(int j=0;j<l2;++j) dp[0][j]=0;
      int enx=0,eny=0;
      for(int i=1;i<l1;++i)
      {
            for(int j=1;j<l2;++j)
            {
                  if(s1[i]==s2[j])
                  {
                        dp[i][j]=dp[i-1][j-1]+1;
                        pa[i][j]='*';
                  }
                  else
                  {

                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                        if(dp[i-1][j]>=dp[i][j-1]) pa[i][j]='s';
                        else pa[i][j]='z';
                  }
            }
      }
      enx=l1-1,eny=l2-1;
      while(pa[enx][eny]!='\0')
      {
            if(pa[enx][eny]=='*')
            {
                  enx--;eny--;
                  ans[cnt++]=s1[enx+1];
            }
            else if(pa[enx][eny]=='s') enx--;
            else if(pa[enx][eny]=='z') eny--;
      }
      ans[cnt]='\0';
      strrev(ans);
      puts(ans);
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      s1[0]='$';s2[0]='$';
      while(~scanf("%s%s",s1+1,s2+1))
      {
            solve();
      }
      return 0;
}
/*

*/
