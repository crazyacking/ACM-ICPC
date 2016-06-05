//  Memory   Time
//  1347K     0MS
//   by : crazyacking
//   2015-03-29-22.02
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
#define MAXN 10005
#define LL long long
using namespace std;
int Cas,n,dp[MAXN];
int main(){
    cin>>Cas;
    while(Cas--)
    {
        int cnt = 0 ,sum=0;
        scanf("%d",&n);
        int ta, tb;
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        int csum = 0 ;
        for(int i = 1;i <= n; i ++)
        {
           scanf("%d %d",&ta,&tb);

          if(ta == 2 )
              sum += tb;
          else{
             csum += tb ;
             for(int i = csum;i >= 0 ;i -- )
             {
               if(dp[i] != 0 )
               {
                  dp[i+tb] = 1;
               }
             }
          }
        }
        for(int i = csum /2 ;i >= 0 ;i--)
        {
          if(dp[i] != 0 )
          {
             sum += max(i,csum-i);
             break;
          }
        }
        printf("%d\n",sum);

    }
return 0;
}
