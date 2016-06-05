#include <bits/stdc++.h>
using namespace std;
const int N=1000005, mo=1000000007;
int n, p[N], pos[N], num[N], tot;
char s[N];
bool vis[N];
void dfs(int x) { if(p[x]) dfs(p[x]); vis[x]=1; pos[++tot]=x; }
void work(int x) {
    tot=0;
    dfs(x);
    for(int i=1, j=0; i<=tot; ++i) {
        while(pos[j+1]*2<=pos[i]) ++j;
        num[pos[i]]=j;
    }
}
void clr() { memset(p, 0, sizeof(int)*(n+1)); memset(vis, 0, sizeof(bool)*(n+1)); memset(num, 0, sizeof(int)*(n+1)); }
int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%s", s+1);
        n=strlen(s+1);
        int j=0;
        for(int i=2; i<=n; ++i) {
            while(j && s[j+1]!=s[i]) j=p[j];
            if(s[j+1]==s[i]) ++j;
            p[i]=j;
        }
        for(int i=n; i>=1; --i) if(!vis[i]) work(i);
        long long ans=1;
        for(int i=1; i<=n; ++i) (ans*=(num[i]+1))%=mo;
        printf("%lld\n", ans);
        clr();
    }
    return 0;
}
