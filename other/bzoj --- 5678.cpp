//  Memory   Time
//  1347K     0MS
//   by : crazyacking
//   2015-03-30-14.33
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

int n,k;
int a[MAXN];
int dp[MAXN];
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0);
//      freopen("C:\\Users\\Devin\\Desktop\\cin.cpp","r",stdin);
//      freopen("C:\\Users\\Devin\\Desktop\\cout.cpp","w",stdout);
        while(~scanf("%d %d",&n,&k))
        {
                for(int i=1;i<=n;++i)
                {
                        scanf("%d",&a[i]);
                }
                memset(dp,0,sizeof dp);
                int Max=INT_MIN,Min=INT_MAX;
                int Max_idx=0,Min_idx=0;
                for(int i=1;i<=n;++i)
                {
                        int tmp=abs(Max_idx-Min_idx);
                        if(a[i]>Max && abs(i-Min_idx)>tmp)
                        {
                                Max=a[i];
                                Max_idx=i;
                        }
                        if(a[i]<Min && abs(i-Max_idx)>tmp)
                        {
                                Min=a[i];
                                Min_idx=i;
                        }
                        if(tmp<=k)
                        {
                                dp[i]=tmp+1;
                        }
                        else
                        {
                                while(tmp>k)
                                {
                                        int sta_idx=min(Max_idx,Min_idx);
                                        int en_idx=max(Max_idx,Min_idx);
                                        for(int i=sta_idx+1;i<=en_idx;++i)
                                        {
                                                if(a[i]>Max)
                                                {
                                                        Max=a[i];
                                                        Max_idx=i;
                                                }
                                                if(a[i]<Min && abs(i-Max_idx)>tmp)
                                                {
                                                        Min=a[i];
                                                        Min_idx=i;
                                                }
                                        }
                                }
                                dp[i]=abs(Max_idx-Min_idx)+1;
                        }
                }
                int ans=1;
                puts("- - - - - - - - - - - Program Run Here ! - - - - - - - - - - - - ");

                for(int i=1;i<=n;++i)
                {
                        printf("%d ",dp[i]);
                        if(dp[i]>ans)
                                ans=dp[i];
                }
                puts("");
                puts("- - - - - - - - - - - Program Run Here ! - - - - - - - - - - - - ");

                cout<<ans<<endl;
        }
        return 0;
}
/*

*/
