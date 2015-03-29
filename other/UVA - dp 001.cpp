//  Memory   Time
//  1347K     0MS
//   by : crazyacking
//   2015-03-25-21.38
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
#define MAXN 1000010
#define LL long long
#include<iostream>
#include<cstdio>
#include<cstring>
//  Memory   Time
//  1347K     0MS
//   by : crazyacking
//   2015-03-26-20.00
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
#define MAXN 1000010
#define LL long long
using namespace std;
char str[1010];
int flag[1010][1010];
int dp[1010];
int l;
const int INF=0x3f3f3f3f;
void pre()
{
	/*令flag[i][j]=1表示长度为i从str的第j个位置开始有一回文串，
	否则flag[i][j]=0*/
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=l;i++)flag[1][i]=1;
	if(l==1)return;
	for(int i=1;i<=l-1;i++)if(str[i]==str[i+1])flag[2][i]=1;
	for(int i=3;i<=l;i++)
	for(int j=1;j<=l-i+1;j++)
	{
		/*j开始i的长度是回文词是加上从j+1开始i-2的长度
			 是回文词切加上两边构成新的回文词 */
		if(flag[i-2][j+1] && str[j]==str[j+i-1])
		flag[i][j]=1;
	}
	printf(" ");
	for(int i=1;i<=l;++i)
        {
                printf(" %d",i);
        }
        puts("");
        int idx=1;
        for(int i=1;i<=l;++i)
        {
                printf("%d ",idx++);
                for(int j=1;j<=l;++j)
                {
                        printf("%d ",flag[i][j]?1:0);
                }
                puts("");
        }
}
void solve()
{
	for(int i=1;i<=l;i++)dp[i]=INF;
	dp[0]=0;
	for(int i=1;i<=l;i++)
	for(int j=1;j<=i;j++)
	{
		//以i开头，长度为j的状态下扫
		//f[i]表示到第i为时，最少的回文词个数，
		//所以只要在i时候前面扫j个单位
		if(flag[j][i-j+1])
		{
			//f[i]=min{f[i-j]+1}(if flag[j][i-j+1]=1}
			dp[i]=min(dp[i],dp[i-j]+1);
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
        {
                scanf("%s",str+1);
                l=strlen(str+1);
                pre();
                solve();
                printf("%d\n",dp[l]);
	}
	return 0;
}
