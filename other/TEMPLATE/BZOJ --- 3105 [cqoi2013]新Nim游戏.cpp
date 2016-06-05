#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
int s[105], a[105], n;
bool cmp(const int &a, const int &b) { return a>b; }
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", &a[i]);
    sort(a, a+n, cmp);
    for(int i=0; i<n; ++i) {
        int t=a[i];
        for(int j=31; j>=0; --j) if((t>>j)&1) {
            if(!s[j]) { s[j]=t; break; }
            t^=s[j];
        }
        if(!t) ans+=a[i];
    }
    printf("%lld\n", ans);
    return 0;
}