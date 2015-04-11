#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <numeric>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define forit(it,S) for(__typeof(S.begin()) it = S.begin(); it != S.end(); ++it)
#ifdef WIN32
#define I64d "%I64d"
#else
#define I64d "%lld"
#endif

typedef pair <int, int> pi;
typedef vector <int> vi;
typedef long long ll;

int a[1111], n, k;
int b[1111], c[1111], bn, cn;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int mx = a[0];
    for (int l = 0; l < n; ++l) {
        bn = 0;
        int cur = 0;
        for (int r = l; r < n; ++r) {
            cur += a[r];
            b[bn++] = a[r];
            sort(b, b + bn);
            int cn = 0;
            for (int i = 0; i < l; ++i) {
                c[cn++] = a[i];
            }
            for (int i = r + 1; i < n; ++i) {
                c[cn++] = a[i];
            }
            sort(c, c + cn, greater <int>());
            
            int now = cur;
            for (int i = 0; i < k && i < bn && i < cn; ++i) {
                if (b[i] >= c[i]) {
                    break;
                }
                now -= b[i];
                now += c[i];
            }
            
            mx = max(mx, now);
        }
    }
    
    cout << mx << endl;
    return 0;
} Codeforces Round #243 (Div. 1), problem: (A) Sereja and Swaps
