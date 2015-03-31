//  Memory   Time
//  1347K     0MS
//   by : crazyacking
//   2015-03-31-16.17
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<iostream>
#include<algorithm>
#define MAXN 5005
#define LL long long
using namespace std;
char str[MAXN];
int dp[MAXN][MAXN];

bool judge(int sta,int en)
{
        for(int i=sta,j=en;i<j;++i,--j)
        {
                if(str[i]!=str[j])
                        return false;
        }
        return true;
}
int main()
{
        gets(str);
        int len=strlen(str);
        memset(dp,0,sizeof dp);
        for(int i=0;i<len;++i)
        {
                if(str[i]==str[i+1])
                        dp[i][i+1]=1;
                dp[i][i]=1;
        }
        for(int i=len-1;i>=0;--i)
        {
                for(int j=i;j<len;++j)
                {
                        if(dp[i+1][j-1]==1&&str[i]==str[j])
                                dp[i][j]=1;
                }
        }
        for(int i=len-1;i>=0;--i)
        {
                for(int j=i;j<len;++j)
                {
                        dp[i][j]=dp[i][j]+dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
                }
        }
        int q;
        scanf("%d",&q);
        while(q--)
        {
                int x,y;
                scanf("%d %d",&x,&y);
                printf("%d\n",dp[x-1][y-1]);
        }
        return 0;
}
