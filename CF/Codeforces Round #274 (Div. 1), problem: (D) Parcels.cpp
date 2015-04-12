#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>

#define MX 505
#define MS 1005
#define rep(i, n) for (int i = 0; i < n; i ++)

using namespace std;

int in[MX], out[MX], w[MX], s[MX], v[MX];
int N, S;
int con[MX][MX], size[MX];
int val[MX][MS], chk[MX][MS];
int pos[MX][MS];
int a[MS];

inline bool ok(int u, int v) {
    return in[u] <= in[v] && out[v] <= out[u];  
}

bool cmp(const int &a, const int &b) {
    return out[a] < out[b];
}

void init() {
    int j, cnt;
    rep(i, N) {
        for (j = 0; j < N; j ++) if (i != j && ok(i, j)) con[i][size[i] ++] = j;
        sort(con[i], con[i] + size[i], cmp);
        cnt = 0;
        pos[i][0] = 0;
        for (j = 1; j < MS; j ++) {
            while (cnt < size[i] - 1 && out[con[i][cnt]] < j) cnt ++;
            pos[i][j] = pos[i][j - 1];
            if (out[con[i][cnt]] == j) pos[i][j] = j;
        }
    }
}

int find(int id, int S) {
    if (chk[id][S]) return val[id][S];
    chk[id][S] = 1;
    if (!size[id]) return val[id][S] = 0;
    int i, k, u, t, r;
    for (i = 0; i < size[id]; i ++) {
        u = con[id][i];
        if (w[u] > S) continue;
        find(u, min(S - w[u], s[u]));
    }
    
    a[0] = 0;
    for (i = 0; i < size[id]; i ++) a[out[con[id][i]]] = 0;
    for (i = 0; i < size[id]; i ++) {
        u = con[id][i];
        if (w[u] > S) t = 0;
        else t = find(u, min(S - w[u], s[u])) + v[u];   
        k = pos[id][in[u]];
        t += a[k]; r = out[u];
        if (a[r] < t) a[r] = t;
        t = a[pos[id][out[u] - 1]];
        if (a[r] < t) a[r] = t; 
    }
    return val[id][S] = a[out[u]];
}

int main() {
    
    cin >> N >> S;
    rep(i, N) scanf("%d%d%d%d%d", in + i, out + i, w + i, s + i, v + i);
    in[N] = 0, out[N] = 2 * N, w[N] = 0, s[N] = S, v[N] = 0;
    N ++;
    init();
    printf("%d\n", find(N - 1, S));
    
    return 0;
}
