#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int t, n, m, dp[2][13][13], num, ok[13], cnt[13];
char map[105][10];

/*
    状态是每个物体的第三行...
    由于第二行的特殊性,加上不能重叠,可以知道第三行状态很少一共有:
    00000000 , 01001000
    01000000 , 01000100
    00100000 , 01000010
    00010000 , 00100100
    00001000 , 00100010
    00000100 , 00010010
    00000010
    13种.
*/
inline void init() { //求出合法状态
    ok[0] = cnt[0] = 0;
    num = 1;
    for (int i = 1; i + 1 < m; i++) {
        ok[num] = (1 << i), cnt[num] = 1, num++; 
        for (int j = i + 3; j + 1 < m; j++) {
                    ok[num] = (1 << i) + (1 << j), cnt[num] = 2, num++; 
        }
    }
}

inline bool suit(int st, int i) { //第i行状态为st,可以吗?需要考虑三行
    for (int j = 0; j < m; j++) {
        if (st & (1 << j)) {
            if (map[i][j] == '#' || map[i - 1][j] == '#' || map[i - 1][j - 1] == '#' || map[i - 1][j + 1] == '#' || map[i - 2][j] == '#')
                return 0;
        }
    }
    return 1;
}

inline bool Can1(int st1, int st2) { //对于物体,第三行的状态和第二行的状态合法不
    int a[3][8];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < 8; i++) {
        if (st1 & (1 << i)) {
            a[0][i]++, a[1][i]++, a[1][i - 1]++, a[1][i + 1]++, a[2][i]++;
        }
        if (st2 & (1 << i)) {
            a[1][i]++, a[2][i]++, a[2][i - 1]++, a[2][i + 1]++;
        }
    }
    for (int i = 0; i < 8; i++) {
        if (a[0][i] > 1 || a[1][i] > 1 || a[2][i] > 1) return 0;
    }
    return 1;
}

inline bool Can2(int st1, int st2) { //对于物体,第三行的状态和第一行的状态合法不
    for (int i = 0; i < m; i++) {
        if (st1 & (1 << i)) {
            if (st2 & (1 << i)) {
                return 0;
            }
        }
    }
    return 1;
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%s", map[i]);
        if (n <= 2 || m <= 2 ) puts("0");
        else {
            init();
            int now = 0;
            memset(dp[now], 0, sizeof(dp[now]));
            for (int i = 2; i < n; i++) {
                now ^= 1;
                memset(dp[now], 0, sizeof(dp[now]));
                for (int j = 0; j < num; j++) {
                    int st1 = ok[j];
                    for (int k = 0; k < num; k++) {
                        int st2 = ok[k];
                        for (int r = 0; r < num; r++) {
                            int st3 = ok[r];
                            if (!suit(st3, i)) continue;
                            if (!Can1(st3, st1)) continue;
                            if (!Can2(st3, st2)) continue;
                            dp[now][r][j] = max(dp[now][r][j], dp[1 - now][j][k] + cnt[r]);
                        }
                    }
                }
            }
            int ans = 0;
            for (int i = 0; i < num; i++)
                for (int j = 0; j < num; j++)
                    ans = max(ans, dp[now][i][j]);
            printf("%d\n", ans);
        }
    }
    return 0;
}