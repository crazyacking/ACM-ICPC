#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>

#define X first
#define Y second
#define mp make_pair
#define sqr(x) ((x) * (x))
#define Rep(i, n) for(int i = 0; i<(n); i++)
#define foreach(it, n) for(__typeof(n.begin()) it = n.begin(); it != n.end(); it++)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

#define esp 1e-8
#define N 100010

int n, L, x, y;
int a[N];
vector<int> ans;

bool test(int x) {
    int l = 0, r = 0;
    while (r < n) {
        while (r < n && a[r] - a[l] < x) r++;
        while (r < n && a[r] - a[l] > x) l++;
        if (a[r] - a[l] == x) return true;
    }
    return false;
}
int test(int x, int y) {
    int l = 0, r = 0;
    while (r < n) {
        while (r < n && a[r] - a[l] < x) r++;
        while (r < n && a[r] - a[l] > x) l++;
        if (a[r] - a[l] == x) {
            if (a[l] - y >= 0) return a[l] - y;
            if (a[r] + y <= L) return a[r] + y;
            l++, r++;
        }
    }
    l = 0, r = 0;
    x = x + 2 * y;
    while (r < n) {
        while (r < n && a[r] - a[l] < x) r++;
        while (r < n && a[r] - a[l] > x) l++;
        if (a[r] - a[l] == x) return a[l] + y;
    }
    return -1;
}

int main() {
    scanf("%d%d%d%d", &n, &L, &x, &y);
    Rep(i, n) scanf("%d", &a[i]);
    if (!test(x) && !test(y)) {
        int val = test(abs(x-y), min(x, y));
        if (val == -1) {
            ans.push_back(x); 
            ans.push_back(y);
        }
        else ans.push_back(val);
    }
    else if (!test(x)) ans.push_back(x);
    else if (!test(y)) ans.push_back(y);

    printf("%d\n", ans.size());
    Rep(i, ans.size()) 
        printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');

    return 0;
}
