
/*
* -----------------------------------------------------------------
* Copyright (c) 2015 crazyacking All rights reserved.
* -----------------------------------------------------------------
*       Author: crazyacking
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
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

const int MAXN = 1001;
char s[MAXN][MAXN];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int dis[3][MAXN][MAXN];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	while (~scanf("%d %d", &n, &m))
	{
		for (int i = 0; i < n; ++i)
			scanf("%s", s[i]);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				dis[0][i][j] = dis[1][i][j] = dis[2][i][j] = (int)1e8;
		queue<pair<int, int> > Q;
		for (int k = 0; k < 3; ++k)
		{
			while (!Q.empty())
				Q.pop();
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					if (s[i][j] == k + '1')
					{
						Q.push(make_pair(i, j));
						dis[k][i][j] = 0;
					}
				}
			}

			while (!Q.empty())
			{
				pair<int, int> now = Q.front();
				Q.pop();
				int x = now.first;
				int y = now.second;
				for (int i = 0; i < 4; ++i)
				{
					int xx = x + dx[i];
					int yy = y + dy[i];
					if (!(xx >= 0 && xx < n))continue;
					if (!(yy >= 0 && yy<m))continue;
					if (s[xx][yy] == '#')continue;
					if (dis[k][xx][yy]>dis[k][x][y] + (s[x][y] == '.'))
					{
						dis[k][xx][yy] = dis[k][x][y] + (s[x][y] == '.');
						Q.push(make_pair(xx, yy));
					}
				}
			}
		}
		int ans = 1e9;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				ans = min(ans, dis[0][i][j] + dis[1][i][j] + dis[2][i][j]+(s[i][j]=='.'));
		}
		if (ans >= 1e8)
			puts("-1");
		else
			printf("%d\n", ans);
	}
	return 0;
}
/*

*/