#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define N 100005
typedef long long ll;
vector<int> x[N];
bool is[N];

void prime() {
    memset(is, false, sizeof(is));
    for (int i=0; i<N; i++) x[i].clear();

    for (int j=2; j<N; j+=2) x[j].push_back(2);
    for (int i=3; i<N; i+=2)
        if (!is[i]) {
            for (int j=i; j<N; j+=i) {
                is[j] = true;
                x[j].push_back(i);
            }
        }
}
int work(int u, int s, int w) {
    int cnt = 0, v = 1;
    for (int i=0; i<x[w].size(); i++) {
        if ((1<<i) & s) {
            cnt++;
            v *= x[w][i];
        }
    }
    int all = u/v;
    if (cnt % 2 == 0) return -all;
    else return all;
}

int main() {

    prime();

    int T, a, b, c, d, k;
    scanf("%d", &T);
    for (int cas=1; cas<=T; cas++) {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        if (k == 0) {
            printf("Case %d: 0\n", cas);
            continue;
        }
        b /= k, d /= k;

        if (b > d) { a = b; b = d; d = a; }
        long long ans = 0;
        for (int i=1; i<=d; i++) {
            k = min(i, b);
            ans += k;
            for (int j=1; j<(1<<x[i].size()); j++)
                ans -= work(k, j, i);
        }
        printf("Case %d: %I64d\n", cas, ans);
    }
    return 0;
}
