#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
const int inf = 100000;
int g[50][50],n;
int main() {
    int x, t, a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0;i < n;++i) {
            for (int j = 0;j < n;++j) {
                scanf("%d", &x);
                g[i][j] = x == 0 ? inf : 1;
            }
        }
        for (int i = 0;i < n;++i) {
            for (int j = 0;j < n;++j) {
                for (int k = 0;k < n;++k)
                    g[j][k] = std::min(g[j][k], g[j][i] + g[i][k]);
            }
        }
        scanf("%d", &x);
        while (x--) {
            scanf("%d%d", &a, &b);
            --a, --b;
            if (g[a][b] == inf)
                puts("Sorry");
            else printf("%d\n", g[a][b]-1);
        }
    }
    return 0;
}