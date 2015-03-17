#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
#define MAXN 1000010
#define max(a, b) ((a) > (b) ? (a) : (b))
#define suc(x, k) (((x) > (k)) ? ((x) - (k)) : (x))

int c[MAXN], sum[MAXN << 1], que[MAXN << 1];
int ans = 0;
int main()
{
//    freopen("E.in", "r", stdin);

    int cas; scanf("%d", &cas);
    while(cas--)
    {
        int n; scanf("%d", &n);
        sum[0] = 0;

        for(int i = 1; i <= n; i++) scanf("%d", c + i);
        for(int i = 1; i <= 2 * n; i++) sum[i] = sum[i - 1] + c[suc(i, n)];

        int h = 0, t = -1;
        que[0] = ans = 0;
        for(int i = 1; i <= 2 * n; i++)
        {
            while(t >= h && sum[i] < sum[que[t]]) ans = max(ans, sum[que[t]] - sum[que[h]]), t--;
            while(t >= h && i - que[h] > n) ans = max(ans, sum[que[t]] - sum[que[h]]), h++;
            que[++t] = i;
        }
        ans = max(ans, sum[que[t]] - sum[que[h]]);
        printf("%d\n", ans);
    }
    return 0;
}
