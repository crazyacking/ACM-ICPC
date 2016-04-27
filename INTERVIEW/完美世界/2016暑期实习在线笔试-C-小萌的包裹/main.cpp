#include <bits/stdc++.h>

using namespace std;

const int MAXN=25;

int N,T,M;
int v[MAXN];
int dp[MAXN][MAXN][MAXN];
void solve()
{
	memset(dp,0,sizeof(dp));
	for(int i=1;i<M;++i) // 前i个背包
	{
		for(int j=1;j<N;++j) // 前j件物品
		{
			for(int k=1;k<T;++k) // 容量为k
			{
				if(k-v[j]>=0) // 放入
				{
					dp[i][j][k]=max(dp[i][j-1][k],dp[i][j-1][k-v[j]]+1); // 放入当前背包
					
				}
				else // 丢弃
					dp[i][j][k]=max(dp[i][j-1][k],0);
			}
		}
		//
	}
}

int main(int argc, char const *argv[])
{
	int Cas;
	cin>>Cas;
	while(Cas--)
	{
		cin>>N>>T>>M;
		for (int i = 0; i < M; ++i)
			cin>>v[i];
		solve();
	}
	return 0;
}