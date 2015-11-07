
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

const int MAXN = 20010;
int a[MAXN], b[MAXN];
int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (~scanf("%d %d", &n, &m), !(n == 0 && m == 0))
	{
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < m; ++i)
			scanf("%d", &b[i]);
		sort(a, a + n);
		sort(b, b + m);
		int ans = 0;
		int pos = 0;
		bool flag = 0;
		int cnt = 0;
		for (int j, i = 0; i < n; ++i)
		{
			if (pos >= m) break;
			for (j = pos; j < m; ++j)
			{
				if (b[j] >= a[i])
				{
					ans += b[j];
					pos = j + 1;
					++cnt;
					break;
				}
			}
			if (j >= m) break;
		}
		if (cnt < n)
		{
			printf("Loowater is doomed!\n");
		}
		else
			printf("%d\n", ans);
	}
	return 0;
}
/*

*/